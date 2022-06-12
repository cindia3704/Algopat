/*
    작성자: 김지수
    작성일: 2022/06/12
    백준 -- 알파벳 개수 (10808번)
*/

#include <iostream>
#include <cstring>
#define ALPHA 26
using namespace std; 
int alphaCount[ALPHA];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(alphaCount,0,sizeof(alphaCount));
    string word;
    cin>>word;

    for(int i=0;i<word.length();i++){
        alphaCount[word[i]-'a']++;
    }

    for(int i=0;i<ALPHA;i++){
        cout<<alphaCount[i]<<" ";
    }

}