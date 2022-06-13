/*
    작성자: 김지수
    작성일: 2022/06/13
    백준 -- 스택 (10828번)
*/

#include <iostream> 
#include <stack> 

using namespace std;
stack<int> s;  

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int commandNum; 
    cin>>commandNum;
    for(int i=0;i<commandNum;i++){
        string command; 
        cin>>command; 

        if(command == "push"){
            int num;
            cin>>num;
            s.push(num);
        }else if(command == "pop"){
            if(s.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<s.top()<<'\n';
                s.pop();
            }
        }else if(command == "size"){
            cout<<s.size()<<'\n';
        }else if(command == "empty"){
            if(s.empty()){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(command == "top"){
            if(s.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<s.top()<<'\n';
            }
        }
    }
}