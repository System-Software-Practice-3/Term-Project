#include "kmeans.h"
#include "image2vec.h"
#include <algorithm>
#include <iostream>

#define MAX_DISTANCE 0x7ffffffff
#define INVAILD -1

void change_form(cv::Mat input_matrix,std::vector <cv::Point3f>& pixels){
    int row_count = input_matrix.rows;
    int col_count = input_matrix.cols;

    for (int i = 0; i < row_count; i++){
        for (int j = 0; j < col_count; j++){
            int off=i*col_count*3+j*3;
            pixels.push_back(cv::Point3f(input_matrix.data[off+0],input_matrix.data[off+1],input_matrix.data[off+2]));
        }
    }
}

double distance_func(cv::Point3f cur_pixel, cv::Point3f cur_center){
    double ret = 0;
    ret += std::pow(cur_pixel.x-cur_center.x,2);
    ret += std::pow(cur_pixel.y-cur_center.y,2);
    ret += std::pow(cur_pixel.z-cur_center.z,2);

    return std::sqrt(ret);
}

void allocate_cluster(std::vector <cv::Point3f> pixels,std::vector<cv::Point3f> centers,std::vector<std::vector<int>>& cluster){
    //std::cout << "allocate" << std::endl;
    int len = pixels.size();

    for (int i = 0; i < len; i++){
        double min_distance = MAX_DISTANCE;
        int min_center = INVAILD;
        for (int j = 0; j < centers.size(); j++){
            double distance = distance_func(pixels[i],centers[j]);
            if(distance < min_distance){
                min_distance = distance;
                min_center = j;
            }
        }
        cluster[min_center].push_back(i);
    }
}
void solving_tmp_centers(std::vector<std::vector<int>> cluster,std::vector <cv::Point3f> pixels,std::vector<cv::Point3f>& tmp_centers ){
     //std::cout << "solving tmp" << std::endl;
    for (int i = 0; i < cluster.size(); i++){
        int red=0,green=0,blue=0;
       //  std::cout << "i is " << cluster.size() << std::endl;
        for (int j = 0; j < cluster[i].size(); j++){
            //std::cout << "j is " << j << " " << cluster[i].size() << std::endl;
            red += pixels[cluster[i][j]].z;
            green += pixels[cluster[i][j]].y;
            blue += pixels[cluster[i][j]].x;
        }
        //std::cout << "segment" << std::endl;
        if(red == 0){
            red = 0;
        }
        else{
            red/=cluster[i].size();
        }

        if(green == 0){
            green = 0;
        }
        else{
            green/=cluster[i].size();
        }
        
        if(blue == 0){
            blue = 0;
        }
        else{
            blue/=cluster[i].size();
        }
       // std::cout << tmp_centers[i].x << ' ' << tmp_centers[i].y << ' ' << tmp_centers[i].z << std::endl;
       // std::cout << blue << ' ' << green << ' ' << red << std::endl << std:: endl;
        tmp_centers[i].x = blue;
        tmp_centers[i].y = green;
        tmp_centers[i].z = red;
    }
}
bool checking_condition(std::vector<std::vector<int>> cluster,std::vector<cv::Point3f>& centers,std::vector<cv::Point3f> tmp_centers,int withinDistance,bool& first){
     //std::cout << "condition" << std::endl;
    double changed_magnitude = 0;
    for (int i = 0; i < cluster.size(); i++){
        //std::cout << tmp_centers[i].x << ' ' << tmp_centers[i].y << ' ' << tmp_centers[i].z << std::endl;
       // std::cout << centers[i].x << ' ' << centers[i].y << ' ' << centers[i].z << std::endl << std::endl;
        changed_magnitude += distance_func(tmp_centers[i],centers[i]);
    }

    bool same = false;
    for (int i = 0; i < cluster.size()-1; i++){
        for (int j = i+1; j < cluster.size();j++){
            if(distance_func(tmp_centers[i],tmp_centers[j]) <= 5){
                i = cluster.size();
                same = true;
                break;
            }
        }
    }

    if(first == true){
        first = false; return false;
    }
    //std::cout << changed_magnitude << ' ' << same << std::endl;
    if((changed_magnitude <= withinDistance) && (same == false)) return true;

    for (int i = 0; i < centers.size(); i++){
       // std::cout << tmp_centers[i].x << ' ' << tmp_centers[i].y << ' ' << tmp_centers[i].z << std::endl;
       // std::cout << centers[i].x << ' ' << centers[i].y << ' ' << centers[i].z << std::endl << std::endl;
        centers[i].x = tmp_centers[i].x;
        centers[i].y = tmp_centers[i].y;
        centers[i].z = tmp_centers[i].z;
       // std::cout << tmp_centers[i].x << ' ' << tmp_centers[i].y << ' ' << tmp_centers[i].z << std::endl;
       // std::cout << centers[i].x << ' ' << centers[i].y << ' ' << centers[i].z << std::endl << std::endl;
      //  std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
    }
//std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
    return false;
}
cv::Mat kmeans_clustering(cv::Mat input_matrix, int Numofcluster, int withinDistance){
    cv::Mat ret = cv::Mat::zeros(input_matrix.size(),CV_8UC3);
    //change pixel rgb form;
    std::vector <cv::Point3f> pixels;
    change_form(input_matrix, pixels);
    //randomly choose centers
    srand((unsigned int)time(NULL));


    std::vector<cv::Point3f> centers;
    for (int i = 0; i < Numofcluster; i++){
        int Rand[3];
        for (int k = 0; k < 3; k++){
            Rand[k] = rand()%255;
        }
        centers.push_back(cv::Point3f(Rand[0],Rand[1],Rand[2]));
    }


    bool first = true;
    std::vector<std::vector<int>> Cluster(centers.size());
    while(1){
        //allocate pixels to each cluster..
        std::vector<std::vector<int>> cluster(centers.size());
        allocate_cluster(pixels,centers,cluster);


        //find tmp center of cluster
        std::vector<cv::Point3f> tmp_centers(cluster.size());


        solving_tmp_centers(cluster,pixels,tmp_centers);


        // condition check
        if(checking_condition(cluster,centers,tmp_centers,withinDistance,first)) {
            Cluster = cluster;
            break;
        }
    }


    for (int i = 0; i < Cluster.size(); i++){
        for (int j = 0; j < Cluster[i].size();j++){
            ret.data[Cluster[i][j]*3+0] = centers[i].x;
            ret.data[Cluster[i][j]*3+1] = centers[i].y;
            ret.data[Cluster[i][j]*3+2] = centers[i].z;
        }
    }
    return ret;
}


struct color_ratio{
    int r=-1,g=-1,b=-1;
    int count = 0;
    double ratio;
};



double compare_two_img(cv::Mat mat1,cv::Mat mat2,int Numofcluster){
    int len1 = mat1.rows*mat1.cols;
    int len2 = mat2.rows*mat2.cols;
    struct color_ratio Mat1_ratio[Numofcluster];
    struct color_ratio Mat2_ratio[Numofcluster];
    double ret = 0;

    for (int i = 0; i < len1; i++){
        for (int j = 0; j < Numofcluster; j++){
            if(Mat1_ratio[j].r == -1){
                Mat1_ratio[j].r = mat1.at<cv::Vec3b>(i)[2];
                Mat1_ratio[j].g = mat1.at<cv::Vec3b>(i)[1];
                Mat1_ratio[j].b = mat1.at<cv::Vec3b>(i)[0];
                Mat1_ratio[j].count++;
                break;
            }
            else{
                if((Mat1_ratio[j].r ==  mat1.at<cv::Vec3b>(i)[2]) && (Mat1_ratio[j].g ==  mat1.at<cv::Vec3b>(i)[1]) && (Mat1_ratio[j].b ==  mat1.at<cv::Vec3b>(i)[0])){
                    Mat1_ratio[j].count++;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < len2; i++){
        for (int j = 0; j < Numofcluster; j++){
            if(Mat2_ratio[j].r == -1){
                Mat2_ratio[j].r = mat2.at<cv::Vec3b>(i)[2];
                Mat2_ratio[j].g = mat2.at<cv::Vec3b>(i)[1];
                Mat2_ratio[j].b = mat2.at<cv::Vec3b>(i)[0];
                Mat2_ratio[j].count++;
                break;
            }
            else{
                if((Mat2_ratio[j].r ==  mat2.at<cv::Vec3b>(i)[2]) && (Mat2_ratio[j].g ==  mat2.at<cv::Vec3b>(i)[1]) && (Mat2_ratio[j].b ==  mat2.at<cv::Vec3b>(i)[0])){
                    Mat2_ratio[j].count++;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < Numofcluster; i++){
        Mat1_ratio[i].ratio = (double)Mat1_ratio[i].count/len1;
        Mat2_ratio[i].ratio = (double)Mat2_ratio[i].count/len2;
    }

//choose one mat and compare.. loop length is numofcluster.
    for (int i = 0; i < Numofcluster; i++){
        int close_idx = -1;
        double close_val = 0x7fffffff;
        for (int j = 0; j < Numofcluster; j++){
            if(Mat2_ratio[j].ratio <= 0) continue;
            if(std::pow(Mat1_ratio[i].r-Mat2_ratio[j].r,2)+std::pow(Mat1_ratio[i].g-Mat2_ratio[j].g,2)+std::pow(Mat1_ratio[i].b-Mat2_ratio[j].b,2) < close_val){
                close_val = std::pow(Mat1_ratio[i].r-Mat2_ratio[j].r,2)+std::pow(Mat1_ratio[i].g-Mat2_ratio[j].g,2)+std::pow(Mat1_ratio[i].b-Mat2_ratio[j].b,2);
                close_idx = j;
               // break;
            }
        }

        if(Mat1_ratio[i].ratio > Mat2_ratio[close_idx].ratio){
        //    std::cout << Mat1_ratio[i].ratio << ' ' << Mat2_ratio[close_idx].ratio << std::endl;
            ret += std::sqrt(close_val) * Mat2_ratio[close_idx].ratio;


            Mat1_ratio[i].ratio -= Mat2_ratio[close_idx].ratio;
            Mat2_ratio[close_idx].ratio = 0;
            i--;
            if(Mat1_ratio[i].ratio < 0.0000001){
                Mat1_ratio[i].ratio=0;
                i++;
            }
        }
        else{
            ret += std::sqrt(close_val) * Mat1_ratio[i].ratio;

            Mat2_ratio[close_idx].ratio -= Mat1_ratio[i].ratio;
            Mat1_ratio[i].ratio = 0;
            if(Mat2_ratio[close_idx].ratio < 0.0000001){
                Mat2_ratio[close_idx].ratio=0;
                //i++;
            }
        }
      //  std::cout << i << ' ' << Numofcluster << std::endl;
    }
    return ret;
}

//cv::Mat kmeans_clustering(cv::Mat input_matrix, int Numofcluster, int withinDistance);
std::vector<img2RGB> kmeans_similarity(img2RGB input,std::vector<img2RGB> stored_picture,int number_of_cluster,int withinDistance, int choose_num){
    int len = stored_picture.size();
    std::vector <double> similar;

    for (int i = 0; i < len; i++){
        similar.push_back(compare_two_img(kmeans_clustering(input.get_img(),number_of_cluster,withinDistance),
        kmeans_clustering(stored_picture[i].get_img(),number_of_cluster,withinDistance),
        number_of_cluster));
    }

    //sorting asc (more similar close to zero)
    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len-1-i;j++){
            if(similar[j] > similar[j+1]){
                double num_tmp = similar[j];
                img2RGB RGB_tmp = stored_picture[j];

                similar[j] = similar[j+1];
                similar[j+1] = num_tmp;

                stored_picture[j] = stored_picture[j+1];
                stored_picture[j+1] = RGB_tmp;
            }
        }
    }
    std::vector<img2RGB> ret;
    if(choose_num > len) choose_num = len;
    for (int i = 0; i < choose_num; i++){
        ret.push_back(stored_picture[i]);
    }

    return ret;
}