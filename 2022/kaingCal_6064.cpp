/*
    작성자: 김지수
    작성일: 2022/08/22
    백준 -- 카잉 달력 (6064번)
*/

#include <iostream>
#define MAX 40001
using namespace std; 
int m,n,x,y;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; 
    cin>>tc; 
    while(tc--){
        long long ans = -2; 
        cin>>m>>n>>x>>y;
        x--;
        y--;
        for(int i=0;i<=n;i++){
            long long year = i*m+x;
            if(year%n ==y){
                ans = year; 
                break;
            }
        }
        cout<<ans+1<<'\n';
    }
}