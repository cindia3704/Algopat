/*
    작성자: 김지수
    작성일: 2022/06/23
    백준 -- 치킨 배달 (15686번)
*/

#include <iostream>
#include <cstring> 
#include <vector>
#include <queue>
#define MAX 51
using namespace std;
int boardSize, maxChickenStore;

long long ans =987654321; 
vector<pair<int,int> > home; 
vector<pair<int,int> > store; 
int pick[MAX*MAX];
bool visited[MAX*MAX];

void findMinDistance(){
    long long sum = 0;
    // 뽑힌 치킨집 & 모든집들까지 거리중 가장 작은 것들만 골라서 합함 
    for(int i=0;i<home.size();i++){
        long long distance = 987654321; 
        for(int j=0;j<maxChickenStore;j++){
            long long temp = abs(store[pick[j]].first - home[i].first)+abs(store[pick[j]].second - home[i].second);
            if(distance> temp){
                distance = temp;
            }
        }
        sum+=distance;
    }
    if(ans>sum){
        ans = sum;
    }
    return;
}

// 최대 개수만큼 치킨집 뽑기 (조합) - 백트레킹 
void makeComb(int pickCount, int start){
    if(pickCount == maxChickenStore){
        findMinDistance();
        return;
    }else{
        for(int i=start;i<store.size();i++){
            if(!visited[i]){
                visited[i] = true;
                pick[pickCount] = i;
                makeComb(pickCount+1, i+1);
                visited[i] = false;
            }
        }
    }
}


int main (void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>maxChickenStore;
    // 치킨가게 & 집 위치 담기 
    for(int i=0; i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int num; 
            cin>>num;
            if(num==1){
                home.push_back(make_pair(i,j));
            }
            if(num == 2){
                store.push_back(make_pair(i,j));
            }
        }   
    }

    memset(visited,false,sizeof(visited));
    makeComb(0,0);
    cout<<ans; 
}