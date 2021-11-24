#ifndef Ensemble_H
#define Ensemble_H

#include <string>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

namespace cbr {
    class Ensemble {
    private:
        std::vector<std::vector<int>> ranking_list;
        std::vector<std::vector<std::pair<int, double>>> ranking_list_with_weight;
        void ReciprocalRankFusion(int k, std::vector<int>& result);
        void CombMNZ(int k, std::vector<int>& result);
        void CombSum(int k, std::vector<int>& result);

    public:
        Ensemble();
        void AddRanking(std::vector<int> ranking);
        void AddRanking(std::vector<std::pair<int, double>> ranking, bool is_similarity=false);
        void GetResult(int k, std::string policy, std::vector<int>& result);
    };
}

#endif
