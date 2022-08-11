/*
    작성자: 김지수
    작성일: 2022/08/10
    SWEA -- [Professional] 단어가 등장하는 횟수 (4038번)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTable(string s){
    int sSize = s.size();
    vector<int> table(sSize,0);

    int j=0;
    for(int i=1;i<sSize;i++){
        while(j>0 && s[j]!=s[i]){
            j=table[j-1];
        }
        if(s[j]==s[i]){
            table[i]=++j;
        }
    }
    
    return table;
}

int KMP(string a,string b){
    vector<int> table = makeTable(b);
    int aSize = a.size();
    int bSize = b.size();
    int j=0;
    int cnt=0;
    for(int i=0;i<aSize;i++){
        while(j>0 && b[j]!=a[i]){
            j=table[j-1];
        }
        if(a[i]==b[j]){
            if(j==bSize-1){
                cnt++;
                j=table[j];
            }else{
                j++;
            }
        }
    }
    return cnt;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string a, b; 
        cin>>a>>b;
        int cnt = KMP(a,b);
        cout<<"#"<<test_case<<" "<<cnt<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}