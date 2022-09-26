/*
    작성자: 김지수
    작성일: 2022/09/26
    백준 -- 단어의 개수 (1152번)
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string para; 
    getline(cin,para);

    int wordCnt=0;
    char words[para.length()+1];
    strcpy(words,para.c_str());
    char *p = strtok(words," ");
    while(p!=NULL){
        wordCnt++;
        p=strtok(NULL, " ");
    }
    cout<<wordCnt;
}