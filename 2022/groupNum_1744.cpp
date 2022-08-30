/*
    작성자: 김지수
    작성일: 2022/08/30
    백준 -- 수 묶기 (1744번)
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std; 

int ans =0;
int arrLen;
priority_queue<int> arrPos;
priority_queue<int> arrNeg;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>arrLen;

    for(int i=0;i<arrLen;i++){
        int num;
        cin>>num;
        if(num>0){
            arrPos.push(num);    
        }else{
            arrNeg.push(-num);
        }

    }
   while(arrPos.size()>1){
        int num1 = arrPos.top();
        arrPos.pop();
        int num2 = arrPos.top();
        arrPos.pop();
        int temp = num1 * num2; 
        if(temp < num1+num2){
            temp = num1+num2;
        }
        ans+=temp;
   }
   if(arrPos.size()==1){
        ans+=arrPos.top();
   }

   while(arrNeg.size()>1){
        int num1 = -arrNeg.top();
        arrNeg.pop();
        int num2 = -arrNeg.top();
        arrNeg.pop();
        int temp = num1 * num2; 
        if(temp < num1+num2){
            temp = num1+num2;
        }
        ans+=temp;
   }
   if(arrNeg.size()==1){
        ans+=-arrNeg.top();
   }

   cout<<ans;

}