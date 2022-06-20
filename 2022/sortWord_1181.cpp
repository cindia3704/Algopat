/*
    작성자: 김지수
    작성일: 2022/06/21
    백준 -- 단어 정렬 (1181번)
*/

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

vector<pair<int, string> > wordList;

bool compareWord(const pair<int,string> &a, const pair<int,string> &b){
    if(a.first<b.first){
        return true;
    }
    else if(a.first == b.first){
        if(a.second<b.second){
            return true;
        }else{
            return false;
        }
    }else {
        return false;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int wordCount; 
    cin>>wordCount; 
    for(int i=0;i<wordCount;i++){
        string word;
        cin>>word;
        wordList.push_back(make_pair(word.length(),word));
    }

    sort(wordList.begin(),wordList.end(),compareWord);
    string last = "";
    for(int i=0;i<wordList.size();i++){
        if(last == wordList[i].second){
            continue;
        }
        cout<<wordList[i].second<<'\n';
        last = wordList[i].second;
    }
}