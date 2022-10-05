/*
    작성자: 김지수
    작성일: 2022/10/05
    백준 -- 토너먼트 (1057번)
*/

#include <iostream>
#include <queue>
using namespace std; 
queue<int> comp;
bool found = false;
int ans = -1;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int totalPeople,a,b;
    cin>>totalPeople>>a>>b;
    for(int i=1;i<=totalPeople;i++){
        comp.push(i);
    }
    int stage = 1; 
    while(!found){
        queue<int> temp;
        if(comp.size()==1){
            break;
        }
        while(comp.size()>1){
            int num1 = comp.front();
            comp.pop();
            int num2 = comp.front();
            comp.pop();
            if((num1 ==a && num2==b) || (num1==b && num2==a)){
                ans = stage;
                found = true;
                break;
            }
            if(num1 ==a || num1 ==b){
                temp.push(num1);
            }else{
                temp.push(num2);
            }
        }
        if(comp.size()==1){
            temp.push(comp.front());
            comp.pop();
        }
        comp = temp;
        stage++;
    }
    cout<<ans;
}