#ifndef Tag2Vec_H
#define Tag2Vec_H

#include <vector>
#include <string>
#include <iostream>

class Tag2Vec {
    private:
        std::vector<std::string> tag_list;
        std::vector<std::vector<double>> tag_table;
    public:
        Tag2Vec();
        //inherited split function

        void AddData(const std::vector<std::string> data);

        std::vector<std::vector<double>> GetTable();
        std::vector<double> GetVectorById(int id);
        std::vector<std::string> GetTagList();
};

#endif
