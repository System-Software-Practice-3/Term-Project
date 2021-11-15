#include <iostream>
#include "image2vec.h"
#include "kmeans.h"
#include "histogram.h"

int main(){
    //img2RGB A = img2RGB("lena.jpg");
    std::vector<img2RGB> A;
    //A.push_back(img2RGB("apple.jpeg"));
    A.push_back(img2RGB("apple1.jpeg"));
    A.push_back(img2RGB("apple2.jpeg"));
    A.push_back(img2RGB("sky.jpeg"));
    A.push_back(img2RGB("sky1.jpeg"));
    A.push_back(img2RGB("sky2.jpeg"));
    //img2RGB B = kmeans_clustering(A.get_img(),2,5);
    //cv:: namedWindow("changed Blue");
    //int row = B.get_B().rows;
    //int col = B.get_B().cols;
    std::cout << "kmeans" << std::endl;
    std::vector<img2RGB> B = kmeans_similarity(img2RGB("apple.jpeg"),A,3,5,2);
    int len = B.size();
    for (int i = 0; i < len; i++){
        std::cout << B[i].get_bookname() << std:: endl;
    }
//void calculate_histo(img2RGB input,std::vector<img2RGB> stored_picture)
//std::vector<img2RGB> histo_similarity(std::vector<img2RGB> stored_picture, int choose_num)
    std::cout << "histogram" << std::endl;
    calculate_histo(img2RGB("apple.jpeg"),A);
    B = histo_similarity(A, 2);
    len = B.size();
    for (int i = 0; i < len; i++){
        std::cout << B[i].get_bookname() << std:: endl;
    }
    //cv::imshow("changed Blue",B.get_img());
    //cv::waitKey(0);
    return 0;
}

/*
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ",B.get_B().at<u_char>(i,j));
        }
        std::cout << '\n';
    }
*/