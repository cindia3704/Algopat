/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 에디터 (1406번)
*/


#include <iostream>
#include <list>
using namespace std; 
list<char> memo; 

int main(void ){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string initial; 
    cin>>initial;
    for(int i=0;i<initial.length();i++){
        memo.push_back(initial[i]);
    }
    
    list<char> ::iterator it = memo.end();

    int commandNum;
    cin>>commandNum;

    for(int i=0;i<commandNum;i++){
        char command; 
        cin>>command;
        switch (command)
        {
        case 'L':
            if(it!= memo.begin()){
                it--;
            }
            break;
         case 'D':
            if(it!=memo.end()){
                it++;
            }
            break;
         case 'B':
            if(it!= memo.begin()){
                it--;
                it = memo.erase(it);
            }
            break;
         case 'P':
            char alpha;
            cin>>alpha;
            memo.insert(it,alpha);
            break;
        default:
            break;
        }
    }
    
    for(list<char> :: iterator t= memo.begin();t!=memo.end();t++){
        cout<<*t;
    }
}
    

