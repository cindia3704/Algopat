/*
    작성자: 김지수
    작성일: 2022/08/04
    백준 -- 평범한 배낭 (12865번)
*/

#include <iostream> 
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 
vector<pair<int,int> > itemList; 
int cache[101][100001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int totalItem,maxWeight; 
    cin>>totalItem>>maxWeight;
    memset(cache,0,sizeof(cache));
    for(int i=0;i<totalItem;i++){
        int weight,score;
        cin>>weight>>score;
        itemList.push_back(make_pair(weight,score));
    }

    for(int itemIdx = 1;itemIdx<=totalItem;itemIdx++){
        for(int nowW = 1; nowW<=maxWeight;nowW++){
            pair<int,int> nowItem = itemList[itemIdx-1];
            if(nowItem.first <= nowW){
                cache[itemIdx][nowW] = max(cache[itemIdx-1][nowW-nowItem.first]+nowItem.second , cache[itemIdx-1][nowW]);
            }else{
                cache[itemIdx][nowW] = cache[itemIdx-1][nowW];
            }
        }
    }
    cout<<cache[totalItem][maxWeight];
}