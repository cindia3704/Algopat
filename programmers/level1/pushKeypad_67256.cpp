/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 키패드 누르기 (67256번)
*/

#include <algorithm>
#include <string>
#include <vector>

using namespace std;
const string l = "L";
const string r = "R";

string solution(vector<int> numbers, string hand) {
   string answer = "";
   int nowLeft = 10;
   int nowRight = 12;
   for (int i = 0; i < numbers.size(); i++) {
      int nowNum = numbers[i];
      if (nowNum == 0) {
         nowNum = 11;
      }
      if (nowNum % 3 == 1) {
         nowLeft = nowNum;
         answer.append(l);
      } else if (nowNum % 3 == 0) {
         nowRight = nowNum;
         answer.append(r);
      } else {
         int tempL = abs(nowLeft - nowNum);
         int tempR = abs(nowRight - nowNum);

         int leftDistance = tempL / 3 + tempL % 3;
         int rightDistance = tempR / 3 + tempR % 3;
         if (leftDistance == rightDistance) {
            if (hand == "right") {
               answer.append(r);
               nowRight = nowNum;
            } else {
               answer.append(l);
               nowLeft = nowNum;
            }
         } else if (leftDistance < rightDistance) {
            answer.append(l);
            nowLeft = nowNum;
         } else {
            answer.append(r);
            nowRight = nowNum;
         }
      }
   }
   return answer;
}