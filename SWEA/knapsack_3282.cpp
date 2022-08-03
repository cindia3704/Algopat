/*
    작성자: 김지수
    작성일: 2022/08/04
    SWEA -- 0/1 Knapsack (3282번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 101

using namespace std;
int totalItem,maxWeight; 
vector<pair<int,int> > itemList; 

int cache[MAX][1001];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>totalItem>>maxWeight;
        itemList.clear();
        memset(cache,-1,sizeof(cache));
        
        for(int i=0;i<totalItem;i++){
            int w,score;
            cin>>w>>score; 
            itemList.push_back(make_pair(w,score));
        }
        // idx번째 물건 포함한 경우  \ 남은 무게 로 cache 테이블 만들기 
        // 남은 무게가 0이면 최대 점수 = 0
        for(int i=0;i<=maxWeight;i++){
            cache[0][i] = 0;
        }
        // 아무것도 고르지 않은 경우-> 최대 점수 = 0
        for(int i=0;i<=totalItem;i++){
            cache[i][0] = 0;
        }
        //각 아이템 돌면서 포함 / 미포함 경우중 Max 값
        for(int i=1;i<=totalItem;i++){
            for(int j=1;j<=maxWeight;j++){
                // 현재 item의 무게가 남은 무게보다 작거나 같은 경우 
                if(itemList[i-1].first<=j){
                    // max( 현재 아이템 뺀 무게 중 가장 큰거 + 현재 아이템의 점수   ,   현재 아이템 포함 안한 경우)
                    cache[i][j] = max(cache[i-1][j-itemList[i-1].first]+itemList[i-1].second , cache[i-1][j]);
                }else{
                    // 포함할 수 없으면 이전값가져오기 (포함 ==> 대각선 아래, 미포함 -> 바로 내려오기 )
                    cache[i][j] = cache[i-1][j];
                }
            }
        }

        cout<<"#"<<test_case<<" "<<cache[totalItem][maxWeight]<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}