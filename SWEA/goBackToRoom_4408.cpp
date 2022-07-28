/*
    작성자: 김지수
    작성일: 2022/07/29
    SWEA -- 자기 방으로 돌아가기 (4408번)
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include<cstring>
#define MAX 201
using namespace std;
int studNum;
int corridore[201];

bool cmp(int & a, int &b){
    return a>b;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        cin>>studNum;
        memset(corridore,0,sizeof(corridore));
        for(int i=0;i<studNum;i++){
            int a,b;
            cin>>a>>b;
            if(a>b){
                int temp = a;
                a=b;
                b=temp;
            }
            int start = (a%2==1) ? (a+1)/2 : a/2;
            int end = (b%2==1) ? (b-1)/2 : b/2;
            for(int k=start;k<=end;k++){
                corridore[k]++;
            }
        }
        int ans = 0;
        for(int i=0;i<MAX;i++){
            if(ans<corridore[i]){
                ans = corridore[i];
            }
        }        
        cout<<"#"<<test_case<<" "<<ans<<'\n';
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}