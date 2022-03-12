/*
    작성자: 김지수
    작성일: 2022/03/12
    백준 -- 회의실 배정 (1931번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct meeting {
   int start;
   int end;
};
const int MAX = 100001;
vector<meeting> m;

bool compareMeeting(const meeting &a, const meeting &b) {
   if (a.end == b.end) {
      return a.start < b.start;
   } else {
      return a.end < b.end;
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int n;
   cin >> n;
   for (int i = 0; i < n; i++) {
      meeting a;
      cin >> a.start >> a.end;
      m.push_back(a);
   }
   sort(m.begin(), m.end(), compareMeeting);
   int meetingCount = 0;
   int end = 0;
   for (int i = 0; i < n; i++) {
      meeting now = m[i];
      if (end <= now.start) {
         end = now.end;
         meetingCount++;
      }
   }
   cout << meetingCount;
}