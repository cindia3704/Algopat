/*
    작성자: 김지수
    작성일: 2022/08/24
    SWEA -- 그래도 수명이 절반이 되어서는... (3813번)
*/

#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;
int blockCnt, coverCnt;
int wearLevel[MAX];
int coverSize[MAX];
int ans;

bool check(int n){
    int blockIdx = -1;
    for(int i=0;i<coverCnt;i++){
        for(int j=0;j<coverSize[i];j++){
            blockIdx++;
            //cout<<"i: "<<i<<" j:"<<j<<" blockIdx:"<<blockIdx<<" wL:"<<wearLevel[blockIdx]<<" n:"<<n<<endl;
            if(blockIdx>=blockCnt){
                return false;
            }
            if(wearLevel[blockIdx] > n){
                i--;
                break;
            }
        }
    }
    return true;
}

int binSearch(){
    int st = 1;
    int en = MAX;
    while(st<en){
        int mid = (st+en)/2;       
        if(check(mid)){
            en = mid;
        }else{
            st = mid+1;
        }
    }
    return en;
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
        ans = 0x7fffffff;
        cin>>blockCnt>>coverCnt; 
        for(int i=0;i<blockCnt;i++){
           cin>>wearLevel[i];
        }
        for(int i=0;i<coverCnt;i++){
            cin>>coverSize[i];
        }
        ans = min(ans,binSearch());
        cout<<"#"<<test_case<<" "<<ans<<'\n';

	}
	return 0;
}