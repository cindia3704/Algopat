/*
    작성자: 김지수
    작성일: 2022/07/27
    백준 -- 애너그램 (6443번)
*/

#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std; 
int leftAlpha[26];
int pick[MAX];

void makeComb(int pickCount, int target){
    if(pickCount == target){
        for(int i=0;i<pickCount;i++){
            cout<<(char)(pick[i]+'a');
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<26;i++){
        if(leftAlpha[i]>0){
            leftAlpha[i]-=1;
            pick[pickCount] = i;
            makeComb(pickCount+1,target);
            leftAlpha[i]+=1;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);    
    cin.tie(0);

    int wordCnt;
    cin>>wordCnt;
    for(int i=0;i<wordCnt;i++){
        memset(leftAlpha,0,sizeof(leftAlpha));
        string word; 
        cin>>word;
        for(int j=0;j<word.length();j++){
            leftAlpha[word[j]-'a']++;
        }
        makeComb(0,word.length());
    }
}