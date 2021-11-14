#include "Tag2Vec.h"


namespace cbr {
    Tag2Vec::Tag2Vec(){
        tag_list.clear();
        tag_table.clear();
    }

    void Tag2Vec::AddData(const std::set<std::string> data){
        tag_table.push_back(data);

        for(auto iter=data.begin();iter!=data.end();iter++){
            tag_list.insert(*iter);
        }

        return;
    }

    std::vector<std::set<std::string>> Tag2Vec::GetTable(){
        return tag_table;
    }

    std::set<std::string> Tag2Vec::GetVectorById(int id){
        return tag_table.at(id);
    }

    std::set<std::string> Tag2Vec::GetTagList(){
        return tag_list;
    }

    std::set<std::string> Tag2Vec::split(const std::string& text){
        size_t i =0;
        std::string temp;
        std::set<std::string> ret;
        ret.clear();

        while(i < text.size()){
            if(text.at(i) != ','){
                temp += text.at(i);
            } else if(text.at(i) == ',' || text.at(i) == '\n'){
                ret.insert(temp);
                temp.clear();
            }
            i++;
        }

        return ret;
    }
}
