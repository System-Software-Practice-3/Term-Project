#ifndef IMGTVEC
#define IMGTVEC


#include "MYopencv.h"
#include <string>

class img2RGB{
    private:
        cv::Mat FIRST_IMG;
        std::string book_name;
    public:
        img2RGB(std::string str);
        img2RGB(cv::Mat mat);
        cv::Mat get_img();
        //set get bookname;;
};

#endif
