#ifndef IMGTVEC
#define IMGTVEC


#include "MYopencv.h"
#include <string>

class img2RGB{
    private:
        cv::Mat FIRST_IMG;
        std::string book_name;
    public:
        img2RGB();
        img2RGB(std::string str);
        img2RGB(cv::Mat mat);
        cv::Mat get_img();
        void operator=(img2RGB rhs);
        std::string get_bookname();
        //set get bookname;;
};

#endif
