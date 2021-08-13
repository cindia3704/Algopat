/*
    작성자: 김지수
    작성일: 2021/08/13
    백준 -- 행운의 바퀴 (2840번)
    문제:
    - 바퀴에 같은 글자는 두 번 이상 등장하지 않는다
    - 바퀴는 시계방향으로만 돌아간다
    - 상덕이는 바퀴를 연속해서 K번 돌림
    - 매번 바퀴를 돌릴 때 마다, 상덕이는 화살표가 가리키는 글자가 변하는 횟수와
   어떤 글자에서 회전을 멈추었는지를 종이에 적는다
   - 희원이는 상덕이가 적어놓은 종이를 발견 ->상덕이가 바퀴에 적은 알파벳을
   알아내려고 한다.
   - 어떤 글자인지 결정하지 못하는 칸은 '?'를 출력
   - 해당하는 행운의 바퀴가 없다면 "!"를 출력
*/

#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int wheelNum, turnCount;
   cin >> wheelNum >> turnCount;

   int wheel[wheelNum];
   set<int> alphas;

   memset(wheel, -1, sizeof(wheel));

   int nowIdx = 0;
   bool noWheel = false;
   for (int i = 0; i < turnCount; i++) {
      int blockCount;
      char alphabet;
      cin >> blockCount >> alphabet;
      int writeBlock = (nowIdx + blockCount) % wheelNum;
      if (wheel[writeBlock] != -1 && wheel[writeBlock] != int(alphabet)) {
         // 이미 쓰인 칸에 다른 알파벳 넣으려 할때
         noWheel = true;
         break;
      } else {
         int originalSize = alphas.size();
         alphas.insert(int(alphabet));
         if (alphas.size() == originalSize &&
             wheel[writeBlock] != int(alphabet)) {
            // 같은 위치에 쓴 알파벳이 아닌데 알파벳 중복생겼을 경우
            noWheel = true;
            break;
         }
         wheel[writeBlock] = int(alphabet);
         nowIdx = writeBlock;
      }
   }

   if (noWheel) {
      cout << "!";
   } else {
      for (int i = 0; i < wheelNum; i++) {
         int idx = (nowIdx - i) % wheelNum;
         if (idx < 0) {
            idx = wheelNum + idx;
         }
         if (wheel[idx] == -1) {
            cout << "?";
         } else {
            cout << char(wheel[idx]);
         }
      }
   }
}