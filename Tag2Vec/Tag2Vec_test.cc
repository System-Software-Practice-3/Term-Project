#include "Tag2Vec.h"
#include "../Knn/Knn.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>

int main(void){
    using namespace cbr;
    
    Tag2Vec test;
    
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

    Knn fortest(1, "Jaccard");

    std::vector<std::pair<int, double>> ret;
    ret.clear();

    std::set<std::string> test_vec;

    test_vec.clear();
    test_vec.insert("사과");
    test_vec.insert("포도");

    std::cout << "target : 사과 포도" << std::endl;

    fortest.AddData(tag_table);

    fortest.SearchByVector(test_vec, 2, ret);

    for(size_t i =0;i<ret.size();i++){
        std::cout << "ID : " <<ret.at(i).first <<" distance : " << ret.at(i).second << std::endl;
    }

    return 0;
    
}
