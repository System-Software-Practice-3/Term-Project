#include "Knn.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main(void){
    //double test
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



    //string test
    



}
