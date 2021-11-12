#include "Tag2Vec.h"

Tag2Vec::Tag2Vec(){
    tag_list.clear();
    tag_table.clear();
}

void Tag2Vec::AddData(const std::vector<std::string> data){
    
    int check = 0;
    std::vector<double> temp;
    temp.clear();

    for(size_t i =0;i<data.size();i++){
        check = 0;
        for(size_t j =0;j<tag_list.size();j++){
            if(data.at(i) == tag_list.at(j)){
                check = 1;
                break;
            }
        }
        if(check == 0){
            tag_list.push_back(data.at(i));
        }
    }

    for(size_t i =0;i<tag_list.size();i++){
        check = 0;
        for(size_t j =0;j<data.size();j++){
            if(tag_list.at(i) == data.at(j)){
                check = 1;
                break;
            }
        }
        if(check == 1){
            temp.push_back(1);
        } else{
            temp.push_back(0);
        }
    }

    tag_table.push_back(temp);

    for(size_t i = 0;i<tag_table.size();i++){
        while(tag_table.at(i).size() < tag_list.size()){
            tag_table.at(i).push_back(0);
        }
    }

    return;
}

std::vector<std::vector<double>> Tag2Vec::GetTable(){
    return tag_table;
}

std::vector<double> Tag2Vec::GetVectorById(int id){
    return tag_table.at(id);
}

std::vector<std::string> Tag2Vec::GetTagList(){
    return tag_list;
}
