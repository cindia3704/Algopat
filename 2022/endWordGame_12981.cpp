/*
    작성자: 김지수
    작성일: 2022/09/18
    프로그래머스 -- 영어 끝말잇기 (12981번)
*/

#include <string>
#include <vector>
#include <iostream>
#include <set> 

using namespace std;
set<string> wordList; 

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int turn = 1; 
    int people = 1;
    string prev = words[0];
    wordList.insert(words[0]);
    bool found = false;
    for(int i=1;i<words.size();i++){
        if(people==0){
            turn++;
        }
      
        if(prev[prev.length()-1]!=words[i][0]){
            found = true;
            break;
        }else if(words[i].length()<=1){
            found = true;
            break;
        }else{
            set<string> :: iterator it = wordList.find(words[i]);
            if(it!=wordList.end()){
                found = true;
                break;
            }else{
                wordList.insert(words[i]);
                people = (people+1)%n;
                prev = words[i];
            }
        }
    }
    if(!found){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        answer.push_back(people+1);
        answer.push_back(turn);
    }
    return answer;
}