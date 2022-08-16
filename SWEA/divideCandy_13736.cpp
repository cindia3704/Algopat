/*
    작성자: 김지수
    작성일: 2022/08/16
    SWEA -- 사탕 분배 (13736번)
*/
#include<iostream>
#include <cstring> 
using namespace std;
long long a, b, k;
long long modOp;

// 분할정복으로 O(nlogn)으로 거듭제곱 구하기 
long long findMin(long long n){
    if(n==0){
        return 1; 
    }
    long long k = findMin(n/2);
    k*=k;
    k%=modOp;
    if(n%2==1){
        k*=2;
        k%=modOp;
    }
    return k;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>a>>b>>k;
        modOp = a+b;
        long long temp = (findMin(k)*a)%modOp;
        long long ans = min(modOp-temp, temp);
        cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;
}