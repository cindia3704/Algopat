/*
    작성자: 김지수
    작성일: 2022/09/07
    프로그래머스 -- JadenCase 문자열 만들기 (12951번)
*/

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    string word = "";
    while(idx<s.length()){
        if(s[idx]==' '){
            word+=' ';
            answer+=word;
            word.clear();
        }else{
            if(word.empty()){
                int now = s[idx]-'0';
                if(now>=0 && now<=9){
                    word+=s[idx];
                }else{
                    word+=toupper(s[idx]);
                }
            }else{
                word+=tolower(s[idx]);
            }
        }
        idx++;
    }
    answer+=word;

    return answer;
}