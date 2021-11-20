#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <locale>
#include <kiwi/Kiwi.h>

#include "TextRec/TextRec.h"
#include "RankFusion/RankFusion.h"
using namespace std;

const string BOOK_PATH = "/home/ssw3-team2/book_text"; //absolute path
const int MAX_BOOK = 100;

int main(){
    cbr::TextRec tr;
    ifstream metafin(BOOK_PATH + "/metadata.txt");
    istreambuf_iterator<char> begin(metafin), end;
    string meta = string(begin, end);
    vector<string> titles = cbr::split(meta, {u8","});

    for (int i = 0; i < MAX_BOOK; i++) {
        ifstream fin(BOOK_PATH + "/" + to_string(i+1) + ".txt");
        istreambuf_iterator<char> begin(fin), end;
        tr.AddData(kiwi::utf8To16(string(begin, end)));
        fin.close();
    }

    int target; cin>>target;
    cout << titles[target - 1] << '\n';
    vector<pair<int, double>> result1, result2;
    vector<int> final_result;

    tr.SetConfig({{"ngram_range", "{1, 2}"}});
    tr.Build("tf-idf");
    tr.GetRankingList(target - 1, 20, result1);

    tr.Build("jaccard");
    tr.GetRankingList(target - 1, 20, result2);
    
    cout << "tf-idf\n";
    for (int i = 0; i < 20; i++) {
        int idx = result1[i].first;
        cout << i + 1 << ". ";
        cout << titles[idx] << ' ' << idx + 1  << ' ' << result1[i].second << '\n';
    }

   cout << "jaccard\n";
    for (int i = 0; i < 20; i++) {
        int idx = result2[i].first;
        cout << i + 1 << ". ";
        cout << titles[idx] << ' ' << idx + 1  << ' ' << result2[i].second << '\n';
    }

    cbr::RankFusion en;
    en.AddRanking(result1);
    en.AddRanking(result2);
    en.GetResult(20, "CombSum", final_result);

    cout << "RankFusion Result : \n";
    for (int i = 0; i < 20; i++) {
        int idx = final_result[i];
        cout << i + 1 << ". ";
        cout << titles[idx] << ' ' << idx + 1  << '\n';
    }

    return 0;
}