#include <iostream>
#include <locale>
#include "TextRec.h"
using namespace std;

int main(){
    // TextRec_Test.cc file should be encoded by utf-8
    // C++11
    u16string text = u"이 글은 ★Test★를 위한 글입니다. 잘 읽힐까요?";
    cout << kiwi::utf16To8(text) << '\n';
    kiwi::Kiwi kiwi = kiwi::KiwiBuilder(cbr::MODEL_PATH).build();
    auto res = kiwi.analyze(text, kiwi::Match::all);
    std::cout << res.first.size() << '\n';
    for (auto i : res.first) cout << kiwi::utf16To8(i.str) << ' ';
    cout<<'\n';

    cbr::TfidfVectorizer tfidf;

    // tfidf.set_configs({{"min_df", "2"}});
    u16string textli[4] = {u"먹고 싶은 <사과>", u"먹고~ 싶은 바나나", u"길고 노란 바나나, 바나나", u"저는 과일이 좋아요!"};
    vector<u16string> text_list;
    for (int i = 0; i < 4; i++) {
        text_list.push_back(textli[i]);
        auto parsed = kiwi.analyze(textli[i], kiwi::Match::all);
        for (auto i : parsed.first) cout << kiwi::utf16To8(i.str) << ' ';
        cout<<'\n';     
    }
    tfidf.fit(text_list);
    
    vector<vector<double>> text_vec = tfidf.transform();
    map<u16string, int> df = tfidf.get_df();
    for (auto i : df) cout << kiwi::utf16To8(i.first) << ' ';
    cout<<'\n';
    for (auto i : text_vec) {
        for (double j : i) cout << j << ' ';
        cout<<'\n';
    }

    vector<u16string> text_list2{u"사과나 바나나를 먹고 싶다", u"사과는 싫지만 복숭아는 좋다", u"노는게 제일 좋아 친구들 모여라", u"배고파서 아무거나 먹고 싶다"};

    cout << "TF-IDF Test\n";
    cbr::TextRec tr;
    for (auto i : text_list2) tr.AddData(i);
    tr.Build();
    vector<pair<int, double>> result;
    tr.GetRankingList(0, 3, result);
    cout << kiwi::utf16To8(text_list2[0]) << " is similar to...\n";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << (i + 1) << ' ' << kiwi::utf16To8(text_list2[result[i].first]) << ", score : " << result[i].second << '\n';
    }

    cout << "Jaccard Test\n";
    tr.ResetData();
    for (auto i : text_list2) tr.AddData(i);
    tr.Build("jaccard");
    result.clear();
    tr.GetRankingList(0, 3, result);
    cout << kiwi::utf16To8(text_list2[0]) << " is similar to...\n";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << (i + 1) << ' ' << kiwi::utf16To8(text_list2[result[i].first]) << ", score : " << result[i].second << '\n';
    }
}