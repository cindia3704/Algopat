/*
    작성자: 김지수
    작성일: 2022/09/17
    백준 -- 외계인의 기타 연주 (2841번)
*/

#include <iostream>
#include <stack>
using namespace std; 
stack<int> q[7];


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int pitchCnt,pretCnt;
    cin>>pitchCnt>>pretCnt;
    int moveCnt = 0;

    for(int i=0;i<pitchCnt;i++){
        int line,pret; 
        cin>>line>>pret; 
        if(q[line].empty()){
            q[line].push(pret);
            moveCnt++;
        }else{
            int topPret = q[line].top();
            if(pret>topPret){
                q[line].push(pret);
                moveCnt++;
            }else if(pret == q[line].top()){
                continue;
            }else{
                while(q[line].size()>0){
                    int nextPret = q[line].top();
                    if(nextPret<=pret){
                        break;
                    }
                    moveCnt++;
                    q[line].pop();
                }
                if(q[line].empty()){
                    q[line].push(pret);
                    moveCnt++;
                }else{
                    if(q[line].top()<pret){
                        q[line].push(pret);
                        moveCnt++;
                    }
                }
            }
        }
    }
    cout<<moveCnt;

}