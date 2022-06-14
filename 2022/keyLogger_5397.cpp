/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 키로거 (5397번)
*/

#include <iostream>
#include <list>
using namespace std; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int testCase; 
    cin>>testCase;
    
    while(testCase--){
        list<char> pw; 
        list<char> ::iterator it = pw.begin();
        string input; 
        cin>>input;
        for(int i=0;i<input.size();i++){
            if(input[i] == '-'){
                if(it!=pw.begin()){
                    it--;
                    it = pw.erase(it);
                }
            }else if(input[i] =='>'){
                if(it!=pw.end()){
                    it++;
                }

            }else if(input[i] == '<'){
                if(it!=pw.begin()){
                    it--;
                }

            }else{
                pw.insert(it,input[i]);
            }
        }
        for(list<char> :: iterator t=pw.begin();t!=pw.end();t++){
            cout<<*t;
        }
        cout<<'\n';
        pw.clear();
    }

}