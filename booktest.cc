#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <locale>
#include <kiwi/Kiwi.h>


#include "ImageRec/image2vec.h"
#include "ImageRec/kmeans.h"
#include "ImageRec/histogram.h"
#include "TagRec/TagRec.h"
#include "TextRec/TextRec.h"
#include "Ensemble/Ensemble.h"

using namespace std;
using namespace cbr;


const string BOOK_TEXT_PATH = "/home/ssw3-team2/book_text"; //absolute path
const std::string BOOK_TAG_PATH = "../book_tag/";


const int MAX_BOOK = 100;

int main(){
    cbr::TextRec tr;
    ifstream metafin(BOOK_TEXT_PATH + "/metadata.txt");
    istreambuf_iterator<char> begin(metafin), end;
    string meta = string(begin, end);
    vector<string> titles = cbr::split(meta, {u8","});

    for (int i = 0; i < MAX_BOOK; i++) {
        ifstream fin(BOOK_TEXT_PATH + "/" + to_string(i+1) + ".txt");
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
    tr.GetRankingList(target - 1, MAX_BOOK, result1);

    tr.Build("jaccard");
    tr.GetRankingList(target - 1, MAX_BOOK, result2);

////////////////////////
    std::ifstream TAG_ifs;
    std::string TAG_str;
    cbr::TagRec tag;
    std::vector<std::pair<int, double>> result3;


    for(int i = 1;i<=100;i++){
        TAG_ifs.open(BOOK_TAG_PATH + std::to_string(i) + ".csv");
        getline(TAG_ifs, TAG_str);
        tag.AddData(tag.split(TAG_str));
        TAG_ifs.close();
    }

    tag.GetRankingList(target-1, MAX_BOOK, result3);
//////////////////////////////
    std::vector<std::pair<int, double>> result4;
    ImageRec analyze_histogram = ImageRec(1,5); // second arg is cluster number and we fix  it 5
    for (int i = 1; i <= MAX_BOOK; i++){
        char tmp[50];
        sprintf(tmp, "/home/ssw3-team2/book_imgs/%d.jpg",i);
        std::string str="";
        for (int j = 0; ;j++){
            if(tmp[j]=='\0') break;
            str += tmp[j];
        }
       // analyze_kmeans.AddData(str);
        analyze_histogram.AddData(str);
    }
    analyze_histogram.GetRankingList(target,MAX_BOOK,result4); 
    //

    //under seal kmens.. if you want to check kmeans result remove this commend and 107line.
    /*
    std::vector<std::pair<int, double>> result5;
    ImageRec analyze_kmeans = ImageRec(0,5); // second arg is cluster number and we fix  it 5
    for (int i = 1; i <= MAX_BOOK; i++){
        char tmp[50];
        sprintf(tmp, "/home/ssw3-team2/book_imgs/%d.jpg",i);
        std::string str="";
        for (int j = 0; ;j++){
            if(tmp[j]=='\0') break;
            str += tmp[j];
        }
        analyze_kmeans.AddData(str); 
    }
    analyze_kmeans.GetRankingList(target,MAX_BOOK,result5);
    */
////////////
    cbr::Ensemble en;
    en.AddRanking(result1);
    en.AddRanking(result2);
    en.AddRanking(result3);
    en.AddRanking(result4);
    //en.AddRanking(result5);


    en.GetResult(20, "CombSum", final_result);



    cout << "Ensemble Result : \n";
    for (int i = 0; i < 20; i++) {
        int idx = final_result[i];
        cout << i + 1 << ". ";
        cout << titles[idx] << ' ' << idx + 1  << '\n';
    }

    return 0;
}