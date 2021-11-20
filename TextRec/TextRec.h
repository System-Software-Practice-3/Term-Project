#ifndef Text2Vec_H
#define Text2Vec_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#include <kiwi/Utils.h>
#include <kiwi/Kiwi.h>

#include "../Knn/Knn.h"
#include "../ItemRec.cc"

namespace cbr {
    const std::string MODEL_PATH = "/home/ssw3-team2/Kiwi/ModelGenerator"; //must absolute path

    std::vector<std::string> split(const std::string& text, std::vector<std::string> seperators, bool word_unit=true);

    class TfidfVectorizer {
    private:
        int max_features;
        int min_df;
        std::pair<int, int> ngram_range;
        std::map<std::u16string, int> df;
        std::vector<std::map<std::u16string, int>> tf;

    public:
        TfidfVectorizer();
        TfidfVectorizer(int _max_features);

        void set_configs(const std::vector<std::pair<std::string, std::string>>& config);
        void fit(const std::vector<std::u16string>& text_list);
        void fit(const std::vector<std::string>& text_list);
        std::vector<std::vector<double>> transform();
        std::map<std::u16string, int> get_df() const;
        std::vector<std::map<std::u16string, int>> get_tf() const;
    };

    class TextRec : public ItemRec<std::u16string> {
    private:
        std::vector<std::u16string> text_list;
        std::vector<std::vector<double>> vectorized_text_list;
        std::vector<std::set<std::string>> text_set_list; //for jaccard similarity
        std::vector<std::pair<std::string, std::string>> configs;
        std::string policy;

    public:
        void AddData(const std::string& text);
        void AddData(const std::u16string& text) override;
        void Build(std::string policy="tf-idf") override;
        void SetConfig(const std::vector<std::pair<std::string, std::string>>& config) override;
        void ResetConfig();
        void ResetData();
        void GetRankingList(int id, int k, std::vector<int>& result) override;
        void GetRankingList(int id, int k, std::vector<std::pair<int, double>>& result) override;
    };
}

#endif