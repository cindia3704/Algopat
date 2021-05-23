/*
    작성자: 김지수
    작성일: 2021/05/23
    백준 -- 알파벳 찾기 (10809)
    문제:
    - 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서,
   단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은
   경우에는 -1을 출력하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
   char num_char;
   string input;
   cin >> input;

   int alphabets[26];
   memset(alphabets, -1, sizeof(alphabets));

   for (int i = 0; i < input.length(); i++) {
      char letter = input[i];
      int index = letter - 'a';
      if (alphabets[index] == -1) {
         alphabets[index] = i;
      }
   }
   for (int i = 0; i < 26; i++) {
      cout << alphabets[i] << " ";
   }
}