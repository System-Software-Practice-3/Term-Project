#ifndef Text2Vec_H
#define Text2Vec_H

#include <string>
#include <vector>
#include <utility>
#include <map>

class TfidfVectorizer {
private: 
    int max_features;
    std::map<std::string, int> df;
    std::vector<std::map<std::string, int>> tfidf;

public:
    TfidfVectorizer();
    TfidfVectorizer(int _max_features = -1);
    std::vector<std::string> split(const std::string& text);
    void fit(const std::vector<std::string>& text_list);
    std::vector<std::vector<double>> transform();
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
