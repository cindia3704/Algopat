/*
    작성자: 김지수
    작성일: 2022/07/19
    SWEA -- 동아리실 관리하기 (3316번)
*/

#include <iostream>
#include <cstring>
#define MOD 1000000007
#define MAX 10001

using namespace std;
long long cache[MAX][16];

void calculate(string s){
    for(int i=0;i<s.length();i++){
        int manager = (1<<(s[i]-'A'));
        for(int j=1;j<16;j++){
            if(i==0){
                // 첫째날은 A가 열쇠 가지고 있으므로 (j&1) ++ 관리자가 포함되어있어야함 
                if((j&manager)&& (j & 1)){
                    cache[i][j] = 1;
                }
            }else{
                // 이전날을 만족한 경우
                if(cache[i-1][j]!=0){
                    // 전날 나온사람이 오늘도 나옴 & 관리자 만족하면 
                    for(int k=1;k<16;k++){
                        if((k&j) && (k&manager)){
                            cache[i][k] += cache[i-1][j]; 
                            cache[i][k]%=MOD;
                        }
                    }
                }
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
        string manager; 
        cin>>manager;
        memset(cache,0,sizeof(cache));

        calculate(manager);
        
        long long possiblility = 0;
        for(int i=1;i<16;i++){
            possiblility+=cache[manager.length()-1][i];
            possiblility%=MOD;
        }
        cout<<"#"<<test_case<<" "<<possiblility<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}