/*
    작성자: 김지수
    작성일: 2022/10/18
    Softeer -- 택배 마스터 광우
*/
#include<iostream>
#include <vector> 
#include <cstring>
#include <deque> 
#include <algorithm>
using namespace std;

int railCnt,targetWeight,turnCnt; 
vector<int> inputs; 
int ans = 0x7fffffff;

void caculate(){
	deque<int> rails;
	for(int i=0;i<railCnt;i++){
		rails.push_back(inputs[i]);
	}
	int sum = 0;
	for(int i=0;i<turnCnt;i++){
		int temp = 0;
		while(true){
			int now = rails.front();
			if(temp+now <= targetWeight){
				temp+=now;
				rails.pop_front();
				rails.push_back(now);
			}else{
				break;
			}
		}
		sum+=temp;
	}
	ans = min(ans,sum);
}

int main(int argc, char** argv)
{
	cin>>railCnt>>targetWeight>>turnCnt;
	for(int i=0;i<railCnt;i++){
		int num;
		cin>>num; 
		inputs.push_back(num);
	}
	sort(inputs.begin(),inputs.end());
	do{
		caculate();
	}while(next_permutation(inputs.begin(),inputs.end()));

	cout<<ans;
	return 0;
}