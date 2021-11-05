#include "Text2Vec.h"
#include <iostream>


TfidfVectorizer::TfidfVectorizer() : max_features(-1), min_df(-1), analyzer("word"), ngram_range(std::pair<int, int>(1, 1)) {}

std::vector<std::string> TfidfVectorizer::split(const std::string& text, std::vector<std::string> seperators, bool word_unit) {
    std::vector<std::string> ret;
    std::string tmp;
    int i = 0;
    while (i < text.size()) {
        int char_sz = 0;

        if ((text[i] & 0b11111000) == 0b11110000) {
            if (i+3 < text.size() && (text[i+1] & 0b11000000) == 0b10000000 && (text[i+2] & 0b11000000) == 0b10000000 && (text[i+3] & 0b11000000) == 0b10000000)
                char_sz = 4;
            else {
                i++; continue;
            }
        }
        else if ((text[i] & 0b11110000) == 0b11100000) {
            if (i+2 < text.size() && (text[i+1] & 0b11000000) == 0b10000000 && (text[i+2] & 0b11000000) == 0b10000000)
                char_sz = 3;    
            else {
                i++; continue;
            }
        }
        else if ((text[i] & 0b11100000) == 0b11000000) {
            if (i+1 < text.size() && (text[i+1] & 0b11000000) == 0b10000000)
                char_sz = 2;
            else {
                i++;
                continue;
            }
        }
        else if ((text[i] & 0b10000000) == 0b00000000) char_sz = 1;
        else {
            i++; continue;
        }

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

void TfidfVectorizer::fit(const std::vector<std::string>& text_list) {
    std::string punctuation = u8"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n";
    std::vector<std::string> punc_vec = split(punctuation, {}, false);
    bool word_unit = 1;
    if (analyzer == "char") word_unit = 0;
    for (const std::string& text : text_list) {
        std::vector<std::string> parsed_text = split(text, punc_vec, word_unit);
        std::map<std::string, int> word_count;
        for (int ngram = ngram_range.first; ngram <= ngram_range.second; ngram++) {
            for (int i = 0; i < parsed_text.size() - ngram + 1; i++) {
                std::string word;
                for (int j = 0; j < ngram; j++) {
                    word += parsed_text[i + j];
                    if (j != ngram - 1) word += u8" ";
                }
                word_count[word]++;
                df[word]++;
            }
        }
        tf.push_back(word_count);
    }
    if (min_df != -1) {
        std::set<std::string> st;
        for (auto i : df) if (i.second < min_df) st.insert(i.first);
        for (auto i : st) df.erase(i);
        for (int i = 0; i < tf.size(); i++) {
            for (auto j : st) if (tf[i].find(j) != tf[i].end()) tf[i].erase(j);
        }
    }
    if (max_features != -1) {
        std::priority_queue<std::pair<int, std::string>> pq;
        for (auto i : df) {
            pq.push({i.second, i.first});
            if (pq.size() > max_features) pq.pop();
        }
        df.clear();
        while(pq.size()) {
            auto i = pq.top(); pq.pop();
            df[i.second] = i.first;
        }
        for (int i = 0; i < tf.size(); i++) {
            for (auto j : df) if (tf[i].find(j.first) != tf[i].end()) tf[i].erase(j.first);
        }
    }
}

std::vector<std::vector<double>> TfidfVectorizer::transform() {
    std::vector<std::vector<double>> ret;
    for (int i = 0; i < tf.size(); i++) {
        std::vector<double> tmp;
        for (auto j : df) {
            if (tf[i].find(j.first) == tf[i].end()) tmp.push_back(0);
            else {
                double idf = log((double)tf.size() / (j.second + 1));
                tmp.push_back(tf[i][j.first] * idf);
            }
        }
        ret.push_back(tmp);
    }
    return ret;
}

std::map<std::string, int> TfidfVectorizer::get_df() const {
    return df;
}

std::vector<std::map<std::string, int>> TfidfVectorizer::get_tf() const {
    return tf;
}