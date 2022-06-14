/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 탑 (2493번)
*/

#include <iostream>
#include <stack> 
using namespace std; 
stack<pair<int,int> > buildings; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int buildingNum;
    cin>>buildingNum;

    int num;
    for(int i=1;i<=buildingNum;i++){
        cin>>num; 
        // 쌓여있는 빌딩중 지금보다 큰거 있으면 출력, 없으면 하나씩 위에서 지움 
        while(!buildings.empty()){
            if(buildings.top().second >num){
                cout<<buildings.top().first<<' ';
                break;
            }
            buildings.pop();
        }
        // 첫빌딩은 무조건 0
        if(buildings.empty()){
            cout<<"0 ";
        }
        // 빌딩 스택에 넣음 
        buildings.push(make_pair(i,num));
    }

}