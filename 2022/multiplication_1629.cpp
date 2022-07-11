/*
    작성자: 김지수
    작성일: 2022/07/12
    백준 -- 곱셈 (1629번)
*/

#include <iostream>
#define ll long long
using namespace std; 

ll a,b,c;

ll multiply(ll baseNum, ll exNum, ll modNum){
    if(exNum ==1){
        return baseNum%modNum;
    }else{
        ll temp = multiply(baseNum,exNum/2,modNum);
        temp = ((temp%modNum) * (temp%modNum))%modNum;
        if(exNum %2 == 0){
            return temp;
        }else{
            return ((temp%modNum) * (a%modNum))%modNum;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c; 
    
    cout<<multiply(a,b,c);
      
}