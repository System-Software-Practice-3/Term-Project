#include "image2vec.h"

img2RGB::img2RGB(){
}

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

img2RGB::img2RGB(cv::Mat mat){
    FIRST_IMG = mat;
}

cv::Mat img2RGB::get_img(){
    return FIRST_IMG;
}

void img2RGB::operator=(img2RGB rhs){
    this->FIRST_IMG = rhs.FIRST_IMG;
    this->book_name = rhs.book_name;
}

std::string img2RGB::get_bookname(){
    return this->book_name;
}