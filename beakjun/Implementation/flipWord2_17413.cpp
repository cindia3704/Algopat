/*
    작성자: 김지수
    작성일: 2021/08/21
    백준 -- 단어 뒤집기 2 (17413번)
    문제:
    - 태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다.
    - 공백으로 구분되는 단어들을 뒤집어 출력하라
*/
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   string line;
   getline(cin, line);
   line.append("\n");  // 공백봤을때랑 같이 처리해주기 위해 추가
   string answer = "";
   stack<char> temp;

   for (int i = 0; i < line.length();) {
      temp.push(line[i]);
      if (isspace(line[i]) || i == line.length() - 1) {
         temp.pop();  // 공백 제거
         while (!temp.empty()) {
            answer.append(string(1, temp.top()));
            temp.pop();
         }
         answer.append(" ");
      }
      if (line[i] == '<') {  // tag시작 전의 단어 뒤집음
         temp.pop();         // 공백 제거
         while (!temp.empty()) {
            answer.append(string(1, temp.top()));
            temp.pop();
         }
         answer += "<";
         i++;
         while (line[i] != '>') {  // tag끝날때까지 정상 출력
            answer.append(string(1, line[i]));
            i++;
         }
         answer += '>';
      }
      i++;
   }
   cout << answer;
}