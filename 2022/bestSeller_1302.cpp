/*
    작성자: 김지수
    작성일: 2022/08/04
    백준 -- 베스트셀러 (1302번)
*/

#include <iostream>
#include <unordered_map>
using namespace std; 

unordered_map<string,int> books;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int bookCnt;
    cin>>bookCnt;
    for(int i=0;i<bookCnt;i++){
        string bookName; 
        cin>>bookName;
        unordered_map<string,int> ::iterator it = books.find(bookName);
        if(it==books.end()){
            // 찾을 수 없으면 책 개수 1로 넣음  
            books.insert(make_pair(bookName,1));
        }else{
            // 찾을 수 있으면 책 개수 ++ 
            it->second++;
        }
    }
    int maxCnt = 0;
    string name = "";
    // 모든 원소 돌면서 
    for(unordered_map<string,int>:: iterator i = books.begin();i!=books.end();i++){
        // 개수가 현재최대보다 크면 업데이트 
        if((i->second) > maxCnt){
            maxCnt = i->second;
            name = i->first;
        }else if((i->second) == maxCnt){
            // 현재최대랑 같으면 사전순이 책 이름 
            if((i->first).compare(name)<0){
                name = i->first;
            }
        }
    }
    cout<<name;
}
