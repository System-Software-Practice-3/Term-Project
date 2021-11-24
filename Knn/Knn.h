#ifndef Knn_H
#define Knn_H

#include <utility>
#include <cmath>
#include <string>
#include <set>
#include <vector>
#include <iostream>

namespace cbr {
class Knn {
    private:
        std::vector<std::vector<double>> double_table;
        std::vector<std::set<std::string>> string_table;
        
        int dimension;
        std::string metric;

        void sort(std::vector<std::pair<int, double>> &result, int _k);

    public:
        Knn();
        Knn(int dim, std::string met);//dimension of vector, metric used to search.
        
        int get_dim();
        void set_dim(int dim);
        std::string get_metric();
        void set_metric(std::string met);//met <- Euclidean, Manhattan, Jaccard, Cosine

        double distance(std::vector<double> v1, std::vector<double> v2, std::string met);
        double distance(std::set<std::string> s1, std::set<std::string> s2, std::string met);

        //for vector consisting of double.
        void AddData(const std::vector<double> data); //function that add a vector(double) into table;
        void AddData(const std::set<std::string> data); //function that add a set(string) into table;
        void AddData(const std::vector<std::vector<double>> data_table);
        void AddData(const std::vector<std::set<std::string>> data_table);


        void SearchByVector(const std::vector<double> target, int k, std::vector<std::pair<int, double>> &result); //function that search the nearest k vectors. it returns vectors' id.       
        void SearchByVector(const std::set<std::string> target, int k, std::vector<std::pair<int, double>> &result); //function that search the nearest k sets.
        
        void SearchById(const int target, int k, int type, std::vector<std::pair<int, double>> &result); 
        //function that search the nearest k vectors. it returns vectors' id. 
        //type <-  0 - std::vector<double>, 1 - std::set<std::string>
 
};
}
#endif
