#ifndef Knn_H
#define Knn_H

#include <vector>
#include <utility>
#include <cmath>

class Knn {
    private:
        std::vector<std::vector<double>> double_table;
        int dimension;
        std::string metric;
        void sort(std::vector<pair<int, double>> &result, int _k);

    public:
        Knn();
        Knn(int dim, std::string met); //dimension of vector, metric used to search.
        
        int get_dim();
        void set_dim(int dim);
        std::string get_metric();
        void set_metric(std::string met);//Euclidean, Manhattan 

        double distance(std::vector<double> v1, std::vector<double> v2, std::string met);

        //for vector consisting of double.
        void AddDouble(std::vector<double> data); //function that add a vector(double) into table;
        void SearchByVector(const std::vector<double> target, int k, std::vector<pair<int, double>> &result); //function that search the nearest k vectors. it returns vectors' id.
        void SearchById(const int target, int k, std::vector<pair<int, double>> &result); //function that search the nearest k vectors. it returns vectors' id.

};

#endif
