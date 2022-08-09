/*
    작성자: 김지수
    작성일: 2022/08/09
    SWEA -- 중간값 구하기 (3000번)
*/

#include<iostream>
#include <queue>
#define MOD 20171109
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        priority_queue<int> maxQ,minQ; 
        int sum=0;
        int round,num;
        cin>>round>>num;
        maxQ.push(num);
        for(int i=0;i<round;i++){
            for(int j=0;j<2;j++){
                int num1;
                cin>>num1;
                if(maxQ.top()<num1){
                    minQ.push(-num1);
                    if(minQ.size()==maxQ.size()+1){
                        maxQ.push(-minQ.top());
                        minQ.pop();
                    }
                }
                else{
                    maxQ.push(num1);
                    if(maxQ.size()>minQ.size()+1){
                        minQ.push(-maxQ.top());
                        maxQ.pop();
                    }
                }
            }
            sum+=(maxQ.top());
            sum%=MOD;
            
        }
        cout<<"#"<<test_case<<" "<<sum<<'\n';

	}
	return 0;
}