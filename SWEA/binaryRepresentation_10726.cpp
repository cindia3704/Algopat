/*
    작성자: 김지수
    작성일: 2022/07/19
    SWEA -- 이진수 표현 (10726번)
*/

#include<iostream>

using namespace std;

bool checkOnOff(int n,int m){
    for(int i=0;i<n;i++){
        if(!(m &(1<<i))){
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n,m;
        cin>>n>>m; 
        bool turnedOn = checkOnOff(n,m);
        cout<<"#"<<test_case<<" ";
        if(turnedOn){
            cout<<"ON"<<endl;
        }else{
            cout<<"OFF"<<endl;
        }

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}