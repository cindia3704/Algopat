/*
    작성자: 김지수
    작성일: 2022/09/07
    백준 -- 단어 뒤집기 2 (17413번)
*/

#include <iostream>
#include <stack>
using namespace std; 
stack<char> st;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; 
    getline(cin,s);
    int i = 0;
    while(i<s.length()){
        if(s[i] == '<'){
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            while(s[i]!='>'){
                cout<<s[i];
                i++;
            }
        }
        else if(s[i]=='>'){
            cout<<s[i];
            i++;
        }
        else if(s[i] == ' '){
          
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<s[i];
            i++;
        }else{
            st.push(s[i]);
            i++;
        }
    }
    while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
}