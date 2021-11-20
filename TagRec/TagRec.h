#ifndef TagRec_H
#define TagRec_H

#include <vector>
#include <string>
#include <iostream>
#include <set>
#include "ItemRec.cc"
#include "../Knn/Knn.h"

namespace cbr{
    class TagRec : public ItemRec<std::set<std::string>>{
        private:
            std::set<std::string> tag_list;
            std::vector<std::set<std::string>> tag_table;
        public:
            TagRec();
            //inherited split function

            void AddData(const std::set<std::string>& data) override;

            std::vector<std::set<std::string>> GetTable();
            std::set<std::string> GetVectorById(int id);
            std::set<std::string> GetTagList();
            std::set<std::string> split(const std::string& text);

            void GetRankingList(int id, int k, std::vector<int>& result) override;
            void GetRankingList(int id, int k, std::vector<std::pair<int, double>>& result) override;
    };
}

#endif
