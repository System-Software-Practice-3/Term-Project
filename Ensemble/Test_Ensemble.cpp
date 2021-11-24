#include <iostream>
#include <vector>
#include "Ensemble.h"
using namespace std;

int main(){
    cbr::Ensemble en;
    en.AddRanking({1, 4, 2, 3, 7, 6, 5});
    en.AddRanking({2, 3, 1, 4, 6, 5, 7});
    en.AddRanking({1, 4, 2, 5, 3, 6, 7});
    vector<int> res(7);
    en.GetResult(7, "RRF", res);

    cout << "RRF ranking : ";
    for (int i : res) cout << i << ' ';
    cout << '\n';

    en.AddRanking({{1, 0.8}, {2, 0.5}, {5, 0.45}, {4, 0.44}, {3, 0.41}, {6, 0.21}, {7, 0.11}});
    en.AddRanking({{4, 0.02}, {1, 0.05}, {6, 0.1}, {3, 0.2}, {5, 1}, {2, 4}, {7, 5.6}}, true);

    en.GetResult(7, "CombSum", res);
    cout << "CombSum ranking: ";
    for (int i : res) cout << i << ' ';
    cout << '\n';

    en.GetResult(7, "CombMNZ", res);
    cout << "CombMNZ ranking: ";
    for (int i : res) cout << i << ' ';
    cout << '\n';
}