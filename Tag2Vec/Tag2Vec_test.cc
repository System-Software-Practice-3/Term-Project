#include "Tag2Vec.h"

#include <iostream>
#include <string>
#include <vector>

int main(void){
    Tag2Vec test;
    
    std::string test1[3] = {"apple", "pear", "grape"};
    std::string test2[3] = {"grape", "strawberry", "pineapple"};

    std::vector<std::string> test_vec;
    test_vec.clear();

    for(auto i:test1){
        test_vec.push_back(i);
    }

    test.AddData(test_vec);

    test_vec.clear();

    for(auto i:test2){
        test_vec.push_back(i);
    }

    test.AddData(test_vec);

    std::cout << "test tag1 : apple pear grape" << std::endl;
    std::cout << "test tag2 : grape strawberry pineapple" << std::endl;

    std::vector<std::string> tag_list = test.GetTagList();

    std::cout << "tag_list : ";
    for(size_t i =0;i<tag_list.size();i++){
        std::cout << tag_list.at(i) << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<double>> tag_table = test.GetTable();

    std::cout << "tag_vector_table : " << std::endl;
    for(size_t i =0;i<tag_table.size();i++){
        for(size_t j =0;j<tag_table.at(i).size();j++){
            std::cout << tag_table.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
    
}
