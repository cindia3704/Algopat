/*
    작성자: 김지수
    작성일: 2022/03/18
    programmers -- 기능개발(42586번)
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getDays(int prgress, int speed) {
   double temp = 100 - prgress;
   double ans = ceil(temp / speed);
   return ans;
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
   if (a.first == b.first) {
      return a.second < b.second;
   }
   return a.first < b.first;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
   vector<int> answer;
   vector<pair<int, int> > t;
   for (int i = 0; i < progresses.size(); i++) {
      int days = getDays(progresses[i], speeds[i]);
      t.push_back(make_pair(i, days));
   }

   sort(t.begin(), t.end(), compare);
   int count = 1;
   int prevDMax = t[0].second;
   for (int i = 1; i < t.size(); i++) {
      pair<int, int> now = t[i];
      if (now.second > prevDMax) {
         answer.push_back(count);
         count = 1;
         prevDMax = now.second;
      } else {
         count++;
      }
   }
   answer.push_back(count);

   return answer;
}