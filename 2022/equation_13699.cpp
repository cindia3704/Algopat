/*
    작성자: 김지수
    작성일: 2022/09/05
    백준 -- 점화식 (13699번)
*/

#include <iostream>
#include <cstring>
#define MAX 36
using namespace std;
long long cache[MAX];

long long func(int n){
    long long &ret = cache[n];
    if(n==0){
        return 1;
    }
    if(ret!=-1){
        return ret;
    }else{
        ret =0;
        for(int i=0;i<n;i++){
            ret+=func(i)*func(n-1-i);
        }
    }
    return ret;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    memset(cache,-1,sizeof(cache));
    cout<<func(n);

}