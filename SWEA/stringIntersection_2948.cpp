/*
    작성자: 김지수
    작성일: 2022/08/04
    SWEA -- 문자열 교집합 (2948번)
    // 실행시간: 3,620ms
*/

#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<string,int> strs[26];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int set1,set2;
        for(int i=0;i<26;i++){
            strs[i].clear();
        }
        cin>>set1>>set2;
        for(int i=0;i<set1;i++){
            string a;
            cin>>a;
            strs[(a[0]-'a')].insert(make_pair(a,set1));
        }
        int commonCnt = 0;
        for(int i=0;i<set2;i++){
            string a;
            cin>>a;
            if(strs[a[0]-'a'].find(a) !=strs[a[0]-'a'].end()){
                commonCnt++;
            }
        }
        cout<<"#"<<test_case<<" "<<commonCnt<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}