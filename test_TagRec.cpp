#include "./TagRec/TagRec.h"
#include <iostream>
#include <fstream>
#include <string>

const std::string PATH = "../book_tag/";

int main(void){
    std::ifstream ifs;
    std::string str;
    cbr::TagRec tag;
    std::vector<std::pair<int, double>> result;
    int id, k;

    std::cout << "id k 입력" << std::endl;
    std::cin >> id >> k;

    for(int i = 1;i<=100;i++){
        ifs.open(PATH + std::to_string(i) + ".csv");
        getline(ifs, str);
        tag.AddData(tag.split(str));
        ifs.close();
    }

    tag.GetRankingList(id, k, result);

    return 0;
}
