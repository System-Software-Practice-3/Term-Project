#include <iostream>
#include "image2vec.h"
#include "kmeans.h"

int main(){
    img2RGB A = img2RGB("lena.jpg");
    img2RGB B = kmeans_clustering(A.get_img(),2,5);
    cv:: namedWindow("changed Blue");
    //int row = B.get_B().rows;
    //int col = B.get_B().cols;


    cv::imshow("changed Blue",B.get_img());
    cv::waitKey(0);
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