/*
    작성자: 김지수
    작성일: 2022/09/07
    백준 -- A와 B 2 (12919번)
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool found = false;
string from,to;

void makeComb(string st){
    if(st.length()==from.length()){
        
        if(st.compare(from)==0){
                found = true;
        }
        return;
    }
   
        // 뒤집힌게 아니면 뒤에 A 추가 
        if(st[st.length()-1]=='A'){
            string tempA = st.substr(0,st.length()-1);
            makeComb(tempA);
        }

        // 뒤에 B 추가 후 뒤집음 
        string tempB = st;
        reverse(tempB.begin(),tempB.end());
        if(tempB[tempB.length()-1]=='B'){
            tempB =tempB.substr(0,tempB.length()-1);
            makeComb(tempB);
        }
    
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>from>>to;
    makeComb(to);
    cout<<found;
}