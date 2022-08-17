/*
    작성자: 김지수
    작성일: 2022/08/18
    백준 -- 나머지 (10430번)
*/

#include <iostream>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int A,B,C; 
    cin>>A>>B>>C;
    cout<<(A+B)%C<<'\n';
    cout<<((A%C) + (B%C))%C<<'\n';
    cout<<(A*B)%C<<'\n';
    cout<<((A%C) * (B%C))%C<<'\n';
}