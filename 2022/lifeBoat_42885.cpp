/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 구명보트 (42885번)
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 241

using namespace std;
int weights[MAX];
int solution(vector<int> people, int limit) {
    int answer = 0;
    for(int i=0;i<people.size();i++){
        weights[people[i]]++;
    }
    
    for(int i=0;i<people.size();i++){
        int nowSum =0;
        int nowWeight = people[i];
        if(weights[nowWeight]){
            weights[nowWeight]--;
            nowSum +=nowWeight;
            int left = limit - nowWeight;
            int next = left;
            while(next>0){
                if(weights[next]){
                    if(nowSum+next>limit){
                        break;
                    }else{
                        nowSum+=next;
                        weights[next]--;
                        left-=next;
                        break;
                    }
                }
                if(left==0 || nowSum==limit){
                    break;
                }
                next--;
            }
            answer++;
        }
    }
    return answer;
}