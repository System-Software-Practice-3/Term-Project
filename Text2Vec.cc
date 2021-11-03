#include "Text2Vec.h"
#include <iostream>

TfidfVectorizer::TfidfVectorizer() : max_features(-1), min_df(-1), analyzer("word"), ngram_range(std::pair<int, int>(1, 1)) {}

std::vector<std::string> TfidfVectorizer::split(const std::string& text, std::vector<std::string> seperators, bool word_unit) {
    std::vector<std::string> ret;
    std::string tmp;
    int i = 0;
    while (i < text.size()) {
        int char_sz = 0;

        if ((text[i] & 0b11111000) == 0b11110000) char_sz = 4;
        else if ((text[i] & 0b11110000) == 0b11100000) char_sz = 3;
        else if ((text[i] & 0b11100000) == 0b11000000) char_sz = 2;
        else if ((text[i] & 0b10000000) == 0b00000000) char_sz = 1;
        else return {}; //not used

        std::string str = text.substr(i, char_sz);
        i += char_sz;
        if (!word_unit) {
            bool flag = 0;
            for (std::string sep : seperators) 
                if (str == sep) {
                    flag = 1; break;
                }
            if (!flag) ret.push_back(str);
        } else {
            bool flag = 0;
            for (std::string sep : seperators) 
                if (str == sep) {
                    flag = 1; break;
                }

            if (flag) {
                if (tmp.size()) ret.push_back(tmp);
                tmp.clear();
                continue;
            }

            tmp += str;
        }
    }
    if (tmp.size()) ret.push_back(tmp);
    return ret;
}

void TfidfVectorizer::set_configs(const std::vector<std::pair<std::string, std::string>>& config) {
    for (auto c : config) {
        if (c.first == "max_features") max_features = stoi(c.second);
        else if (c.first == "min_df") min_df = stoi(c.second);
        else if (c.first == "analyzer") analyzer = c.second;
        else if (c.first == "ngram_range") {
            std::vector<std::string> range = split(c.second, {"{", "}", ",", " "});
            ngram_range.first = stoi(range[0]);
            ngram_range.second = stoi(range[1]);
        }
    }
}