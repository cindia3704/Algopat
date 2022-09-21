/*
    작성자: 김지수
    작성일: 2022/09/21
    백준 -- 에라토스테네스의 체 (2960번)
*/

#include <iostream>
#include <cstring>
#define MAX 1001
using namespace std; 
bool check[MAX];

void findKth(int n,int k){
    int eraseNum = 1;
    for(int i=2;i<=n;i++){
        if(!check[i]){
            for(int j=i;j<=n;j+=i){
                if(!check[j]){
                    check[j] = true;
                    if(eraseNum == k){
                        cout<<j;
                        exit(0);
                    }
                    eraseNum++;
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n,k;
    cin>>n>>k;
    memset(check,false,sizeof(check));
    findKth(n,k);
}