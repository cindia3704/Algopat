/*
    작성자: 김지수
    작성일: 2022/09/09
    프로그래머스 -- 최솟값 만들기 (12951번)
*/

#include <iostream>
#include<vector>
#include <cstring> 
#include <algorithm>
#define MAX 1001
using namespace std;
int target;

int solution(vector<int> A, vector<int> B)
{
    target = A.size();
    // memset(used,false,sizeof(used));
    // makeComb(0,A,B);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int answer = 0;
    for(int i=0;i<target;i++){
        answer+=(A[i]*B[target-i-1]);
    }
    return answer;
}