#include <iostream>
#include <locale>
#include "Text2Vec.h"
using namespace std;

int main(){
    // Text2Vec_Test.cc file should be encoded by utf-8
    string text = u8"이 글은 ★Test★를 위한 글입니다. 잘 읽힐까요?";
    cout << text << '\n';

    TfidfVectorizer tfidf;
    vector<string> v = tfidf.split(text, {u8" ", u8"\n", u8"\n", u8".", u8",", u8"?"});
    for (string i : v) cout << i << '\n';
    vector<string> v2 = tfidf.split(text, {u8" ", u8"\n", u8"\n", u8".", u8",", u8"?"}, false);
    for (string i : v2) cout << i << ' ';
    cout<<'\n';

    tfidf.set_configs({{"ngram_range", "{1, 2}"}});
    string textli[4] = {u8"먹고 싶은 <사과>", u8"먹고~ 싶은 바나나", u8"길고 노란 바나나, 바나나", u8"저는 과일이 좋아요!"};
    vector<string> text_list;
    for (int i = 0; i < 4; i++) text_list.push_back(textli[i]);
    tfidf.fit(text_list);
}