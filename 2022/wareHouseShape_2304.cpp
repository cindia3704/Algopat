/*
    작성자: 김지수
    작성일: 2022/09/17
    백준 -- 창고 다각형 (2304번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std; 

vector<pair<int,int> > buildingList; 
int area;
int heights[MAX];
int minX = 0x7fffffff;
int maxX = 0;
int mid = 0;

void findArea(int buildingCnt){
    pair<int,int> start = buildingList[0]; 
    heights[start.second] = start.first;
    mid = start.second;
    for(int i=1;i<buildingCnt;i++){
        pair<int,int> now = buildingList[i];
        if(heights[now.second]<now.first){
            heights[now.second] = now.first;
            int x = now.second;
            if(now.second<mid){
                while(x<mid){
                    if(heights[x]>now.first){
                        break;
                    }
                    heights[x] = now.first;
                    x++;
                }
            }else{
                while(x>mid){
                    if(heights[x]>now.first){
                        break;
                    }
                    heights[x] = now.first;
                    x--;
                }
            }
        }
    }
}

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first>b.first;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int buildingCnt; 
    cin>>buildingCnt;
    for(int i=0;i<buildingCnt;i++){
        int x,height;
        cin>>x>>height;
        minX = min(minX,x);
        maxX = max(maxX,x);
        buildingList.push_back(make_pair(height,x));
    }
    sort(buildingList.begin(),buildingList.end(),cmp);
    memset(heights,0,sizeof(heights));
    findArea(buildingCnt);
    int ans =0;
    for(int i=minX;i<=maxX;i++){
        ans+=heights[i];
    }
    cout<<ans;
}   