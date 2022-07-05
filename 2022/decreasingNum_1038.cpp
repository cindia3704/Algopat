#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

long long cache[11][10];
vector<long long> ans; 
int pick[11];
bool visited[10];
//int idx = 0;

// 모든 감소하는 수 구하기 
void makeNum(int digitNum, int firstNum){
    if(digitNum == -1){
            long long temp = 0;
            long long digit = 1;
            for(int i=0;i<10;i++){
                temp+=digit*pick[i];
                digit*=10;

            }
           
            ans.push_back(temp);
        return; 
    }else{
        for(int i=firstNum;i>=0;i--){
            if(!visited[i]){
                visited[i] = true; 
                pick[digitNum] = i;
                makeNum(digitNum-1,i-1);
                visited[i] = false;
            }
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 총 자리수 & 첫 숫자로 시작하는거에 따라 몇개가 있는지 구하기 
    // 1 1 1 1 1 1 1 1 1
    // 0 1 2 3 4 5 6 7 8 9
    // 0 0 1 3 6 10 15 21 26 36
    // a[i][j] = a[i][j-1]+a[i-1][j-1]
    for(int i=0;i<10;i++){
       cache[1][i] = 1;
    }
   for(int i=2;i<11;i++){
        cache[i][0] = 0;
    }
    for(int i=2;i<11;i++){
        for(int j=1;j<10;j++){
            cache[i][j] = cache[i][j-1] + cache[i-1][j-1];
        }
    }

    int n;
    cin>>n; 
    memset(visited,false,sizeof(visited));
    long long sum=-1;
    bool found = false;
    long long finalAns=0;

    // 현재찾으려는 감소하는 수의 범위 구하기 
    for(int i=1;i<11;i++){
        for(int j=0;j<10;j++){
            if(!found){
                //cout<<"sum: "<<sum<<"   i: "<<i<<"   J:"<<j<<"  cache:"<<cache[i][j]<<endl;
                if(sum+cache[i][j]>=n){
                    // 첫번째 수는 세팅
                    pick[i-1] = j;
                    makeNum(i-2,j-1);
                    // 정렬하고 답 구하기 
                    sort(ans.begin(),ans.end());
                    finalAns = ans[n-sum-1];
                    found = true;
                }
                sum+=cache[i][j];
            }
        }
    }

    if(!found){
        cout<<-1;
    }else{
        cout<<finalAns;
    }
}