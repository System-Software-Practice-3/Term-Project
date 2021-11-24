#include "TagRec.h"
#include "../Knn/Knn.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>

int main(void){
    using namespace cbr;
    
    TagRec test;
    
    std::string test1 = "사과,배,포도,";
    std::string test2 = "포도,딸기,파인애플,";

    test.AddData(test.split(test1));

    test.AddData(test.split(test2));

    std::cout << "test tag1 : 사과 배 포도" << std::endl;
    std::cout << "test tag2 : 포도 딸기 파인애플" << std::endl;

    std::set<std::string> tag_list = test.GetTagList();

    std::cout << "tag_list : ";
    for(auto iter = tag_list.begin();iter != tag_list.end(); iter++){
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    std::vector<std::set<std::string>> tag_table = test.GetTable();

    std::cout << "tag_vector_table : " << std::endl;
    for(size_t i =0;i<tag_table.size();i++){
        std::cout << "ID " << i << " " << std::endl;
        for(auto iter = tag_table.at(i).begin();iter != tag_table.at(i).end();iter++){
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }
   
    std::cout << "--------------------------" <<std::endl;

    std::vector<std::pair<int, double>> ret;
    ret.clear();

    test.GetRankingList(0, 1, ret);

    for(size_t i =0;i<ret.size();i++){
        std::cout << "ID : " <<ret.at(i).first <<" distance : " << ret.at(i).second << std::endl;
    }

    return 0;
    
}
