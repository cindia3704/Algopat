/*
    작성자: 김지수
    작성일: 2022/10/06
    SWEA -- [모의 SW 역량테스트] 보물상자 비밀번호 (5658번)
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
int n,k;
deque<char> numList; 
set<string,greater<string> > posList;

void makeNumbers(){
    for(int i=0;i<4;i++){
        string now="";
        for(int j=0;j<n/4;j++){
            now+=numList[i*(n/4)+j];
        }
        posList.insert(now);
    }
}

long long makeToNum(string number){
    long long ret=0;
    for(int i=0;i<number.length();i++){
        char now = number[i];
        if(now>='A' && now<='F'){
            ret+=(now-'A'+10)*pow(16,n/4-1-i);
        }else {
            ret+=(now-'0')*pow(16,n/4-1-i);
        }
    }
    return ret; 
}

long long startGame(){
    long long ans ;

    for(int i=0;i<n;i++){
        int backNum = numList.back();
        numList.pop_back();
        numList.push_front(backNum);
        makeNumbers();
    }
    int idx =1;
    for(set<string> :: iterator it = posList.begin();it!=posList.end();it++){
        if(idx == k){
            ans = makeToNum(*it);
            break;
        }
        idx++;
    }
    return ans; 
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        numList.clear();
        posList.clear();
        cin>>n>>k; 
        string num;
        cin>>num;
        for(int i=0;i<num.length();i++){
            numList.push_back(num[i]);
        }
        cout<<"#"<<test_case<<" "<<startGame()<<"\n";
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}