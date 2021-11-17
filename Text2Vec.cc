#include "Text2Vec.h"
#include <iostream>


cbr::TfidfVectorizer::TfidfVectorizer() : max_features(-1), min_df(-1), ngram_range(std::pair<int, int>(1, 1)) {}

std::vector<std::string> cbr::split(const std::string& text, std::vector<std::string> seperators, bool word_unit) {
    std::vector<std::string> ret;
    std::string tmp;
    int i = 0;
    while (i < (int)text.size()) {
        int char_sz = 0;

        if ((text[i] & 0b11111000) == 0b11110000) {
            if (i+3 < (int)text.size() && (text[i+1] & 0b11000000) == 0b10000000 && (text[i+2] & 0b11000000) == 0b10000000 && (text[i+3] & 0b11000000) == 0b10000000)
                char_sz = 4;
            else {
                i++; continue;
            }
        }
        else if ((text[i] & 0b11110000) == 0b11100000) {
            if (i+2 < (int)text.size() && (text[i+1] & 0b11000000) == 0b10000000 && (text[i+2] & 0b11000000) == 0b10000000)
                char_sz = 3;    
            else {
                i++; continue;
            }
        }
        else if ((text[i] & 0b11100000) == 0b11000000) {
            if (i+1 < (int)text.size() && (text[i+1] & 0b11000000) == 0b10000000)
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

std::u16string cbr::filter(const std::u16string& s, const std::vector<std::string>& seperators) {
    std::string text = kiwi::utf16To8(s);
    std::string ret, tmp;
    int i = 0;
    while (i < (int)text.size()) {
        int char_sz = 0;

        if ((text[i] & 0b11111000) == 0b11110000) {
            if (i+3 < (int)text.size() && (text[i+1] & 0b11000000) == 0b10000000 && (text[i+2] & 0b11000000) == 0b10000000 && (text[i+3] & 0b11000000) == 0b10000000)
                char_sz = 4;
            else {
                i++; continue;
            }
        }
        else if ((text[i] & 0b11110000) == 0b11100000) {
            if (i+2 < (int)text.size() && (text[i+1] & 0b11000000) == 0b10000000 && (text[i+2] & 0b11000000) == 0b10000000)
                char_sz = 3;    
            else {
                i++; continue;
            }
        }
        else if ((text[i] & 0b11100000) == 0b11000000) {
            if (i+1 < (int)text.size() && (text[i+1] & 0b11000000) == 0b10000000)
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
        bool flag = 0;
        for (std::string sep : seperators) 
            if (str == sep) {
                flag = 1; break;
            }

        if (flag) {
            if (tmp.size()) {
                ret += tmp;
                ret += " ";
            }
            tmp.clear();
            continue;
        }

        tmp += str;
    }
    if (tmp.size()) ret += tmp;
    return kiwi::utf8To16(ret);
}

void cbr::TfidfVectorizer::set_configs(const std::vector<std::pair<std::string, std::string>>& config) {
    for (auto c : config) {
        if (c.first == "max_features") max_features = stoi(c.second);
        else if (c.first == "min_df") min_df = stoi(c.second);
        else if (c.first == "ngram_range") {
            std::vector<std::string> range = split(c.second, {"{", "}", ",", " "});
            ngram_range.first = stoi(range[0]);
            ngram_range.second = stoi(range[1]);
        }
    }
}

void cbr::TfidfVectorizer::fit(const std::vector<std::u16string>& text_list) {
    std::string punctuation = u8"!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ \t\n";
    std::vector<std::string> punc_vec = split(punctuation, {}, false);
    kiwi::Kiwi kiwi = kiwi::KiwiBuilder(MODEL_PATH).build();
    for (const std::u16string& text : text_list) {
        auto filtered_text = filter(text, punc_vec);
        auto parsed_text = kiwi.analyze(filtered_text, kiwi::Match::all).first;
        std::map<std::u16string, int> word_count;
        for (int ngram = ngram_range.first; ngram <= ngram_range.second; ngram++) {
            for (int i = 0; i < (int)parsed_text.size() - ngram + 1; i++) {
                std::u16string word;
                for (int j = 0; j < ngram; j++) {
                    word += parsed_text[i + j].str;
                    if (j != ngram - 1) word += u" ";
                }
                word_count[word]++;
                df[word]++;
            }
        }
        tf.push_back(word_count);
    }
    if (min_df != -1) {
        std::set<std::u16string> st;
        for (auto i : df) if (i.second < min_df) st.insert(i.first);
        for (auto i : st) df.erase(i);
        for (int i = 0; i < (int)tf.size(); i++) {
            for (auto j : st) if (tf[i].find(j) != tf[i].end()) tf[i].erase(j);
        }
    }
    if (max_features != -1) {
        std::priority_queue<std::pair<int, std::u16string>> pq;
        for (auto i : df) {
            pq.push({i.second, i.first});
            if ((int)pq.size() > max_features) pq.pop();
        }
        df.clear();
        while(pq.size()) {
            auto i = pq.top(); pq.pop();
            df[i.second] = i.first;
        }
        for (int i = 0; i < (int)tf.size(); i++) {
            for (auto j : df) if (tf[i].find(j.first) != tf[i].end()) tf[i].erase(j.first);
        }
    }
}

void cbr::TfidfVectorizer::fit(const std::vector<std::string>& text_list) {
    std::vector<std::u16string> text_list_u16;
    for (auto &s: text_list) {
        text_list_u16.push_back(kiwi::utf8To16(s));
    }
    fit(text_list_u16);
}

std::vector<std::vector<double>> cbr::TfidfVectorizer::transform() {
    std::vector<std::vector<double>> ret;
    for (int i = 0; i < (int)tf.size(); i++) {
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

std::map<std::u16string, int> cbr::TfidfVectorizer::get_df() const {
    return df;
}

std::vector<std::map<std::u16string, int>> cbr::TfidfVectorizer::get_tf() const {
    return tf;
}

void cbr::TextRec::AddData(const std::string& text) {
    text_list.push_back(kiwi::utf8To16(text));
}

void cbr::TextRec::AddData(const std::u16string& text) {
    text_list.push_back(text);
}

void cbr::TextRec::Build(std::string _policy) {
    policy = _policy;
    if (_policy == "tf-idf") {
        TfidfVectorizer tfidf;
        tfidf.set_configs(configs);
        tfidf.fit(text_list);
        vectorized_text_list = tfidf.transform();
    } else if (_policy == "jaccard") {
        TfidfVectorizer tfidf;
        tfidf.set_configs(configs);
        tfidf.fit(text_list);
        auto tf = tfidf.get_tf();
        for (const auto& i : tf) {
            std::set<std::string> tmp_st;
            for (const auto& j : i) tmp_st.insert(kiwi::utf16To8(j.first));
            text_set_list.push_back(tmp_st);
        }
    }
}

void cbr::TextRec::SetConfig(const std::vector<std::pair<std::string, std::string>>& config) {
    for (auto i : config) configs.push_back(i);
}

void cbr::TextRec::ResetConfig() {
    configs.clear();
}

void cbr::TextRec::ResetData() {
    text_list.clear();
    vectorized_text_list.clear();
    text_set_list.clear();
}

void cbr::TextRec::GetRankingList(int id, int k, std::vector<int>& result) {
    if (policy == "tf-idf") {
        Knn knn(vectorized_text_list[0].size(), "Cosine");
        for (auto i : vectorized_text_list) knn.AddData(i);
        std::vector<std::pair<int, double>> knn_res;
        knn.SearchById(id, k, 0, knn_res);
        for (auto i : knn_res) result.push_back(i.first);
    } else if (policy == "jaccard") {
        Knn knn(1, "Jaccard");
        for (auto i : text_set_list) knn.AddData(i);
        std::vector<std::pair<int, double>> knn_res;
        knn.SearchById(id, k, 1, knn_res);
        for (auto i : knn_res) result.push_back(i.first);
    }
}

void cbr::TextRec::GetRankingList(int id, int k, std::vector<std::pair<int, double>>& result) {
    if (policy == "tf-idf") {
        Knn knn(vectorized_text_list[0].size(), "Cosine");
        for (auto i : vectorized_text_list) knn.AddData(i);
        knn.SearchById(id, k, 0, result);
    } else if (policy == "jaccard") {
        Knn knn(1, "Jaccard");
        for (auto i : text_set_list) knn.AddData(i);
        knn.SearchById(id, k, 1, result);
    }
}
