/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 다음 큰 숫자 (12911번)
*/

#include <string>
#include <vector>

using namespace std;

int convertBinary(int n){
    int num = n;
    int cnt = 0;
    while(true){
        if(num<=1){
            if(num==1){
                cnt++;
            }
            break;
        }
        if(num%2==1){
            cnt++;
        }
        num=num/2;
    }
    return cnt++;
}

int solution(int n) {
    int answer = 0;
    int oneCnt = convertBinary(n);
    while(true){
        n++;
        int ones = convertBinary(n);
        if(ones == oneCnt){
            break;
        }
    }
    answer = n;
    return answer;
}