#include <iostream>
#include "image2vec.h"
#include "kmeans.h"
#include "histogram.h"


using namespace cbr;
int main(){
    ImageRec analyze_kmeans = ImageRec(0,5);
    ImageRec analyze_histogram = ImageRec(1,5); // second arg is cluster number and we fix  it 5
    for (int i = 1; i <= 100; i++){
        char tmp[50];
        sprintf(tmp, "book_imgs/%d.jpg",i);
 
        std::string str="";
        for (int j = 0; ;j++){
            if(tmp[j]=='\0') break;
            str += tmp[j];
        }
        analyze_kmeans.AddData(str);
        analyze_histogram.AddData(str);
    }

    while(1){
        std::vector<std::pair<int, double>> result;
        std::string str;
        std::cout << "if you want to quit, enter q/Q." << std::endl;
        std::cout << "else press any key and press enter key" << std::endl;
        std::cin >> str;
        if(str == "q" || str == "Q") break;
        int option, k, id;
        std::cout << "press option, id, and choose number" << std::endl;
        std::cout << "option 0 is kmeans and 1 is histogram" << std::endl;
        std::cin >> option >> id >> k;
        if(option == 0){
            analyze_kmeans.GetRankingList(id,k,result); 
        }
        else if(option ==1){
            analyze_histogram.GetRankingList(id,k,result); 
        }

        int len = result.size();
        for (int i = 0; i < len; i++){
            std::cout << result[i].first << ' ' << result[i].second << std::endl;
        }
    }

}