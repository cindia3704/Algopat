/*
    작성자: 김지수
    작성일: 2022/09/24
    프로그래머스 -- 야근 지수 (12927번)
*/

#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> w;
    for(int i=0;i<works.size();i++){
        w.push(works[i]);
    }
    long long answer = 0;
    for(int i=0;i<n;i++){
        if(!w.empty()){
            int now = w.top();
            w.pop();
            now--;
            if(now>0){
                w.push(now);
            }
        }
    }
    
    while(!w.empty()){
        int now = w.top();
        w.pop();
        answer+=pow(now,2);
    }
    return answer;
}