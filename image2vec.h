#ifndef IMGTVEC
#define IMGTVEC


#include "MYopencv.h"
#include <string>

class img2RGB{
    private:
        cv::Mat FIRST_IMG;
        int row;
        int col;
        std::string book_name;
    public:
        img2RGB(std::string str);
        void RESIZE(int row, int col);
};

#endif
