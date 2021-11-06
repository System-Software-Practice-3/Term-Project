#include "image2vec.h"

img2RGB::img2RGB(std::string str){
    FIRST_IMG = cv::imread(str,cv::IMREAD_COLOR);

    cv::Mat BGR[3];

    cv::split(FIRST_IMG,BGR);
    RED = BGR[2];
    GREEN = BGR[1];
    BLUE = BGR[0];


    cv::namedWindow("Original image");
    cv::namedWindow("RED image");
    cv::namedWindow("GREEN image");
    cv::namedWindow("BLUE image");

    cv::imshow("Original image", FIRST_IMG);
    cv::imshow("RED image",RED);
    cv::imshow("GREEN image",GREEN);
    cv::imshow("BLUE image",BLUE);

    cv:: waitKey(0);
}


void img2RGB::RESIZE(int row, int col){
    cv::Mat dst;
    this->row =row;
    this->col = col;
    resize(FIRST_IMG,dst,cv::Size(row,col));
    FIRST_IMG = dst;


    resize(RED,dst,cv::Size(row,col));
    RED = dst;

    resize(GREEN,dst,cv::Size(row,col));
    GREEN = dst;

    resize(BLUE,dst,cv::Size(row,col));
    BLUE = dst;
}

cv::Mat img2RGB::get_R(){
    return RED;
}

cv::Mat img2RGB::get_G(){
    return GREEN;
}

cv::Mat img2RGB::get_B(){
    return BLUE;
}