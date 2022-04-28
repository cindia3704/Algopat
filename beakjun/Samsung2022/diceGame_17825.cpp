/*
    작성자: 김지수
    작성일: 2022/04/27
    백준 -- 주사위 윷놀이 (17825번)
    문제:
*/

#include <math.h>

#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
#define MAX 33;
using namespace std;
int maxScore = 0;
vector<int> dice;
int seq[10];
int dicePos[4] = {0, 0, 0, 0};
bool horseMove[10][4];  // 각 차례에 말 움직인적 있는지

int moveInfo[33][6] = {{0, 1, 2, 3, 4, 5},       {2, 2, 3, 4, 5, 6},
                       {4, 3, 4, 5, 6, 7},       {6, 4, 5, 6, 7, 8},
                       {8, 5, 6, 7, 8, 9},       {10, 21, 22, 23, 24, 30},
                       {12, 7, 8, 9, 10, 11},    {14, 8, 9, 10, 11, 12},
                       {16, 9, 10, 11, 12, 13},  {18, 10, 11, 12, 13, 14},
                       {20, 25, 26, 24, 30, 31}, {22, 12, 13, 14, 15, 16},
                       {24, 13, 14, 15, 16, 17}, {26, 14, 15, 16, 17, 18},
                       {28, 15, 16, 17, 18, 19}, {30, 27, 28, 29, 24, 30},
                       {32, 17, 18, 19, 20, 32}, {34, 18, 19, 20, 32, 32},
                       {36, 19, 20, 32, 32, 32}, {38, 20, 32, 32, 32, 32},
                       {40, 32, 32, 32, 32, 32}, {13, 22, 23, 24, 30, 31},
                       {16, 23, 24, 30, 31, 20}, {19, 24, 30, 31, 20, 32},
                       {25, 30, 31, 20, 32, 32}, {22, 26, 24, 30, 31, 20},
                       {24, 24, 30, 31, 20, 32}, {28, 28, 29, 24, 30, 31},
                       {27, 29, 24, 30, 31, 20}, {26, 24, 30, 31, 20, 32},
                       {30, 31, 20, 32, 32, 32}, {35, 20, 32, 32, 32, 32},
                       {0, 32, 32, 32, 32, 32}};
int calcMaxScore() {
   int horsePosition[4] = {0, 0, 0, 0};  // 처음 말 위치 = 모두 시작
   int nowScore = 0;
   bool visited[33];  // 말이 있으면 true, 없으면 false
   memset(visited, false, sizeof(visited));
   visited[0] = true;  // 0번에 말이 있다

   for (int i = 0; i < 10; i++) {
      int nextMove = dice[i];                      // 몇번 움직이는지
      int nextHorse = seq[i];                      // 말 번호
      int nowHorsePos = horsePosition[nextHorse];  // 현재위치
      int nextHorsePos =
          moveInfo[nowHorsePos][nextMove];  // 움직이고 난다음 위치
      if (nextHorsePos >= 32) {             // 도착이후는 안움직임
         nextHorsePos = 32;
      }
      int nextScore = moveInfo[nextHorsePos][0];

      if (nextHorsePos != 32 &&
          visited[nextHorsePos] ==
              true) {  // 도착이 아니고, 가려는 위치에 말이 있다면 break;
         // cout << "  score:" << -1 << endl;
         return 0;
      } else {
         nowScore += nextScore;  // 가려는곳에 말이 없으면 점수 더하기
         if (nowHorsePos != 0 ||
             nowHorsePos != 32) {  // 현재가 시작 / 도착이 아니면 움직이는거니까
                                   // 말 없다고 상태 바꾸기
            visited[nowHorsePos] = false;
         }
         visited[nextHorsePos] = true;  // 다음 자리에 말 있음
         horsePosition[nextHorse] = nextHorsePos;  // 말 위치 변경
      }
   }
   return nowScore;
}

void comb(int turn) {
   if (turn == 10) {
      maxScore = max(maxScore, calcMaxScore());
      return;
   } else {
      for (int i = 0; i < 4; i++) {  // 중복 가능하게 말 1~4까지 뽑기
         if (horseMove[turn][i] ==
             false) {  // 현재 번째에 해당 말을 아직 안뽑았으면
            seq[turn] = i;               // 말 넣고
            horseMove[turn][i] = true;   // 말 뽑았다구 업데이트
            comb(turn + 1);              // 다음 번째로
            horseMove[turn][i] = false;  // 다녀와서 백트렉킹
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(horseMove, false, sizeof(horseMove));
   memset(seq, -1, sizeof(seq));
   for (int i = 0; i < 10; i++) {
      int roll;
      cin >> roll;
      dice.push_back(roll);
   }
   comb(0);
   cout << maxScore << endl;
}