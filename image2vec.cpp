#include "image2vec.h"

img2RGB::img2RGB(std::string str){
    FIRST_IMG = cv::imread(str,cv::IMREAD_COLOR);
    int len = str.length();
    std::string tmp_bookname="";

    for (int i = 0; i < len; i++){
        if(str[i]=='.') break;
        tmp_bookname+=str[i];
    }
    book_name = tmp_bookname;
}


void img2RGB::RESIZE(int row, int col){
    cv::Mat dst;
    this->row =row;
    this->col = col;
    resize(FIRST_IMG,dst,cv::Size(row,col));
    FIRST_IMG = dst;
}
