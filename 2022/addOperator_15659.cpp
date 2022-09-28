/*
    작성자: 김지수
    작성일: 2022/09/28
    백준 -- 연산자 끼워넣기 (3) (15659번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#define MAX 12
using namespace std; 

int operandCnt;
int numList[MAX];
int opCnt[4];   // + - * /
int pick[MAX];
long long maxAns = -1000000001;
long long minAns = 1000000001;

// * & / 의 우선순위가 + - 보다 높음 
long long calc(){
    deque<long long > st; 
    int idx = 0;
    while(true){
        if(idx%2==0){
            if(!st.empty()){
                long long operatorNow = st.back();
                if(operatorNow == 2){
                    st.pop_back();
                    long long num1 = st.back();
                    st.pop_back();
                    long long num2 = numList[idx/2];
                    st.push_back(num1*num2);
                }else if(operatorNow ==3){
                    st.pop_back();
                    long long num1 = st.back();
                    st.pop_back();
                    long long num2 = numList[idx/2];
                    st.push_back(num1/num2);
                }else{
                    st.push_back(numList[idx/2]);
                }
            }else{
                st.push_back(numList[idx/2]);
            }
        }else{
            if(idx/2 >=operandCnt-1){
                break;
            }
           st.push_back(pick[idx/2]);
        }
        idx++;
    }

    while(st.size()>1){
        long long num1 = st.front();
        st.pop_front();
        long long op = st.front();
        st.pop_front();
        long long num2 = st.front();
        st.pop_front();
        if(op == 0){
            st.push_front(num1+num2);
        }else if(op == 1){
            st.push_front(num1-num2);
        }
    }
    long long ret = st.front();
    return ret; 
}

void makeComb(int pickCount){
    if(pickCount == operandCnt-1){
        long long tempAns = calc();
        maxAns= max(maxAns,tempAns);
        minAns = min(minAns,tempAns);
        return;
    }
    for(int i=0;i<4;i++){
        if(opCnt[i]>0){
            opCnt[i]--;
            pick[pickCount] = i;
            makeComb(pickCount+1);
            opCnt[i]++;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>operandCnt;
    for(int i=0;i<operandCnt;i++){
        cin>>numList[i];
    }
    
    for(int i=0;i<4;i++){
        cin>>opCnt[i];
    }
    makeComb(0);
    cout<<maxAns<<'\n'<<minAns;
}