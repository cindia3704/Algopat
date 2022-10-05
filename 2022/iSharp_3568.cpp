/*
    작성자: 김지수
    작성일: 2022/10/06
    백준 -- iSharp (3568번)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    getline(cin,s);

    char arr[s.length()+1];
    strcpy(arr,s.c_str());
    char *p = strtok(arr," ");
    vector<string> datas;

    while(p){
        datas.push_back(p);
        p = strtok(NULL," ,;");
    }

    for(int i=1;i<datas.size();i++){
        string now = datas[i];
        string additionalDT="";
        string nowRealData="";
        bool found = false;

        for(int j=0;j<now.length();j++){
            if(now[j]!='*' && now[j]!='&' && now[j]!='['&&now[j]!=']'){
                nowRealData+=now[j];
            }else{
                found = true;
                if(now[j]=='['){
                    additionalDT+=']';
                }else if(now[j]==']'){
                    additionalDT+='[';
                }else{
                    additionalDT += now[j];
                }
            }
        }
        
        reverse(additionalDT.begin(),additionalDT.end());
        cout<<datas[0]<<additionalDT<<" "<<nowRealData<<";\n";
    }
}