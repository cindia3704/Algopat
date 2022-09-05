/*
    작성자: 김지수
    작성일: 2022/09/06
    Softeer -- 징검다리
*/
#include<iostream>
#include <algorithm>
#define MAX 3001

int arr[MAX];
int cache[MAX];

using namespace std;

int main(int argc, char** argv)
{
	int seqLen;
	cin>>seqLen;
	for(int i=0;i<seqLen;i++){
		cin>>arr[i];
	}
	fill(cache,cache+seqLen+1,1);
	for(int i=1;i<seqLen;i++){
		for(int j=0;j<i;j++){
			//cout<<"arr["<<i<<"]: "<<arr[i]<<" j:"<<j<<". arr:"<<arr[j]<<endl;
			if(arr[j]<arr[i]){
				cache[i]=max(cache[i],cache[j]+1);
			}
		}
		//cout<<"===cache["<<i<<"] :"<<cache[i]<<endl;
	}

	int ans =0;
	for(int i=0;i<seqLen;i++){
		ans = max(ans,cache[i]);
	}
	cout<<ans;
	return 0;
}