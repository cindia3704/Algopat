/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 영어 공부 (10507번)
*/

#include <iostream>
#include <cstring>
#define MAX 1000001

bool used[MAX];
using namespace std;
int ans;

void findMax(int fakeCnt){
    int left = fakeCnt; 
    int cnt = 0;
    int start= 1;
    int end = 1; 

    while(end<MAX){
        // 실제 공부한날 -> 다음날로 이동 & 연속공부 횟수++
        if(used[end]){
            end++;
            cnt++;
            ans =max(ans,cnt);
        }else{
            // 가짜 공부한날 -> 추가할수 있는 날이 남으면 
            if(left>0){
                // 추가횟수 --, 연속공부 횟수 ++, 다음날 보기 
                left--;
                cnt++;
                end++;
            }else {
                // 추가할 수 있는 날이 아니면-> 답 업데이트 
                ans =max(ans,cnt);
                // 시작일이 가짜로 공부한 날 -> 추가 가능 횟수 ++
                if(!used[start]){
                    left++;
                }
                // 시작일 올려주고, 연속공부 횟수 -- 
                start++;
                cnt--;
            }
        }
    }

}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        fill(used,used+MAX,false);
        int realCnt, fakeCnt;
        cin>>realCnt>>fakeCnt;
        ans = fakeCnt+1;
        
        for(int i=0;i<realCnt;i++){
            int num;
            cin>>num;
            used[num] = true; 
        }
        
        findMax(fakeCnt);
        cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;
}