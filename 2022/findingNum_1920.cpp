/*
    작성자: 김지수
    작성일: 2022/06/22
    백준 -- 수 찾기 (1920번)
*/

#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std; 
int arrN[MAX];
int arrM[MAX];
int exists(int num, int n){
    int st = 0;
    int en = n-1; 
    int ans =0;
    while(true){
        int mid = (st+en)/2;
        //시작 & 끝이 역전되면 arrN에 num이 없음을 의미
        if(st>en){
            ans = 0; 
            break;
        }
        // 가운데 원소가 num이면 찾았고, 끝냄 
        if(arrN[mid]==num){
            ans = 1;
            break;
        }else{
            // 가운데 원소가 num보다 크면 en = mid-1
            if(arrN[mid]>num){
                en = mid-1; 
            }else{
                st = mid+1;
            }
        }
        
    }
    return ans; 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arrN[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>arrM[i];
    }

    // N배열 정렬 -> O(NlgN)
    sort(arrN,arrN+n);
    for(int i=0;i<m;i++){
        cout<<exists(arrM[i],n)<<"\n";
    }
}