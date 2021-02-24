/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 열개씩 끊어 출력하기 (11721번)
    문제:알파벳 소문자와 대문자로만 이루어진 길이가 N인 단어가 주어진다.
        한 줄에 10글자씩 끊어서 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string>
using namespace std;

int main(void) {
   string input;
   getline(cin, input);
   int index = 0;
   while (index < input.length()) {
      cout << input.substr(index, 10) << '\n';
      index += 10;
   }
}