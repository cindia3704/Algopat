/*
    작성자: 김지수
    작성일: 2022/06/14
    백준 -- 요세푸스 문제 (1158번)
*/

#include <iostream>
#include <list>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    
    list<int> seq; 
    for(int i=1;i<=n;i++){
        seq.push_back(i);
    }
    list<int> :: iterator it = seq.begin();
    it --;
    cout<<"<"; 
    while(!seq.empty()){
        for(int i=0;i<k;i++){
            it++;
            if(it == seq.end()){
                it = seq.begin();
            }
        }
        if(seq.size() ==1){
            cout<<*it<<">";
        }else{
            cout<<*it<<", ";
        }
        it=seq.erase(it);
        it--;
    }
}