/*
    작성자: 김지수
    작성일: 2022/06/11
    백준 -- 가르침 (1062번)
*/

#include <cstring>
#include <iostream>
#include <vector>
#define ALPHA 26
using namespace std;

int wordCount, alphabetCount;
vector<string> wordList;
bool learned[ALPHA];
int answer = 0;

void checkWord() {
   int canReadCount = 0;
   for (int i = 0; i < wordCount; i++) {
      bool canRead = true;
      for (int j = 0; j < wordList[i].length(); j++) {
         if (learned[wordList[i][j] - 'a'] == false) {
            canRead = false;
            break;
         }
      }
      if (canRead) {
         canReadCount++;
      }
   }
   // max 값 업데이트
   if (canReadCount > answer) {
      answer = canReadCount;
   }
   return;
}

void makeComb(int pickCount, int start) {
   if (pickCount > alphabetCount) {
      return;
   } else if (pickCount == alphabetCount) {
      // 필요한 알파벳 방문후 해당 알파벳 배울시 몇개의 단어 읽을수 있는지 확인
      checkWord();
      return;
   } else {
      // 모든 알파벳 돌면서 아직 방문 안한 알파벳 방문
      for (int i = start; i < ALPHA; i++) {
         if (learned[i] == false) {
            learned[i] = true;
            makeComb(pickCount + 1, i + 1);
            learned[i] = false;
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> wordCount >> alphabetCount;

   for (int i = 0; i < wordCount; i++) {
      string word;
      cin >> word;
      // 시간초과 해결위해서 anta, tica로 모든 단어가 시작 & 끝나니 이부분 제거
      string part = word.substr(4, word.size() - 8);
      wordList.push_back(part);
   }

   if (alphabetCount < 5) {
      cout << 0;
      return 0;
   }

   // antic는 무조건 들어가니, 방문처리
   memset(learned, false, sizeof(learned));
   learned['a' - 'a'] = true;
   learned['n' - 'a'] = true;
   learned['t' - 'a'] = true;
   learned['i' - 'a'] = true;
   learned['c' - 'a'] = true;

   // 위 다섯 알파벳 사용했으니 pickCount =5로 시작
   makeComb(5, 0);
   cout << answer;
}