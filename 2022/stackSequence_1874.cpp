/*
    작성자: 김지수
    작성일: 2022/06/13
    백준 -- 스택 수열 (1873번)
*/

#include <iostream>
#include <stack>
#define MAX 100001

using namespace std; 
int sequence[MAX];
int seqLength;
stack<int> s; 
char op[MAX*2];
bool found = false; 

void makeComb(int pickCount, int nowIdx,int nextInt){
    if(pickCount == seqLength*2){
        if(nowIdx==seqLength){
            found = true;
           for(int i=0;i<pickCount;i++){
               cout<<op[i]<<'\n';
           }
        }
        return; 
    }else{
        if(s.empty()){
            s.push(nextInt);
            op[pickCount] = '+';
            makeComb(pickCount+1,nowIdx,nextInt+1);
        }else{
            if(s.top() == sequence[nowIdx]){
                op[pickCount] = '-';
                s.pop();
                makeComb(pickCount+1,nowIdx+1,nextInt);
            }else{
                op[pickCount] = '+';
                s.push(nextInt);
                makeComb(pickCount+1,nowIdx,nextInt+1);
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>seqLength;
    for(int i=0;i<seqLength;i++){
        cin>>sequence[i];
    }

    makeComb(0,0,1);
    if(!found){
        cout<<"NO";
    }
}   