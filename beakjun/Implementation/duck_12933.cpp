/*
    작성자: 김지수
    작성일: 2021/08/18
    백준 -- 감시(15683번)
    문제:
    - 오리의 울음 소리= "quack"
    - 오리 소리 녹음 후, 들으며 오리의 최소 수를 구하려 함
    - CCTV가 감시할 수 없는 영역은 사각지대라고 한다
    - "quqacukqauackck"과 같은 경우는 두 오리가 울었다고 볼 수 있다
*/

#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
const char duck[] = {'q', 'u', 'a', 'c', 'k'};

int main(void) {
   string sound;
   cin >> sound;
   queue<char> soundQ;
   // 녹음내용 처음부터 끝까지 큐에 넣기
   for (int i = 0; i < sound.length(); i++) {
      soundQ.push(sound[i]);
   }

   int duckNum = 0;  // 오리 수
   bool hasNext = true;
   int idx = 0;   // 울음소리 비교 위한 인덱스
   int count[5];  // quack의 모든 개수가 같아야함
   memset(count, 0, sizeof(count));

   while (hasNext == true && !soundQ.empty()) {
      idx = 0;  // 반례: quackquakc <- 여기서 idx 초기화 안해주면 idx =2여서
                // 조건 통과하게됨
      queue<char> temp;
      hasNext = false;
      while (!soundQ.empty()) {
         char now = soundQ.front();
         soundQ.pop();
         if (now == duck[idx]) {
            count[idx]++;
            if (idx == 4) {  // quack 한번 들었을때 -> 인덱스 초기화
               idx = 0;
               hasNext = true;
            } else {
               idx++;
            }
         } else {
            // 현재 문자와 들어야하는 알파벳이 다른 경우 다른 큐에 넣음
            temp.push(now);
         }
      }
      if (hasNext) {
         duckNum++;
      }
      soundQ = temp;
   }

   if (!soundQ.empty() || idx != 0 || count[0] != count[1] ||
       count[1] != count[2] || count[2] != count[3] || count[3] != count[4]) {
      cout << -1;
   } else {
      cout << duckNum;
   }
}