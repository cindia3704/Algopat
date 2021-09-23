/*
    작성자: 김지수
    작성일: 2021/09/24
    programmers -- k번째 수 (42748번)
*/
#include <string>
#include <vector>

using namespace std;
vector<int> sortV(vector<int> t) {
   for (int i = 0; i < t.size(); i++) {
      for (int j = i + 1; j < t.size(); j++) {
         if (t[i] > t[j]) {
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
         }
      }
   }
   return t;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
   vector<int> answer;
   for (int i = 0; i < commands.size(); i++) {
      int start = commands[i][0] - 1;
      int end = commands[i][1] - 1;
      int k = commands[i][2] - 1;
      vector<int> temp;
      for (int j = start; j <= end; j++) {
         temp.push_back(array[j]);
      }
      temp = sortV(temp);
      answer.push_back(temp[k]);
   }
   return answer;
}