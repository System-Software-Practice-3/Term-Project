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

double distance(std::vector<double> v1, std::vector<double> v2, std::string met){
    if(met == "Euclidean"){
        double result = 0;

        for(size_t i=0;i<v1.size();i++){
            result += pow(v1.at(i)-v2.at(i), 2);
        }

        return sqrt(result);
    } else if(met == "Manhattan"){
        double result = 0;

        for(size_t i=0;i<v1.size();i++){
            result += abs(v1.at(i)-v2.at(i));
        }

        return result;
    }


}

void AddDouble(std::vector<double> data){
    double_table.push_back(data);
    return;
}

void SearchByVector(const std::vector<double> target, int k, std::vector<pair<int, double>> &result){
    
    for(size_t i=0;i<double_table.size();i++){
        std::vector<double> temp = double_table.at(i);
        result.push_back(pair<int, double>(i, distance(temp, target)));
    }

    sort(result, k);

    return;
}

void SearchById(const int target, int k, std::vector<pair<int, double>> &result){
    
    std::vector<double> temp2 = double_table.at(target);
    for(size_t i=0;i<double_table.size();i++){
        if(i == target) continue;

        std::vector<double> temp1 = double_table.at(i);

        result.push_back(pair<int, double>(i, distance(temp1, temp2)));
    }

    sort(result, k);

    return;


};

void sort(std::vector<pair<int, double>> &result, int _k){
    pair<int, double> temp;

    //O(n^2) sorting algorithm
    for(size_t i=0;i<result.size()-1;i++){
        for(size_t j=i+1;j<result.size();j++){
            if(result.at(i).second > result.at(j).second){
                temp = result.at(i);
                result.at(i) = result.at(j);
                result.at(j) = temp;
            }
        }
    }

    return;
}
