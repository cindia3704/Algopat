/*
    작성자: 김지수
    작성일: 2022/08/09
    백준 -- 절댓값 힙 
*/

#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std; 

class Heap{
    #define parent (i>>1)
    #define left (i<<1)
    #define right (i<<1|1)

    pair<int,int> data[MAX];
    size_t size;

public:
    Heap() = default;
    void init(){
        size = 0;
    }

    void push(int x){
        data[++size].first = abs(x);
        data[size].second = x; 
        for(int i=size;parent!=0 && data[parent].first>=data[i].first;i>>=1){
            if(data[parent].first>data[i].first){
                swap(data[parent],data[i]);
            }else if(data[parent].second>data[i].second){
                swap(data[parent],data[i]);
            }
        }
    }

    int top(){
        if(size==0){
            return 0;
        }
        return data[1].second;
    }

    void pop(){
        data[1] = data[size--];
        for(size_t i=1;left<=size;){
            int min_child = (left == size || (data[left].first<data[right].first || (data[left].first==data[right].first && data[left].second<data[right].second) )) ? left : right; 
            if(data[min_child].first<data[i].first || (data[min_child].first==data[i].first && data[min_child].second<data[i].second)){
                swap(data[min_child],data[i]);
                i = min_child;
            }else{
                break;
            }
        }
    }

};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    Heap h; 
    h.init();
    int opCnt; 
    cin>>opCnt;
    for(int i=0;i<opCnt;i++){
        int num;
        cin>>num;
        if(num==0){
            int temp = h.top();
            cout<<temp<<'\n';
            if(temp!=0){
                h.pop();
            }
        }else{
            h.push(num);
        }
    }
}