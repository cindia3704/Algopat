/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 트럭 (13335번)
*/

#include <iostream>
#include <vector>
#include <deque>
#define MAX 1001
using namespace std; 

int truckNum, bridgeLength, maxWeight;
vector<int> truckList; 
int ans = 0;
// 현재 다리에 있는 트럭의 무게 & 각 트럭의 위치 저장 
deque<pair<int,int> > dq; 

// 현재 다리에 있는 트럭 모두 왼쪽으로 한칸 이동! 
int moveOneLeft(){
    // 다리 빠져나가는 트럭의 무게 합 
    int removeWeight =0;
    int dqSize = dq.size();
    // 현재 다리에 있는 트럭만큼 반복 
    for(int i=0;i<dqSize;i++){
        pair<int,int> now = dq.front();
        dq.pop_front();
        // 트럭 위치 한칸 왼쪽으로 
        now.second++;
        // 왼쪽으로 1칸 이동해도 트럭이 다리에 있으면 다시 dq에 넣어줌 
        if(now.second<=bridgeLength){
            dq.push_back(now);
        }else{
            // 다리 빠져나가면 해당 트럭 무게 더함 
            removeWeight+=now.first;
        }
    }
    return removeWeight;
}


void makeComb(int start,int time,int totalWeight){
    // 모든 트럭이 다리 건널 dq에 추가된 경우 
    if(start == truckNum){
        // 모든 트럭이 다리 빠져나갈때까지 왼쪽으로 이동 반복하며 time ++ 
        while(!dq.empty()){
            int removeWeight= moveOneLeft();
            time++;
        }
        ans = time;
    }else{
        // 다리에 있는 트럭들 왼쪽으로 한칸 이동 
        int removeWeight= moveOneLeft();
        // 다리 빠져나간 트럭 무게 업데이트 
        totalWeight-=removeWeight;

        // 다음 트럭이 다리 진입가능한지 체크 
        int nextTruck = truckList[start];
        if(totalWeight+nextTruck<=maxWeight && dq.size()+1 <=bridgeLength){
            dq.push_back(make_pair(nextTruck,1));
            makeComb(start+1,time+1,totalWeight+nextTruck);
        }else{
            makeComb(start,time+1,totalWeight);
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>truckNum>>bridgeLength>>maxWeight;
    // 트럭 무게 받고 저장 
    for(int i=0;i<truckNum;i++){
        int num; 
        cin>>num; 
        truckList.push_back(num);
    }
    makeComb(0,0,0);
    cout<<ans;
}