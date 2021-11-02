#ifndef Ensemble_H
#define Ensemble_H

#include <string>
#include <vector>
#include <utility>


class Ensemble {
private:
    std::vector<std::vector<int>> ranking_list;
    std::vector<std::vector<std::pair<int, double>>> ranking_list_with_weight;
    void RankFusion(std::vector<int>& result);
    void Hard_Voting(std::vector<int>& result);
    void Soft_Voting(std::vector<int>& result);

public:
    Ensemble();
    void AddRanking(std::vector<int> ranking);
    void AddRanking(std::vector<std::pair<int, double>> ranking);
    void GetResult(int k, std::string policy, std::vector<int>& result);
};

#endif
