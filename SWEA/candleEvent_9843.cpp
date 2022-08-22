/*
    작성자: 김지수
    작성일: 2022/08/22
    SWEA -- 촛불 이벤트 (9843번)
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std; 

long long findLev(long long n){
    long long temp = sqrt(2*n);
    return (((temp*(temp+1))/2)==n) ? temp:-1;
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
        long long candleCnt;
        cin>>candleCnt;
        cout<<"#"<<test_case<<" "<<findLev(candleCnt)<<'\n';
	}
	return 0;
}