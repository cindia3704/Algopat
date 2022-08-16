/*
    작성자: 김지수
    작성일: 2022/08/16
    SWEA -- 염라대왕의 이름 정렬 (7701번)
*/

#include<iostream>
#include <vector>
#include <set> 
#include <algorithm>

using namespace std;
vector<pair<string,int> > nameList; 
set<string> names; 

bool cmp(pair<string,int> & a, pair<string,int> &b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    return a.second<b.second;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        nameList.clear();
        names.clear();
        int nameCnt;
        cin>>nameCnt;
        for(int i=0;i<nameCnt;i++){
            string s;
            cin>>s;
            if(names.find(s)==names.end()){
                names.insert(s);
                nameList.push_back(make_pair(s,s.length()));
            }
        }
        sort(nameList.begin(),nameList.end(),cmp);
        cout<<"#"<<test_case<<'\n';
        for(int i=0;i<nameList.size();i++){
            cout<<nameList[i].first<<'\n';
        }
	}
	return 0;
}