/*
    작성자: 김지수
    작성일: 2022/09/11
    프로그래머스 -- 이진 변환 반복하기 (70129번)
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int zeroCnt;
int stageCnt;

using namespace std;

string convert(int num){
    string ret = "";
    while(num>1){
        int mod = num%2;
        ret+=to_string(mod);
        num/=2;
    }
    ret+=to_string(num);
    reverse(ret.begin(),ret.end());
    return ret;
}

void startGame(string s){
    while(true){
        stageCnt++;
        int len = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]!='0'){
                len++;
            }else{
                zeroCnt++;
            }
        }
        s = convert(len);
        if(s.length()==1 && s[0]=='1'){
            break;
        }
    }
}


vector<int> solution(string s) {
    vector<int> answer;
    startGame(s);
    answer.push_back(stageCnt);
    answer.push_back(zeroCnt);
    return answer;
}