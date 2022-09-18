/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 숫자의 표현 (12924번)
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i<=n;i++){
        int subtract = i;
        int num = n;
        while(true){
            num-=subtract;
            if(num==0){
                answer++;
                break;
            }
            if(num<0){
                break;
            }else{
                subtract++;
            }
        }
    }
    return answer;
}