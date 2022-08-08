/*
    작성자: 김지수
    작성일: 2022/08/09
    SWEA -- 힙 (2930번)
*/

#include <iostream>
#include<iostream>
#define MAX 100001

using namespace std;

class Heap{
    #define parent (i>>1)
    #define left (i<<1)
    #define right (i<<1|1)
    
    int data[MAX];
    size_t size; 

public: 
    Heap() = default;

    void init(){
        size = 0;
    }

    void push(int x){
        data[++size] = x; 
        for(int i=size;parent!=0 && data[parent]<data[i];i>>=1){
            swap(data[parent],data[i]);
        }
    }

    int top(){
        if(size == 0){
            return -1;
        }
        return data[1];
    }

    void pop(){
        data[1] = data[size--];
        for(size_t i = 1;left<=size;){
            const int max_child = left==size || data[left]>data[right] ? left:right;
            if(data[max_child]>data[i]){
                swap(data[max_child],data[i]);
                i=max_child;
            }else{
                break;
            }
        }
    }
};

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout<<"#"<<test_case<<" ";
       Heap h;
       h.init();
       int operationCnt; 
       cin>>operationCnt; 
       for(int i=0;i<operationCnt;i++){
            int op;
            cin>>op;
            if(op == 1){
                int num;
                cin>>num;
                h.push(num);
            }else{
                int temp = h.top();
                cout<<h.top()<<" ";
                if(temp!=-1){
                    h.pop();
                }
            }
       } 
       cout<<'\n';

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}