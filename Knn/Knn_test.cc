#include "Knn.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main(void){
    //double test
  /*
    Knn double_test(3, "Euclidean");

    std::vector<double> test_vec;
    std::vector<std::pair<int, double>> ret;

    test_vec.clear();
    test_vec.push_back(1);
    test_vec.push_back(3);
    test_vec.push_back(5);

    std::cout<< "input vector1 : 1 3 5" << std::endl;

    double_test.AddData(test_vec);

    test_vec.clear();
    test_vec.push_back(5);
    test_vec.push_back(45);
    test_vec.push_back(12);

    std::cout<< "input vector2 : 5 45 12" << std::endl;

    double_test.AddData(test_vec);

    test_vec.clear();
    test_vec.push_back(26);
    test_vec.push_back(18);
    test_vec.push_back(75);

    std::cout << "input vector3 : 26 18 75" << std::endl;

    double_test.AddData(test_vec);

    test_vec.clear();
    test_vec.push_back(3);
    test_vec.push_back(6);
    test_vec.push_back(26);

    std::cout << "search by vector : 3 6 26" << std::endl;

    double_test.SearchByVector(test_vec, 2, ret);

    for(size_t i =0;i<2;i++){
        std::cout << "ID : " << ret.at(i).first << " distance : " << ret.at(i).second << std::endl;
    }

    std::cout << "search by ID : 1" << std::endl;

    double_test.SearchById(1, 2, 0, ret);

    for(size_t i=0;i<2;i++){
        std::cout << "ID : " << ret.at(i).first << " distance : " << ret.at(i).second << std::endl;
    }
*/


    //string test

    Knn string_test(3, "Jaccard");

    std::set<std::string> test_set;
    std::vector<std::pair<int, double>> ret;

    test_set.clear();
    test_set.insert("apple");
    test_set.insert("pear");
    test_set.insert("grape");

    std::cout<< "input set1 : apple pear grape" << std::endl;

    string_test.AddData(test_set);
    
    test_set.clear();
    test_set.insert("apple");
    test_set.insert("blueberry");
    test_set.insert("melon");

    std::cout<< "input set2 : apple blueberry melon" << std::endl;

    string_test.AddData(test_set);

    test_set.clear();
    test_set.insert("pear");
    test_set.insert("grape");
    test_set.insert("melon");

    std::cout << "input set3 : pear grape melon" << std::endl;

    string_test.AddData(test_set);

    test_set.clear();
    test_set.insert("blueberry");
    test_set.insert("grape");
    test_set.insert("melon");

    std::cout << "search by set : blueberry grape melon" << std::endl;

    string_test.SearchByVector(test_set, 2, ret);

    for(size_t i =0;i<2;i++){
        std::cout << "ID : " << ret.at(i).first << " distance : " << ret.at(i).second << std::endl;
    }

    std::cout << "search by ID : 1" << std::endl;

    string_test.SearchById(1, 2, 1, ret);

    for(size_t i=0;i<2;i++){
        std::cout << "ID : " << ret.at(i).first << " distance : " << ret.at(i).second << std::endl;
    }

}
