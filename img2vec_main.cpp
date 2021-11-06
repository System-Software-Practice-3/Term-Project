#include <iostream>
#include "image2vec.h"

int main(){
    std::cout << "start test!" << std::endl;
    img2RGB A = img2RGB("lena.jpg");
    A.RESIZE(100,100);
    img2RGB B = A;
    cv:: namedWindow("changed Blue");
    int row = B.get_B().rows;
    int col = B.get_B().cols;

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            //std::cout << std::dec << B.get_B().at<uchar>(i,j) << ' ';
            printf("%d ",B.get_B().at<u_char>(i,j));
        }
        std::cout << '\n';
    }
    cv::imshow("changed Blue",B.get_B());
    cv::waitKey(0);
    return 0;
}