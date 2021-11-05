#ifndef Text2Vec_H
#define Text2Vec_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>

class TfidfVectorizer {
private:
    int max_features;
    int min_df;
    std::pair<int, int> ngram_range;
    std::string analyzer; //word, char
    std::map<std::string, int> df;
    std::vector<std::map<std::string, int>> tf;

public:
    TfidfVectorizer();
    TfidfVectorizer(int _max_features);
    std::vector<std::string> split(const std::string& text, std::vector<std::string> seperators, bool word_unit=true);
    void set_configs(const std::vector<std::pair<std::string, std::string>>& config);
    void fit(const std::vector<std::string>& text_list);
    std::vector<std::vector<double>> transform();
    std::map<std::string, int> get_df() const;
    std::vector<std::map<std::string, int>> get_tf() const;
};

class Text2Vec {
private:
    std::vector<std::string> text_list;
    std::vector<std::vector<double>> vectorized_text_list;

public:
    void AddData(const std::string& text);
    void Build(std::string policy="tf-idf");
    void GetVectorById(int id, std::vector<double>& result) const;
};

#endif
