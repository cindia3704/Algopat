/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 최고의 집합 (12938번)
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n<1){
        answer.push_back(-1);
    }else{
        for(int i=n;i>=1;i--){
            int num = s/i;
            s-=num;
            answer.push_back(num);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}