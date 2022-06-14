/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 큐2 (18258번)
*/

#include <iostream>
#include <deque> 
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int commandNum; 
    cin>>commandNum; 
    deque<int> q; 

    for(int i=0;i<commandNum;i++){
        string command; 
        cin>>command;
        
        if(command == "push"){
            int num;
            cin>>num;
            q.push_back(num);
        }else if(command == "pop"){
            if(q.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<q.front()<<'\n';
                q.pop_front();
            }
        }else if(command == "size"){
            cout<<q.size()<<'\n';
        }else if(command == "empty"){
            cout<<q.empty()<<'\n';
        }else if(command == "front"){
            if(q.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<q.front()<<'\n';
            }
        }
        else if(command == "back"){
            if(q.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<q.back()<<'\n';
            }
        }
    }
}