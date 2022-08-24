/*
    작성자: 김지수
    작성일: 2022/08/24
    백준 -- 수 이어 쓰기 1 (1748번)
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string n;
    cin>>n;
    int numLength=0;
    int nLength = n.length();
    int numN = stoi(n);
    if(nLength>1){
        for(int i=0;i<=nLength-2;i++){
            numLength+=(9*pow(10,i))*(i+1);
        }
    }
    numLength+=(numN - pow(10,nLength-1)+1)*nLength;
    cout<<numLength;
     
}