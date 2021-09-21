/*
    작성자: 김지수
    작성일: 2021/09/21
    programmers -- 모의고사 (42840번)
*/
#include <algorithm>
#include <string>
#include <vector>
const int one[] = {1, 2, 3, 4, 5};
const int two[] = {2, 1, 2, 3, 2, 4, 2, 5};
const int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
using namespace std;

vector<int> solution(vector<int> answers) {
   vector<int> answer;
   int studentOneSize = 5;
   int studentTwoSize = 8;
   int studentThreeSize = 10;
   int countAnswer[3];
   fill(countAnswer, countAnswer + 3, 0);
   for (int i = 0; i < answers.size(); i++) {
      if (answers[i] == one[i % studentOneSize]) {
         countAnswer[0]++;
      }
      if (answers[i] == two[i % studentTwoSize]) {
         countAnswer[1]++;
      }
      if (answers[i] == three[i % studentThreeSize]) {
         countAnswer[2]++;
      }
   }
   int maxNum = *max_element(countAnswer, countAnswer + 3);
   for (int i = 0; i < 3; i++) {
      if (countAnswer[i] == maxNum) {
         answer.push_back(i + 1);
      }
   }
   return answer;
}