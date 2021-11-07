#ifndef Knn_H
#define Knn_H

#include <vector>

class Knn {
    private:
        std::vector<std::vector<double>> double_table;
        int dimension;
        std::string metric;
        void sort(std::vector<double> &vec, std::vector<int> &ret);

    public:
        Knn();
        Knn(int dim, std::string met); //dimension of vector, metric used to search.
        
        int get_dim();
        void set_dim(int dim);
        std::string get_metric();
        void set_metric();

        double distance(std::vector<double> v1, std::vector<double> v2, std::string met);

        //for vector consisting of double.
        void AddDouble(std::vector<double> data); //function that add a vector(double) into table;
        void SearchByVector(const std::vector<double> target, int k, vector<int> &result); //function that search the nearest k vectors. it returns vectors' id.
        void SearchByVector(const int target, int k, vector<int> &result); //function that search the nearest k vectors. it returns vectors' id.

        void Clear(); //function that remove all data in object.
};

#endif
