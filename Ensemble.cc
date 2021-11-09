#include "Ensemble.h"
#include <iostream>

Ensemble::Ensemble() : ranking_list(), ranking_list_with_weight() {}

void Ensemble::AddRanking(std::vector<int> ranking) {
    ranking_list.push_back(ranking);
}

void Ensemble::AddRanking(std::vector<std::pair<int, double>> ranking) {
    ranking_list_with_weight.push_back(ranking);
}

void Ensemble::GetResult(int k, std::string policy, std::vector<int>& result) {
    if (policy == "RRF") ReciprocalRankFusion(k, result);
}

void Ensemble::ReciprocalRankFusion(int k, std::vector<int>& result) {
    const int K = 60; //K=60은 선행연구에서 정해진 값
    std::map<int, double> rrf_score;
    for (auto ranking : ranking_list) {
        for (int i = 0; i < (int)ranking.size(); i++) {
            rrf_score[ranking[i]] += 1.0 / (K + i);
        }
    }
    for (auto ranking : ranking_list_with_weight) {
        for (int i = 0; i < (int)ranking.size(); i++) {
            rrf_score[ranking[i].first] += 1.0 / (K + i);
        }
    }
    std::vector<std::pair<double, int>> rrf_res;
    for (auto s : rrf_score) rrf_res.push_back({s.second, s.first});
    std::sort(rrf_res.rbegin(), rrf_res.rend());
    result.resize(k);
    for (int i = 0; i < k; i++) {
        if (i < (int)rrf_res.size()) result[i] = rrf_res[i].second;
        else result[i] = -1;
    }
}