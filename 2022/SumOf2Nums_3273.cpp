/*
    작성자: 김지수
    작성일: 2022/06/12
    백준 -- 두 수의 합 (3273번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 2000001
using namespace std; 

vector<int> seq;
int isIncluded[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,target;
    cin>>n;
    memset(isIncluded,0,sizeof(isIncluded));

    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        seq.push_back(num);
        isIncluded[num]++;
    }
    cin>>target;
    sort(seq.begin(),seq.end());

    int ans = 0;
   for(int i=0;i<n;i++){
       int diff = target - seq[i];
       if(diff<=0){
           continue;
       }
       if(isIncluded[diff]>0 && diff>0 && diff!=seq[i]){
           ans++;
       }
    }

    cout<<ans/2;

}