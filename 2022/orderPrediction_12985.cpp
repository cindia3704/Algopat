/*
    작성자: 김지수
    작성일: 2022/09/23
    백준 -- 예상 대진표 (12985번)
*/

#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int stage = 0;
    while(true){
        if(a==b){
            break;
        }
        a=(a+1)/2;
        b=(b+1)/2;
        stage++;
    }
    
    answer = stage;

    return answer;
}