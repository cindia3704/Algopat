/*
    작성자: 김지수
    작성일: 2022/06/15
    백준 -- 회전하는 큐 (1021번)
*/

#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 51
using namespace std;

deque<int> dq; 
int n,k; 
int leastCount = 0;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        int numIdx = find(dq.begin(),dq.end(),num) - dq.begin();
        if(numIdx == 0){
            dq.pop_front();
            continue;
        }else{
            int op3Idx = dq.size()-numIdx;
            if(numIdx<op3Idx){
                for(int i=0;i<numIdx;i++){
                    dq.push_back(dq.front());
                    dq.pop_front();
                    leastCount++;
                }
            }else{
                for(int i=0;i<op3Idx;i++){
                    dq.push_front(dq.back());
                    dq.pop_back();
                    leastCount++;
                }
            }
            dq.pop_front();
        }

    }

    cout<<leastCount;
}