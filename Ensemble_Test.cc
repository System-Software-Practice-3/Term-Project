#include <iostream>
#include <vector>
#include "Ensemble.h"
using namespace std;

int main(){
    Ensemble en;
    en.AddRanking({1, 4, 2, 3, 7, 6, 5});
    en.AddRanking({2, 3, 1, 4, 6, 5, 7});
    en.AddRanking({1, 4, 2, 5, 3, 6, 7});
    vector<int> res(7);
    en.GetResult(7, "RRF", res);

    cout << "RRF ranking : ";
    for (int i : res) cout << i << ' ';
    cout<<'\n';
}