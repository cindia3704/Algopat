/*
    작성자: 김지수
    작성일: 2022/08/30
    SWEA -- 최대 상금 (1244번)
*/
#include <iostream>
#include <string> 
#include <algorithm>

using namespace std;
string scoreBoard;
int changeCnt;
long long ans = 0;

void makeComb(int pickCount, int start){
    if(pickCount == changeCnt){
        long long tempScore = stol(scoreBoard);
        ans = max(ans,tempScore);
        return;
    }
    for(int i=0;i<scoreBoard.size()-1;i++){
        for(int j=i+1;j<scoreBoard.size();j++){
                swap(scoreBoard[i],scoreBoard[j]);
                makeComb(pickCount+1,i);
                swap(scoreBoard[i],scoreBoard[j]);
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
        ans = 0;
        cin>>scoreBoard>>changeCnt;
        if(changeCnt>scoreBoard.size()){
            changeCnt = scoreBoard.size();
        }
        makeComb(0,0);
        cout<<"#"<<test_case<<" "<<ans<<'\n';
	}
	return 0;
}