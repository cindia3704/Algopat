/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 덱 (10866번)
*/

#include <iostream>
#include <deque>
using namespace std;
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int commandNum;
    cin>>commandNum;

    deque<int> dq; 

    for(int i=0;i<commandNum;i++){
        string command; 
        cin>>command;
        if(command == "push_back"){
            int num;
            cin>>num;
            dq.push_back(num);
        }else if(command == "push_front"){
            int num;
            cin>>num;
            dq.push_front(num);
        }else if(command == "pop_front"){
            if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.front()<<'\n';
                dq.pop_front();
            }
        }else if(command == "pop_back"){
             if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.back()<<'\n';
                dq.pop_back();
            }
        }else if(command =="size"){
            cout<<dq.size()<<'\n';
        }else if(command == "front"){
             if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.front()<<'\n';
            }
        }
        else if(command == "back"){
             if(dq.empty()){
                cout<<-1<<'\n';
            }else{
                cout<<dq.back()<<'\n';
            }
        }else if(command == "empty"){
            cout<<dq.empty()<<'\n';
        }
    }
}