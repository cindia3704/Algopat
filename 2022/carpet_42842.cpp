/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 카펫 (42842번)
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i=1;i<=yellow;i++){
        if(yellow%i==0){
            int yellowH = i;
            int yellowW = yellow/i;
            int h = yellowH+2;
            int w= yellowW+2; 
           
            if(h>=w  && 2*h+2*w-4 == brown){
                answer.push_back(h);
                answer.push_back(w);
                break;
            }
        }
    }
    return answer;
}