/*
    작성자: 김지수
    작성일: 2022/06/12
    백준 -- 방번호 (1475번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std; 

int useCount[10];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string roomNum; 
    cin>>roomNum;
    memset(useCount,0,sizeof(useCount));
    int setNum = 0;
    for(int i=0;i<roomNum.length();i++){
        int idx = roomNum[i] - '0';
        if(idx == 6 || idx == 9){
            if(useCount[6]+useCount[9]>=2*setNum){
                setNum++;
            }
            useCount[idx]++;
        }else{
            if(useCount[idx]>=setNum){
                setNum++;
            }   
            useCount[idx]++;
        }
            
    } 
    cout<<setNum;
}