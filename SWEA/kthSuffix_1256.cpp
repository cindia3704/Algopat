/*
    작성자: 김지수
    작성일: 2022/08/24
    SWEA -- K번째 접미어 (1256번)
*/

#include <iostream>
#include <algorithm>
#define MAX 401
using namespace std; 

string suffix[MAX];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int k;
        cin>>k;
        string word; 
        cin>>word;
        int wordLength = word.length();
        if(k>wordLength){
            cout<<"#"<<test_case<<" none\n";
        }else{
            for(int i=0;i<wordLength;i++){
                string suff="";
                for(int j=i;j<wordLength;j++){
                    suff+=word[j];
                }
                suffix[i] = suff;
            }
            sort(suffix,suffix+wordLength);
            cout<<"#"<<test_case<<" "<<suffix[k-1]<<'\n';
        }
        
	}
	return 0;
}