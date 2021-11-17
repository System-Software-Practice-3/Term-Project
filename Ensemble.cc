#include "Ensemble.h"
#include <iostream>

cbr::Ensemble::Ensemble() : ranking_list(), ranking_list_with_weight() {}

void cbr::Ensemble::AddRanking(std::vector<int> ranking) {
    ranking_list.push_back(ranking);
}

void cbr::Ensemble::AddRanking(std::vector<std::pair<int, double>> ranking, bool is_similarity) {
    if (is_similarity) ranking_list_with_weight.push_back(ranking);
    else {
        for (auto &i : ranking) {
            i.second = 1.0 / (2 + i.second);
        }
        ranking_list_with_weight.push_back(ranking);
    }
}

void cbr::Ensemble::GetResult(int k, std::string policy, std::vector<int>& result) {
    if (policy == "RRF") ReciprocalRankFusion(k, result);
    else if (policy == "CombMNZ") CombMNZ(k, result);
    else if (policy == "CombSum") CombSum(k, result);
}

void cbr::Ensemble::ReciprocalRankFusion(int k, std::vector<int>& result) {
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

void cbr::Ensemble::CombMNZ(int k, std::vector<int>& result) {
    const int K = 60;
    std::map<int, double> sim_score;
    std::map<int, int> num_nonzero_score;
    for (const auto& ranking : ranking_list_with_weight) {
        for (const auto& i : ranking) {
            sim_score[i.first] += (i.second - ranking.back().second) / (ranking[0].second - ranking.back().second);
            if (i.second != ranking.back().second) num_nonzero_score[i.first]++;
        }
    }
    for (const auto& ranking : ranking_list) {
        double max_sim = 1.0 / K, min_sim = 1.0 / (K + ranking.size() - 1);
        for (int i = 0; i < (int)ranking.size(); i++) {
            sim_score[ranking[i]] += (1.0 / (K + i) - min_sim) / (max_sim - min_sim);
            if (1.0 / (K + i) != min_sim) num_nonzero_score[ranking[i]]++;
        }
    }
    
    std::vector<std::pair<double, int>> csum_res;
    for (auto s : sim_score) csum_res.push_back({s.second * num_nonzero_score[s.first], s.first});
    std::sort(csum_res.rbegin(), csum_res.rend());
    result.resize(k);
    for (int i = 0; i < k; i++) {
        if (i < (int)csum_res.size()) result[i] = csum_res[i].second;
        else result[i] = -1;
    }
}

void cbr::Ensemble::CombSum(int k, std::vector<int>& result) {
    const int K = 60;
    std::map<int, double> sim_score;
    for (const auto& ranking : ranking_list_with_weight) {
        for (const auto& i : ranking) {
            sim_score[i.first] += (i.second - ranking.back().second) / (ranking[0].second - ranking.back().second);
        }
    }
    for (const auto& ranking : ranking_list) {
        double max_sim = 1.0 / K, min_sim = 1.0 / (K + ranking.size() - 1);
        for (int i = 0; i < (int)ranking.size(); i++) {
            sim_score[ranking[i]] += (1.0 / (K + i) - min_sim) / (max_sim - min_sim);
        }
    }

    std::vector<std::pair<double, int>> csum_res;
    for (auto s : sim_score) csum_res.push_back({s.second, s.first});
    std::sort(csum_res.rbegin(), csum_res.rend());
    result.resize(k);
    for (int i = 0; i < k; i++) {
        if (i < (int)csum_res.size()) result[i] = csum_res[i].second;
        else result[i] = -1;
    }
}