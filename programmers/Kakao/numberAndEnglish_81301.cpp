/*
    작성자: 김지수
    작성일: 2021/09/04
    Programmers -- 숫자 문자열과 영단어 (81301번)
*/

#include <string>
#include <vector>

using namespace std;
const string numbers[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
const string numbersString[10] = {"zero", "one", "two",   "three", "four",
                                  "five", "six", "seven", "eight", "nine"};

int solution(string s) {
   int answer = 0;

   for (int i = 0; i < 10; i++) {
      std::size_t pos = s.find(numbersString[i]);
      while (pos != std::string::npos) {
         s.insert(pos, numbers[i]);
         s.erase(pos + 1, numbersString[i].length());
         pos = s.find(numbersString[i]);
      }
   }
   answer = stoi(s);
   return answer;
}