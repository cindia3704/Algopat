/*
    작성자: 김지수
    작성일: 2022/06/17
    백준 -- 연산자 끼워넣기 (14888번)
*/

#include <iostream>
#include <deque> 
#include <algorithm>
#define MAX_OPERAND 12
using namespace std; 

int numOperand;
int operators[4];   // - , + , * , / 
long long operands[MAX_OPERAND];
long long picked[MAX_OPERAND];
deque<long long> dq; 
long long ansMin = 987654321;
long long ansMax = -987654321;

// 스택처럼 쌓은 후 계산 
void calculate(){
    for(int i=0;i<numOperand-1;i++){
        dq.push_back(operands[i]);
        dq.push_back(picked[i]);
    }
    dq.push_back(operands[numOperand-1]);

    while(dq.size()>1){
        long long num1 = dq.front();
        dq.pop_front();
        long long op = dq.front();
        dq.pop_front();
        long long num2 = dq.front();
        dq.pop_front();
       if(op==0){
            long long result = num1+num2; 
            dq.push_front(result);
        }else if(op == 1){
            long long result = num1-num2; 
            dq.push_front(result);  
        }else if(op == 2){
            long long result = num1*num2; 
            dq.push_front(result);  
        }else if(op == 3){
            long long result = num1/num2; 
            dq.push_front(result);  
        }
       
    }
    // 계산 후 최대값 최솟값 업데이트 
    long long last = dq.front();
    if(ansMax<last){
        ansMax = last;
    }
    if(ansMin>last){
        ansMin = last;
    }
    return;
}

void makeComb(int pickCount){
    // 식 만족하는 연산자 고르면 계산하기 
    if(pickCount == numOperand-1){
        calculate();
        // ** 중요!! 스택처럼 만든 덱 비워주기 
        dq.clear();
        return; 
    }else{
        // 연산자 + - * / 돌아가며 개수가 0개보다 많을때 고르기 
        for(int i=0;i<4;i++){
            if(operators[i]>0){
                operators[i]--;
                picked[pickCount] = i;
                makeComb(pickCount+1);
                operators[i]++;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(operators,operators+4,0);

    cin>>numOperand;
    for(int i=0;i<numOperand;i++){
        cin>>operands[i];
    }

    for(int i=0;i<4;i++){
        cin>>operators[i];
    }

    makeComb(0);

    cout<<ansMax<<'\n'<<ansMin;

}