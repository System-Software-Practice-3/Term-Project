#ifndef OPENCV2
#define OPENCV2

#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/opencv.hpp"

#include <string>

class img2RGB{
    private:
        cv::Mat FIRST_IMG;
        cv::Mat RED;
        cv::Mat GREEN;
        cv::Mat BLUE;
        int row;
        int col;

    public:
        img2RGB(std::string str);
        void RESIZE(int row, int col);
        cv::Mat get_R();
        cv::Mat get_G();
        cv::Mat get_B();

};

#endif
