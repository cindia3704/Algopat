/*
    작성자: 김지수
    작성일: 2022/08/24
    SWEA -- [Professional] Inversion Counting (3998번)
*/

#include <iostream>
#define MAX 100001

using namespace std;
long long arrSize;

long long inversionCnt;

void mergesort(long long arr[],long long size){
    if(size == 1){
        return; 
    }
    long long mid = size/2; 
    mergesort(arr,mid);
    mergesort(arr+mid, size-mid);

    long long *buf = new int[size];
    long long i=0, j = mid, k=0;
     while(i<mid && j<size){
        if(arr[i]<arr[j]){
            buf[k++] = arr[i++];
        }else{
            buf[k++] = arr[j++];
            inversionCnt+= (mid-i);
        }
    }
    while(i<mid){
        buf[k++] = arr[i++];
    }
    while(j<size){
        buf[k++] = arr[j++];
    }

    for(int i=0;i<size;i++){
        arr[i] = buf[i];
    }

    delete[] buf;
}


int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        long long arr[MAX];
        inversionCnt = 0;
        cin>>arrSize;
        for(int i=0;i<arrSize;i++){
            cin>>arr[i];
        }
        mergesort(arr,arrSize);
        cout<<"#"<<test_case<<" "<<inversionCnt<<'\n';
	}
	return 0;
}