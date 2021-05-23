/*
    작성자: 김지수
    작성일: 2021/05/23
    백준 -- 알파벳 개수 (10808)
    문제:
    - 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가
   포함되어 있는지 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
   string input;
   cin >> input;
   int alphabets[26];
   memset(alphabets, 0, sizeof(alphabets));

   for (int i = 0; i < input.length(); i++) {
      char letter = input[i];
      int index = letter - 'a';
      alphabets[index]++;
   }

   for (int i = 0; i < 26; i++) {
      cout << alphabets[i] << " ";
   }
}