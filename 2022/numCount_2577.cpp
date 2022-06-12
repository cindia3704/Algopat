/*
    작성자: 김지수
    작성일: 2022/06/12
    백준 -- 숫자의 개수 (2577번)
*/

#include <iostream>
#include <cstring>
using namespace std; 
int useCount[10];


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;
    cin>>a>>b>>c; 
    memset(useCount,0,sizeof(useCount));

    long long result; 
    result = a*b*c; 
    
    string number = to_string(result);
    for(int i=0;i<number.length();i++){
        useCount[number[i]-'0']++;
    }
    for(int i=0;i<10;i++){
        cout<<useCount[i]<<'\n';
    }
}