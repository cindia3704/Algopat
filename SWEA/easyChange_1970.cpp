/*
    작성자: 김지수
    작성일: 2022/07/28
    SWEA -- 쉬운 거스름돈 (1970번)
*/

#include <iostream>
#include <cstring>
using namespace std;

int change[8]={50000,10000,5000,1000,500,100,50,10};
int changeUsed[8];

int useChange(int money){
    for(int i=0;i<8;i++){
        if(money-change[i]>=0){
            changeUsed[i]++;
            return money - change[i];
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        memset(changeUsed,0,sizeof(changeUsed));
        int money;
        cin>>money;

        while(money>0){
            money = useChange(money);
        }
        cout<<"#"<<test_case<<"\n";
        for(int i=0;i<8;i++){
            cout<<changeUsed[i]<<" ";
        }
        cout<<'\n';
       
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}