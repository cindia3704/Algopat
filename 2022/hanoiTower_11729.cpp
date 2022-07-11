/*
    작성자: 김지수
    작성일: 2022/07/12
    백준 -- 하노이 탑 이동 순서 (11729번)
*/

#include <iostream>
#include <vector>
using namespace std;
int k;
int counts =0;
vector<string> ans; 

void move(int from,int to,int n){
    counts++;
    // 원판 한개남았으면 from -> to 로 옮기면 됨 
    if(n==1){
        string s = to_string(from)+" "+to_string(to);
        ans.push_back(s);
    }else{
        // n-1개는 from 도 to 도 아닌곳으로 옮김 
        move(from,6-from-to,n-1);
        // 마지막 n번째 원판을 from 에서 to 로 옮김 
        string s = to_string(from)+" "+to_string(to);
        ans.push_back(s);
        // 다시 n-1개를 from 도 to도 아닌곳에서 to 로 옮김
        move(6-from-to,to,n-1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>k;
    move(1,3,k);
    
    cout<<counts<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}