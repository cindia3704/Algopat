/*
    작성자: 김지수
    작성일: 2022/06/13
    백준 -- Strfry (11328번)
*/

#include <iostream>
#include <cstring> 
#define ALPHA 26 
using namespace std; 

int freq[ALPHA];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 

    int n; 
    cin>>n;
    for(int i=0;i<n;i++){
        memset(freq,0,sizeof(freq));
        string a,b;
        cin>>a>>b;
        if(a.length()!=b.length()){
            cout<<"Impossible"<<'\n';
        }else{
            for(int j=0;j<a.length();j++){
                freq[a[j]-'a']++;
            }
            bool possible = true;
            for(int j=0;j<b.length();j++){
                if(freq[b[j]-'a'] >0){
                    freq[b[j]-'a']--;
                }else{
                    possible = false;
                    break;
                }
            }
            if(possible){
                cout<<"Possible"<<'\n';
            }else{
                 cout<<"Impossible"<<'\n';
            }
        }
    }
}