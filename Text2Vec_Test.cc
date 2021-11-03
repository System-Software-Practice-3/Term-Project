#include <iostream>
#include <locale>
#include "Text2Vec.h"
using namespace std;

int main(){
    // Text2Vec_Test.cc file should be encoded by utf-8
    string text = u8"이 글은 Test를 위한 글입니다. 잘 읽힐까요?";
    cout << text << '\n';

    TfidfVectorizer tfidf;
    vector<string> v = tfidf.split(text, {u8" ", u8"\n", u8"\n", u8".", u8",", u8"?"});
    for (string i : v) cout << i << '\n';
    vector<string> v2 = tfidf.split(text, {u8" ", u8"\n", u8"\n", u8".", u8",", u8"?"}, false);
    for (string i : v2) cout << i << ' ';
    cout<<'\n';
}