/*
    작성자: 김지수
    작성일: 2022/06/13
    백준 -- 애너그램 만들기 (1919번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define ALPHA 26
using namespace std; 

int freq1[ALPHA];
int freq2[ALPHA];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(freq1,0,sizeof(freq1));
    memset(freq2,0,sizeof(freq2));

    string a,b;
    cin>>a>>b;
    // 각각 알파벳 개수 알아내기 
    for(int i=0;i<a.length();i++){
        freq1[a[i]-'a']++;
    }
    for(int i=0;i<b.length();i++){
        freq2[b[i]-'a']++;
    }

    // 각 알파벳 차이가 빼야하는 알파벳 개수 
    int count=0;
    for(int i=0;i<ALPHA;i++){
        count+=abs(freq1[i]-freq2[i]); 
    }
    cout<<count;


}