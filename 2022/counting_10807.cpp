/*
    작성자: 김지수
    작성일: 2022/06/13
    백준 -- 개수 세기 (10807번)
*/

#include <iostream>
#include <cstring>
#define MAX 202

using namespace std; 
int freq[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(freq,0,sizeof(freq));
    int n,v;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        freq[num+101]++;
    }
    cin>>v;
    cout<<freq[v+101];

}