/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 오큰수 (17298번)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

stack<int> s; 
vector<int> temp;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int seqLength;
    cin>>seqLength; 
    for(int i=0;i<seqLength;i++){
        int num;
        cin>>num;
        temp.push_back(num);
    }
    vector<int> ans; 
    
    // 입력 받은후 거꾸로 스택에 쌓기 
    for(int i=seqLength-1;i>=0;i--){
        // 다음꺼는 지금까지 쌓인 것중 top 보면서 큰 숫자 만날때까지 pop 
        while(!s.empty()){
            if(s.top() > temp[i]){
                ans.push_back(s.top());
                break;
            }
            s.pop();
        }
        // 스택이 비어있으면 -1 
        if(s.empty()){
            ans.push_back(-1);
        }
        s.push(temp[i]);
    }
    // ans 거꾸로 출력 
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}