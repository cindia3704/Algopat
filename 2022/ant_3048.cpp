/*
    작성자: 김지수
    작성일: 2022/07/14
    백준 -- 개미 (3048번)
*/

#include <iostream>

#define MAX 26
using namespace std;
int n,m;
int group[MAX];
char now[MAX]; 


void move(){
    char temp[MAX];
    int groupTemp[MAX];
    for(int i=0;i<n+m;i++){
        groupTemp[i] = group[i];
        temp[i] = now[i];
    }

    for(int i=n+m-1;i>0;i--){
        int j = i-1;
        if(group[i]==2 && group[j]==1){
                char a = now[i];
                temp[i] = now[j];
                temp[j] = a;
                groupTemp[j] = group[i];
                groupTemp[i] = group[j];
        }
    }

    for(int i=0;i<n+m;i++){
        now[i] = temp[i];
        group[i] = groupTemp[i];
    }
    return;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m; 
    for(int i=n-1;i>=0;i--){
        group[i]=1;
        cin>>now[i];
    }
    for(int j=n;j<n+m;j++){
        group[j] = 2;
        cin>>now[j];
    }

    int t;
    cin>>t;
    
    while(t--){
        move();
    }
    for(int i=0;i<n+m;i++){
        cout<<now[i];
    }
}