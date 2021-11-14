#ifndef Tag2Vec_H
#define Tag2Vec_H

#include <vector>
#include <string>
#include <iostream>
#include <set>

namespace cbr{
    class Tag2Vec {
        private:
            std::set<std::string> tag_list;
            std::vector<std::set<std::string>> tag_table;
        public:
            Tag2Vec();
            //inherited split function

            void AddData(const std::set<std::string> data);

            std::vector<std::set<std::string>> GetTable();
            std::set<std::string> GetVectorById(int id);
            std::set<std::string> GetTagList();
            std::set<std::string> split(const std::string& text);
    };
}

#endif
