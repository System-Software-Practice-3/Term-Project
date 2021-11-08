#include <Knn.h>

Knn::Knn(){
    double_table.clear();
    dimension = 0;
    metric = "";
}

Knn::Knn(int dim, std::string met){
    double_table.clear();
    dimension = dim;
    metric = met;
}

int Knn::get_dim(){
    return dimension;
}

void Knn::set_dim(int dim){
    dimension = dim;
    return;
}

std::string get_metric(){
    return metric;
}

void set_metric(std::string met){
    metric = met;
    return;
}

double distance(std::vector<double> v1, std::vector<double> v2, std::string met){}

void AddDouble(std::vector<double> data){
    double_table.push_back(data);
    return;
}

void SearchByVector(const std::vector<double> target, int k, vector<int> &result){
    
    std::vector<double> d_vec;
    for(size_t i=0;i<double_table.size();i++){
        std::vector<double> temp = double_table.at(i);
        d_vec.push_back(distance(temp, target));
        
    }
}

void SearchByVector(const int target, int k, vector<int> &result){};
