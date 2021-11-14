#include "Knn.h"

namespace cbr {
    Knn::Knn(){
        double_table.clear();
        string_table.clear();
        dimension = 0;
       metric = "";
    }

    Knn::Knn(int dim, std::string met){
        double_table.clear();
        string_table.clear();
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

    std::string Knn::get_metric(){
        return metric;
    }

    void Knn::set_metric(std::string met){
        metric = met;
        return;
    }

    double Knn::distance(std::vector<double> v1, std::vector<double> v2, std::string met){
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
        } else if(met == "Jaccard"){
            int intersection = 0;
            double result;
            int* check = new int[v1.size()];
            
            for(size_t i =0;i<v1.size();i++){
                check[i]=0;
            }

            for(size_t i =0;i<v1.size();i++){
                for(size_t j =0;j<v2.size();j++){
                    if((v1.at(i) == v2.at(j)) && (check[j] == 0)){
                        intersection++;
                        check[j]=1;
                        break;
                    }
                }
            }

            result = 1 - static_cast<double>(intersection)/static_cast<double>(v1.size() + v2.size() - intersection);
        
            return result; //0 is the most similarity

        } else if(met == "Cosine"){
            double adotb =0;
            double a = 0;
            double b = 0;
            double result = 0;

            for(size_t i =0;i<v1.size();i++){
                adotb += v1.at(i) * v2.at(i);
            }

            for(size_t i =0;i<v1.size();i++){
                a += v1.at(i) * v1.at(i);
            }
            a = sqrt(a);

            for(size_t i=0;i<v1.size();i++){
                b += v2.at(i) * v2.at(i);
            }
            b = sqrt(b);

            result = adotb / (a*b);

            return -result; //-1 is the most similarist one
        }


    }

    double Knn::distance(std::set<std::string> s1, std::set<std::string> s2, std::string met){
        if(met == "Jaccard"){
            int intersection = 0;
            double result;

            for(auto iter1=s1.begin();iter1!=s1.end();iter1++){
                for(auto iter2=s2.begin();iter2!=s2.end();iter2++){
                    if((*iter1 == *iter2)){
                        intersection++;
                    }
                }
            }

            result = 1 - static_cast<double>(intersection)/(s1.size() + s2.size() - intersection);

            return result;
        }
    }


    void Knn::AddData(const std::vector<double> data){
        if(dimension == 0){
            std::cout << "Please set the dimension!" << std::endl;
            exit(1);
        } else if(data.size() != dimension){
            std::cout << "Data dimension mismatch!" << std::endl;
            exit(1);
        }

        double_table.push_back(data);
        return;
    }

    void Knn::AddData(const std::set<std::string> data){
        string_table.push_back(data);
        return;
    }     

    void Knn::AddData(const std::vector<std::vector<double>> data_table){
        double_table = data_table;
        return;
    }

    void Knn::AddData(const std::vector<std::set<std::string>> data_table){
        string_table = data_table;
        return;
    }

    void Knn::SearchByVector(const std::vector<double> target, int k, std::vector<std::pair<int, double>> &result){
        if(dimension == 0){
            std::cout << "Please set the dimension!" << std::endl;
            exit(1);
        } else if(metric == ""){
            std::cout << "Please set the metric!" << std::endl;
            exit(1);
        } else if(target.size() != dimension){
            std::cout << "Target dimension mismatch!" << std::endl;
            exit(1);
        }
   
        result.clear();

        for(size_t i=0;i<double_table.size();i++){
            std::vector<double> temp = double_table.at(i);
            result.push_back(std::pair<int, double>(i, distance(temp, target, metric)));
        }

        sort(result, k);

        return;
    }

    void Knn::SearchByVector(const std::set<std::string> target, int k, std::vector<std::pair<int, double>> &result){
        if(metric == ""){
            std::cout << "Please set the metric!" << std::endl;
            exit(1);
        }
   
        result.clear();

        for(size_t i=0;i<string_table.size();i++){
            std::set<std::string> temp = string_table.at(i);
            result.push_back(std::pair<int, double>(i, distance(temp, target, metric)));
        }

        sort(result, k);

        return;
    }

    void Knn::SearchById(const int target, int k, int type, std::vector<std::pair<int, double>> &result){
        if(dimension == 0){
            std::cout << "Please set the dimension!" << std::endl;
            exit(1);
        } else if(metric == ""){
            std::cout << "Please set the metric!" << std::endl;
            exit(1);
        } else if(type == 0){
            if(target < 0 || double_table.size() <= target){
                std::cout << "Target Id is illegal!" << std::endl;
                exit(1);
            } 
        } else if(type == 1){
            if(target < 0 || string_table.size() <= target){
                std::cout << "Target Id is illegal!" << std::endl;
                exit(1);
            }
        }
   
        result.clear();

   
        if(type == 0){
            std::vector<double> temp2 = double_table.at(target);
            for(size_t i=0;i<double_table.size();i++){
                if(i == target) continue;

                std::vector<double> temp1 = double_table.at(i);

                result.push_back(std::pair<int, double>(i, distance(temp1, temp2, metric)));
            }

            sort(result, k);
        }      
        else if(type == 1){
            std::set<std::string> temp2 = string_table.at(target);
                for(size_t i=0;i<string_table.size();i++){
                    if(i == target) continue;

                    std::set<std::string> temp1 = string_table.at(i);

                    result.push_back(std::pair<int, double>(i, distance(temp1, temp2, metric)));
                }

                sort(result, k);
        }

        return;
    }

    void Knn::sort(std::vector<std::pair<int, double>> &result, int _k){
        std::pair<int, double> temp;

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

        if(result.size() < _k){
            std::cout << "The number of data in table is less than K";
        }

        while(result.size() > _k){
            result.pop_back();
        }

        return;
    }
}
