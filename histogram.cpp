#include "MYopencv.h"
#include "image2vec.h"


std::vector<cv::Mat> histogram;
std::vector<cv::Mat> HLS_img;
std::vector<img2RGB> tmp_picture;

void calculate_histo(img2RGB input,std::vector<img2RGB> stored_picture){
    //convert to hls format
    int len = stored_picture.size()+1;
    std::vector<cv::Mat> tmp_img(len);
    tmp_picture = stored_picture;
    tmp_picture.push_back(input);

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

std::vector<img2RGB> histo_similarity(std::vector<img2RGB> stored_picture, int choose_num){
    int len = histogram.size();
    std::vector<double> similarity(len);
    for(int i = 0; i < len-1; i++){
        similarity[i] = compareHist(histogram[len-1],histogram[i],cv::HISTCMP_CORREL);
    }

    for (int i = 0; i < len-2; i++){
        for (int j = 0; j < len-2-i;j++){
            if(similarity[j] < similarity[j+1]){
                double num_tmp = similarity[j];
                img2RGB RGB_tmp = stored_picture[j];

                similarity[j] = similarity[j+1];
                similarity[j+1] = num_tmp;

                stored_picture[j] = stored_picture[j+1];
                stored_picture[j+1] = RGB_tmp;
            }
        }
    }
    std::vector<img2RGB> ret;
    for (int i = 0; i < choose_num;i++){
        ret.push_back(stored_picture[i]);
    }
    return ret;
}


