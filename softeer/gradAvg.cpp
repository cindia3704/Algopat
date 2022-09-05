/*
    작성자: 김지수
    작성일: 2022/09/06
    Softeer -- 성적 평균
*/
#include <iostream>
#define MAX 1000002

using namespace std;
int arr[MAX];
int sum[MAX];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int studCnt,rangeCnt;
	cin>>studCnt>>rangeCnt;
	for(int i=1;i<=studCnt;i++){
		cin>>arr[i];
	}
	sum[0] = 0;
	for(int i=1;i<=studCnt;i++){
		sum[i] = sum[i-1]+arr[i];
	}
	for(int i=0;i<rangeCnt;i++){
		int st,en;
		cin>>st>>en;
		double avg = 1.0*(sum[en]-sum[st-1])/(en-st+1);
		cout << fixed;
		cout.precision(2);
		cout<<avg<<'\n';
	}
	return 0;
}