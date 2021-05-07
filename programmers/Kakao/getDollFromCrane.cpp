
/*
    작성자: 김지수
    작성일: 2021/05/07
    프로그래머스 -- 크레인 인형 뽑기
    문제:
    - 게임 화면은 "1 x 1" 크기의 칸들로 이루어진 "N x N" 크기의 정사각
    격자이며 위쪽에는 크레인이 있고 오른쪽에는 바구니가 있습니다.
    - 각 격자 칸에는 다양한 인형이 들어 있으며 인형이 없는 칸은 빈칸입니다
    - 모든 인형은 "1 x 1" 크기의 격자 한 칸을 차지하며 격자의 가장 아래 칸부터
   차곡차곡 쌓여 있습니다.
   - 게임 사용자는 크레인을 좌우로 움직여서 멈춘 위치에서 가장 위에 있는 인형을
   집어 올릴 수 있습니다. 집어 올린 인형은 바구니에 쌓이게 되는 데, 이때
   바구니의 가장 아래 칸부터 인형이 순서대로 쌓이게 됩니다.
   - 만약 같은 모양의 인형 두 개가 바구니에 연속해서 쌓이게 되면 두 인형은
   터뜨려지면서 바구니에서 사라지게 됩니다.
   -  크레인을 모두 작동시킨 후 터트려져 사라진 인형의 개수를 return 하도록
   solution 함수를 완성해주세요.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves) {
   vector<int> basket;
   int answer = 0;
   int height = board.size();
   int width = board[0].size();

   for (int i = 0; i < moves.size(); i++) {
      int x = moves[i] - 1;
      int j = 0;
      bool pushed = false;
      while (!pushed && j < height) {
         if (board[j][x] == 0) {
            j++;
            continue;
         }
         if (board[j][x] != 0) {
            basket.push_back(board[j][x]);
            if (basket.size() > 1 && board[j][x] == basket[basket.size() - 2]) {
               basket.pop_back();
               basket.pop_back();
               answer += 2;
            }
            board[j][x] = 0;
            pushed = true;
         }
      }
   }
   return answer;
}