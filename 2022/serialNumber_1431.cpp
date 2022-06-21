/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 시리얼 번호 (1431번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct SER{
    int serialLen,serialSum;
    string serial;
};
vector<SER> serials; 

bool cmpSerial(SER &a, SER &b){
    if(a.serialLen==b.serialLen){
        if(a.serialSum==b.serialSum){
            return a.serial < b.serial;
        }else{
            return a.serialSum<b.serialSum;
        }
    }else{
        return a.serialLen <b.serialLen;
    }
}

int getSum(string s){
    int sum = 0;
    for(int i=0;i<s.length();i++){
        int diff = s[i] - '0';
        if(diff>=0 && diff<=9){
            sum+=diff;
        }
    }
    return sum; 
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int serialCount; 
    cin>>serialCount;
    for(int i=0;i<serialCount;i++){
        SER now; 
        cin>>now.serial;
        now.serialLen = now.serial.length();
        now.serialSum = getSum(now.serial);
        serials.push_back(now);
    }

    sort(serials.begin(),serials.end(),cmpSerial);
    for(int i=0;i<serials.size();i++){
        cout<<serials[i].serial<<'\n';
    }
}