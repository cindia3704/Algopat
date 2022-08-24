/*
    작성자: 김지수
    작성일: 2022/08/24
    SWEA -- K번째 문자열 (1257번)
*/

#include <iostream>
#include <algorithm>
#include <set>
#define MAX 401
using namespace std; 

set<string> temp; 

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int k;
        cin>>k;
        temp.clear();
        string word; 
        cin>>word;
        int wordLength = word.length();
        int idx = 0;
        for(int i=0;i<wordLength;i++){
            string suff="";
            for(int j=i;j<wordLength;j++){
                suff+=word[j];
                temp.insert(suff);
            }
        }
       
        int nowIdx = 0;
        string prev = "";
        bool found = false;
        
        for(set<string> ::iterator it = temp.begin(); it!=temp.end();it++){
            if(nowIdx == k-1){
                found = true;
                cout<<"#"<<test_case<<" "<<*it<<'\n';
            }
            nowIdx++;
        }
        if(!found){
             cout<<"#"<<test_case<<" none"<<'\n';
        }  
	}
	return 0;
}