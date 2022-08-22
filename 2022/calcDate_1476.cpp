/*
    작성자: 김지수
    작성일: 2022/08/22
    백준 -- 날짜 계산 (1476번)
*/

#include <iostream>
using namespace std; 
int E = 15; 
int S=28;
int M = 19; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int e,s,m;
    cin>>e>>s>>m;

    int e1=1,s1=1,m1=1;
    int ans = 1; 

    while(true){
        // 주어진 ems와 같으면 그것이 정답 
        if(e1==e && s1==s && m1==m){
            cout<<ans;
            break;
        }
        ans++;
        e1++;
        s1++;
        m1++;
        
        if(e1>E){
            e1=1;
        }
        if(s1>S){
            s1=1;
        }
        if(m1>M){
            m1=1;
        }
    }
}