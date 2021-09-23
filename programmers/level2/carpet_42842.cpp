/*
    작성자: 김지수
    작성일: 2021/09/24
    programmers -- 카펫(42842번)
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long finalH, finalW;
bool found = false;
void checkBrown(int width, int height, int brown, int yellow) {
   int finalSum = height * 2 + width * 2 + 4;
   int tempH = height + 2;
   int tempW = width + 2;
   if (finalSum == brown && (tempH * tempW) == (brown + yellow)) {
      finalH = height + 2;
      finalW = width + 2;
      found = true;
   }
}

vector<int> solution(int brown, int yellow) {
   vector<int> answer;

   for (int i = 1; i <= yellow; i++) {
      if (!found) {
         int w = yellow / i;
         int h = i;
         checkBrown(w, h, brown, yellow);
      }
   }
   answer.push_back(finalW);
   answer.push_back(finalH);
   return answer;
}