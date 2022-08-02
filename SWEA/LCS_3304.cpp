/*
    작성자: 김지수
    작성일: 2022/08/03
    SWEA -- 최장 공통 부분 수열 (3304번)
*/
#include<iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int lcs[1002][1002];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string word1,word2; 
        cin>>word1>>word2;
        int word1L = word1.length();
        int word2L = word2.length();
        
        memset(lcs,0,sizeof(lcs));

        for(int i=1;i<=word1L;i++){
            for(int j=1;j<=word2L;j++){
                if(word1[i-1] == word2[j-1]){
                    lcs[i][j] = lcs[i-1][j-1]+1;
                }else{
                    lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        cout<<"#"<<test_case<<" "<<lcs[word1L][word2L]<<"\n";
     
	}
	return 0;
}
