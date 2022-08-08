#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
using namespace std; 

class MAXHeap{
    #define parent (i>>1)
    #define left (i<<1)
    #define right (i<<1|1)

    static const int MAX_N = 100000;
    int data[MAX_N+1];
    size_t size; 
private:
    /* data */
public:
    MAXHeap(){}
    
    void init(){
        size = 0;
    }

    // 마지막 노드에 추가하고 위치 찾아가기 
    void push(int x){
        data[++size] = x; 
        for(int i=size; parent!=0 && data[parent]<data[i];i>>=1){
            swap(data[parent],data[i]);
        }
    }

    int top(){
        return data[1];
    }

    // 위에 있는거 없애고, 마지막 노드에 있는수 루트로 가져와서 위치 찾아가기 
    void pop(){
        if(size==0){
            return;
        }
        data[1] = data[size--];
        for(size_t i=1;left<=size;){
            const int max_child = (left==size)||(data[left]>data[right]) ? left:right;
            if(data[max_child] > data[i]){
                swap(data[max_child],data[i]);
                i=max_child;
            }else{
                break;
            }
        }

    }
};


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    MAXHeap h;
    h.init();
    h.push(1);
    h.push(2);
    cout<<h.top()<<endl;
    h.push(3);
    cout<<h.top()<<endl;
    h.pop();
    cout<<h.top()<<endl;
}