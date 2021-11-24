#include "image2vec.h"
#include "kmeans.h"
#include "histogram.h"

ImageRec::ImageRec(int op,int cluster_number){
    option = op;
    cluster_num = cluster_number;
}

void ImageRec::AddData(const std::string& data){
    pictures.push_back(img2RGB(data));
}

void ImageRec::GetRankingList(int id, int k, std::vector<std::pair<int, double>>& result) {
    int len = pictures.size();

    img2RGB compare_picture;
    for(int i = 0; i < len; i++){
        if(pictures[i].get_id() == id){
            compare_picture = pictures[i];
            break;
        }
    }   
    if(option == 0){
        result = kmeans_similarity(compare_picture,pictures,cluster_num,5,k);
    }
    else if(option == 1){
        calculate_histo(pictures);     
        result = histo_similarity(compare_picture,pictures,k);
    }
}