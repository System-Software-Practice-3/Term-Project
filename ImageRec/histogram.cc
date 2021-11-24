#include "MYopencv.h"
#include "image2vec.h"
#include <utility>

using namespace cbr;
std::vector<cv::Mat> histogram;
std::vector<cv::Mat> HLS_img;
std::vector<img2RGB> tmp_picture;

void calculate_histo(std::vector<img2RGB>& stored_picture){
    //convert to hls format
    int len = stored_picture.size();
    std::vector<cv::Mat> tmp_img(len);
    tmp_picture = stored_picture;

    for (int i = 0; i < len; i++){
        cvtColor(tmp_picture[i].get_img(),tmp_img[i],cv::COLOR_BGR2HLS);
    }

    HLS_img = tmp_img;
    std::vector<cv::Mat> tmp_histogram(len);
    histogram = tmp_histogram;
    int channel_num[]={0,1,2};

    for (int i = 0; i < len; i++){
        int* bins_num = new int[HLS_img[i].channels()];
        for (int j = 0; j < HLS_img[i].channels(); j++){
            bins_num[j] = 8;
        }
        float range[]={0.0,255.0};
        const float *Ranges[]={range,range,range};
        calcHist(&HLS_img[i],1,channel_num,cv::Mat(),histogram[i],HLS_img[i].channels(),bins_num,Ranges);
        normalize(histogram[i],histogram[i],1.0);
    }
}

std::vector<std::pair<int,double>> histo_similarity(img2RGB input, std::vector<img2RGB> stored_picture, int choose_num){
    int len = histogram.size();
    std::vector<img2RGB> tmp_stored_picture = stored_picture;
    std::vector<double> similarity(len);

    for(int i = 0; i < len; i++){
        similarity[i] = compareHist(histogram[input.get_id()-1],histogram[i],cv::HISTCMP_CORREL);
    }

    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len-1-i;j++){
            if(similarity[j] < similarity[j+1]){
                double num_tmp = similarity[j];
                img2RGB RGB_tmp = tmp_stored_picture[j];

                similarity[j] = similarity[j+1];
                similarity[j+1] = num_tmp;

                tmp_stored_picture[j] = tmp_stored_picture[j+1];
                tmp_stored_picture[j+1] = RGB_tmp;
            }
        }
    }

    std::vector<std::pair<int,double>> ret;
    for (int i = 1; i <= choose_num;i++){
        ret.push_back(std::make_pair(tmp_stored_picture[i].get_id(),similarity[i]));//bigger is similiar
    }
    return ret;
}


