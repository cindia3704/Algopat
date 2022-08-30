/*
    작성자: 김지수
    작성일: 2022/08/30
    SWEA -- 스팟마트 (8935번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX_N 3001
#define MAX_M 101
using namespace std; 

int cache[MAX_N][MAX_M][MAX_M][2];
int a[MAX_N];
int b[MAX_M];
int n,m;

int dp(int aPick,int bPick,int bSkip,int choose){
	int &ret = cache[aPick][bPick][bSkip][choose];
	if(aPick == n && bPick+bSkip == m){
		return 0;
	}
	if(ret!=-1){
		return ret; 
	}
	int temp = 0; 
	
	if(aPick<n){
		if(!choose){
			temp = max(temp,dp(aPick+1,bPick,bSkip,1)+a[aPick]);
		}
		temp = max(temp,dp(aPick+1,bPick,bSkip,0));
	}
	if(bPick+bSkip<m){
		if(!choose){
			temp = max(temp,dp(aPick,bPick+1,bSkip,1)+b[bPick]);
		}
		temp = max(temp,dp(aPick,bPick,bSkip+1,0));
	}
	
	ret = temp;
	return ret; 
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		memset(cache,-1,sizeof(cache));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));

		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}

		cin>>m;
		for(int i=0;i<m;i++){
			cin>>b[i];
		}
		sort(b,b+m,greater<int>());

		int ans = dp(0,0,0,0);
		cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}