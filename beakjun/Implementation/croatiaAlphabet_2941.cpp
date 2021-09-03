/*
    작성자: 김지수
    작성일: 2021/09/04
    백준 -- 크로베티아 알파벳 (2941번)
    문제:
    - 운영체제에서 크로아티아 알파벳을 입력할 수 X
   - 입력으로 주어진 단어가 몇 개의 크로아티아 알파벳으로 이루어져 있는지
   출력하라
*/

#include <iostream>
#include <string>
using namespace std;
const string alpha[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main(void) {
   string input;
   cin >> input;
   for (int i = 0; i < 8; i++) {
      std::size_t found = input.find(alpha[i]);
      while (found != std::string::npos) {
         input.insert(found, "a");
         input.erase(found + 1, alpha[i].length());
         found = input.find(alpha[i]);
      }
   }
   cout << input.length();
}