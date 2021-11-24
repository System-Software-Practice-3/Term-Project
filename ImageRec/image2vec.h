#ifndef IMGTVEC
#define IMGTVEC

#include "MYopencv.h"
#include "../ItemRec.cc"
#include <string>
namespace cbr{
    class img2RGB{
        private:
            cv::Mat FIRST_IMG;
            int id;
            std::string book_name;
        public:
            img2RGB(){};
            img2RGB(std::string str);
            img2RGB(cv::Mat mat);
            void set_id(int id);
            int get_id();
            cv::Mat get_img();
            void operator=(img2RGB rhs);
            std::string get_bookname();
            //set get bookname;;
    };

    class ImageRec : public ItemRec<std::string> {
        private:
            int option;
            int cluster_num;
            std::vector<img2RGB> pictures;
            //option 0 is kmeans
            //option 1 is histogram
        public:
            ImageRec(int op, int cluster_number);
            void AddData(const std::string& data) override;
            void GetRankingList(int id, int k, std::vector<std::pair<int, double>>& result) override;
    };

}
#endif
