/*
    작성자: 김지수
    작성일: 2022/09/24
    프로그래머스 -- n^2 배열 자르기 (87390번)
*/

#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#define MAX 10000001
using namespace std;

const int dy[3] = {0,1,1};
const int dx[3] = {1,1,0};

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int startNum = (left/n)+1;
    int startIdx = left%n;
    int endNum = (right/n)+1;
    int endIdx=right%n;
    //cout<<"START "<<startNum<<" idx:"<<startIdx<<"  END:"<<endNum<<" idx:"<<endIdx<<endl;
    while(true){
        //cout<<"NOW: "<<startNum<<" idx:"<<startIdx<<endl;
        if(startIdx<startNum){
            answer.push_back(startNum);
        }else{
            answer.push_back(startNum+(startIdx-startNum+1));
        }
        if(startNum == endNum && startIdx == endIdx){
            break;
        }
        startIdx=(startIdx+1)%n;
        if(startIdx==0){
            startNum++;
        }
    }
    
    return answer;
}