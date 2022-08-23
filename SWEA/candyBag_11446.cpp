/*
    작성자: 김지수
    작성일: 2022/08/23
    SWEA -- 사탕 가방 (11446번)
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std; 
long long candyNum[101];
long long candyTypeCnt, minCandy;

long long findMax(long long st,long long en){

    while(st<=en){
        long long mid = (st+en)/2;
        long long sum = 0;
        for(int i=0;i<candyTypeCnt;i++){
            sum+=candyNum[i]/mid;
        }

        if(sum>=minCandy){
            st=mid+1;
        }else{
            en=mid-1;
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
        memset(candyNum,0,sizeof(candyNum));
        cin>>candyTypeCnt>>minCandy;
        long long maxCnt=0;
        for(int i=0;i<candyTypeCnt;i++){
            cin>>candyNum[i];
            if(candyNum[i]>maxCnt){
                maxCnt = candyNum[i];
            }
        }
                                     
        long long maxBag = findMax(1,maxCnt);
        cout<<"#"<<test_case<<" "<<maxBag<<'\n';


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}