/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 제로 (10773번)
*/

#include <iostream>
#include <stack> 
using namespace std; 
stack<int> s; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int numCount; 
    cin>>numCount;
    for(int i=0;i<numCount;i++){
        int num;
        cin>>num;
        if(num==0){
            if(s.empty()){
                continue;
            }else{
                s.pop();
            }
        }else{
            s.push(num);
        }
    }
    
    int sum = 0;
    while(!s.empty()){
        sum+=s.top();
        s.pop();
    }
    cout<<sum;

}