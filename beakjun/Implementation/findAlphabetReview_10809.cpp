/*
    작성자: 김지수
    작성일: 2022/03/05
    백준 -- 알파벳 찾기(10809번)
*/

#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int alphaPos[26];
   memset(alphaPos, -1, sizeof(alphaPos));

   string input;
   cin >> input;
   for (int i = 0; i < input.length(); i++) {
      int alpha = input[i] - 'a';
      if (alphaPos[alpha] == -1) {
         alphaPos[alpha] = i;
      } else {
         continue;
      }
   }
   for (int i = 0; i < 26; i++) {
      cout << alphaPos[i] << " ";
   }
}