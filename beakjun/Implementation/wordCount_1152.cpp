/*
    작성자: 김지수
    작성일: 2021/07/31
    백준 -- 단어의 개수 (1152번)
    문제:
    - 영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다
    - 문자열에는 몇 개의 단어가 있을까?
    - 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다
    - 문자열의 앞과 뒤에는 공백이 있을 수도 있다
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int ans = 1;
int main(void) {
   string str;
   getline(cin, str);
   bool wordFound = false;
   for (int i = 0; i < str.length(); i++) {
      if (str[i] == ' ') {
         ans++;
      }
   }
   if (str[0] == ' ') {
      ans--;
   }
   if (str[str.length() - 1] == ' ') {
      ans--;
   }

   cout << ans;
}