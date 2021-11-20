#include "TagRec.h"


namespace cbr {
    TagRec::TagRec(){
        tag_list.clear();
        tag_table.clear();
    }

    void TagRec::AddData(const std::set<std::string>& data){
        tag_table.push_back(data);

        for(auto iter=data.begin();iter!=data.end();iter++){
            tag_list.insert(*iter);
        }

        return;
    }

    std::vector<std::set<std::string>> TagRec::GetTable(){
        return tag_table;
    }

    std::set<std::string> TagRec::GetVectorById(int id){
        return tag_table.at(id);
    }

    std::set<std::string> TagRec::GetTagList(){
        return tag_list;
    }

    std::set<std::string> TagRec::split(const std::string& text){
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

    void TagRec::GetRankingList(int id, int k, std::vector<int>& result){
        Knn knn(1, "Jaccard");
        std::vector<std::pair<int, double>> ret;

        knn.AddData(tag_table);
        knn.SearchById(id, k, 1, ret);

        for(size_t i;i<ret.size();i++){
            result.at(i) = ret.at(i).first;
        }

        return;
    }

    void TagRec::GetRankingList(int id, int k, std::vector<std::pair<int, double>> & result){
        Knn knn(1, "Jaccard");

        knn.AddData(tag_table);
        knn.SearchById(id, k, 1, result);

        return;
    }
}
