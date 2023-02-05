#include <iostream>
#include <algorithm>
#include <vector>
#include<cstring>
#define MAX 11

using namespace std; 
int n;
pair<int,int> ingr[MAX];
long long ans = 0x7fffffff;
bool visited[MAX];

void makeComb(int cnt,int sourScr,int bitterScr){
    if(cnt==0){
        long long tempAns = abs(bitterScr-sourScr);
        if(tempAns<ans){
            ans = tempAns;
        }
        return;
    }else{
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                makeComb(cnt-1,sourScr*ingr[i].first,bitterScr+ingr[i].second);
                visited[i] = false;
            }
        }
        return;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ingr[i].first>>ingr[i].second;
    }

    for(int i=1;i<=n;i++){
        memset(visited,false,sizeof(visited));
        makeComb(i,1,0);
    }

    cout<<ans;
    
}