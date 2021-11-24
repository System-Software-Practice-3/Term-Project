#include "image2vec.h"
#include "kmeans.h"
#include "histogram.h"

img2RGB::img2RGB(std::string str){
    FIRST_IMG = cv::imread(str,cv::IMREAD_COLOR);
    int len = str.length();
    std::string tmp_bookname="";
    std::string tmp_bookname2="";
    for (int i = 0; i < len; i++){
        if(str[i]=='.') break;
        tmp_bookname+=str[i];
    }
    len = tmp_bookname.size();
    for (int i = len-1;;i--){
        if(!(tmp_bookname[i] >= '0' && tmp_bookname[i] <= '9')){
            for(int j = i+1; j < len;j++){
                tmp_bookname2[j-i-1] += tmp_bookname[j];
            }
            id = stoi(tmp_bookname2);
            break;
        }
    }
}

img2RGB::img2RGB(cv::Mat mat){
    FIRST_IMG = mat;

}

void img2RGB::set_id(int id){
    this->id = id;
}

int img2RGB::get_id(){
    return id;
}

cv::Mat img2RGB::get_img(){
    return FIRST_IMG;
}

void img2RGB::operator=(img2RGB rhs){
    this->FIRST_IMG = rhs.FIRST_IMG;
    this->book_name = rhs.book_name;
    this->id = rhs.id;
}

std::string img2RGB::get_bookname(){
    return this->book_name;
}

