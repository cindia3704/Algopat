/*
    작성자: 김지수
    작성일: 2022/08/19
    백준 -- 골드바흐의 추측 (6588번)
*/

#include <iostream>
#include <cstring>
#define MAX 1000001
using namespace std; 
bool cache[MAX];

pair<int,int> findAns(int n){
    for(int i=3;i<=n;i++){
        if(!cache[i] && !cache[n-i]){
            return make_pair(i,n-i);
        }
    }
    return make_pair(-1,-1);
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(cache,false,sizeof(cache));
    cache[1] = true; 
    for(int i=2;i<MAX;i++){
        if(!cache[i]){
            for(int j=2;j*i<MAX;j++){
                cache[j*i] = true; 
            }
        }
    }

    int n;
    cin>>n;
    while(true){
        if(n==0){
            break;
        }
        pair<int,int> found = findAns(n);
        if(found.first==-1){
            cout<<"Goldbach's conjecture is wrong."<<'\n';
        }else{
            cout<<n<<" = "<<found.first<<" + "<<found.second<<'\n';
        }
        cin>>n;
    }

}