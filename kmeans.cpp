#include "kmeans.h"
#include <algorithm>

#define MAX_DISTANCE 0x7ffffffff
#define INVAILD -1

void change_from(cv::Mat input_matrix,std::vector <cv::Point3f>& pixels){
    int row_count = input_matrix.rows;
    int col_count = input_matrix.cols;

    for (int i = 0; i < row_count; i++){
        for (int j = 0; j < col_count; j++){
            int off=i*col_count*3+j*3;
            pixels.push_back(cv::Point3f(input_matrix[off+0],input_matrix[off+1],input_matrix[off+2]));
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
    for (int i = 0; i < cluster.size(); i++){
        int red=0,green=0,blue=0;
        for (int j = 0; j < cluster[i].size(); j++){
            red = pixel[cluster[i][j]].z;
            green = pixel[cluster[i][j]].y;
            blue = pixel[cluster[i][j]].x;
        }

        red/=cluster[i].size();
        green/=cluster[i].size();
        blue/=cluster[i].size();

        tmp_centers[i].x = blue;
        tmp_centers[i].y = green;
        tmp_centers[i].z = red;
    }
}
bool checking_condition(std::vector<std::vector<int>> cluster,std::vector<cv::Point3f> centers,std::vector<cv::Point3f> tmp_centers,int withinDistance,bool& first){
    double changed_magnitude = 0;
    for (int i = 0; i < cluster.size(); i++){
        changed_magnitude += distance_func(tmp_centers[i],centers[i]);
    }

    bool same = false;
    for (int i = 0; i < cluster.size()-1; i++){
        for (int j = i+1; j < cluster.size();j++){
            if(distance_func(tmp_centers[i],tmp_centers[j]) <= withinDistance){
                i = cluster.size();
                same = true;
                break;
            }
        }
    }

    if(first == true){
        first = false; return false;
    }

    if(changed_magnitude <= withinDistance && same == false) return true;

    for (int i = 0; i < centers.size(); i++){
        center[i].x = tmp_centers[i].x;
        center[i].y = tmp_centers[i].y;
        center[i].z = tmp_centers[i].z;
    }

    return false;
}
cv::Mat kmeans_clustering(cv::Mat input_matrix, int Numofcluster, int withinDistance){
    CV::Mat ret = cv::Mat::zeros(input_matrix,CV_8UC3);

    //change pixel rgb form;
    std::vector <cv::Point3f> pixels;
    change_form(input_matrix, pixels);

    //randomly choose centers
    srand((unsigned int)time(NULL));
    std::vector<cv::Point3f> centers;
    for (int i = 0; i < Numofcluster; i++){
        int rand[3];
        for (int k = 0; k < 3; k++){
            rand[k] = rand()%255;
        }
        centers.push_back(cv::Point3f(rand[0],rand[1],rand[2]));
    }

    bool first = true;
    std::vector<std::vector<int>> cluster(center.size());
    while(1){
        //allocate pixels to each cluster..
        allocate_cluster(pixels,centers,cluster);
        //find tmp center of cluster
        std::vector<cv::Point3f> tmp_centers;
        solving_tmp_centers(cluster,pixels,tmp_centers);
        // condition check
        if(checking_condition(cluster,centers,tmp_centers,withinDistance,first)) break;
        cluster.clear();
    }

    for (int i = 0; i < cluster.size(); i++){
        for (int j = 0; j < cluster[i].size();j++){
            ret[cluster[i][j]*3+0] = centers[i].x;
            ret[cluster[i][j]*3+1] = centers[i].y;
            ret[cluster[i][j]*3+2] = centers[i].z;
        }
    }
    return ret;
}