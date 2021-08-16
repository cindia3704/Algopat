/*
    작성자: 김지수
    작성일: 2021/08/16
    백준 -- 마법사 상어와 비바라기 (21610번)
    문제:
    - NxN 격자에서 비바라기 마법 연습하려함
    - A[r][c]는 (r, c)에 있는 바구니에 저장되어 있는 물의 양
    - 비바라기를 시전하면 (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 생김
    - 1부터 순서대로 ←, ↖, ↑, ↗, →, ↘, ↓, ↙ 방향(di)
    - 1) 구름이 di방향으로 si만큼 움직임 & 물 양 1증가
    - 2)구름이 모두 사라진다
    - 3)물이 증가한 칸 (r, c)에 대각선 방향에 물이 있는 바구니의 수만큼 바구니의
   물이 양 증가
    - 4)바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생김 & 물 양 2 감소
    - 5)이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한
*/

#include <cstring>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int diagX[] = {-1, 1, 1, -1};
const int diagY[] = {-1, -1, 1, 1};
const int MAX_N = 50;
int boardSize, command;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<pair<int, int> > rain;
vector<pair<int, int> > nextCor;
deque<pair<int, int> > clouds;

// 현재 보드에 있는 물 합 계산
int countWater(int boardSize) {
   int sum = 0;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         sum += board[i][j];
      }
   }
   return sum;
}

// board를 boardTemp에 복사
void copyBoard(int board[MAX_N][MAX_N], int boardTemp[MAX_N][MAX_N]) {
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         boardTemp[i][j] = board[i][j];
      }
   }
}

// 다음 구름 위치 계산 <- 이전에 비 내렸던 곳이면 안됨 & 물이 2이상 -> 구름 생성
// 후 비가 2만큼 온다
void getNextCloudSet() {
   deque<pair<int, int> > temp;

   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         if (board[i][j] >= 2 && visited[i][j] == false) {
            pair<int, int> p = make_pair(i, j);
            temp.push_back(p);
            board[i][j] -= 2;
         }
      }
   }
   clouds = temp;
}

// 대각선에 물있는지 확인 & 물있는 대각선 칸 개수 만큼 물 증가
// & visited 처리 <- 다음 구름 세트 구할때 사용
void checkDiag(int boardTemp[MAX_N][MAX_N]) {
   for (int j = 0; j < nextCor.size(); j++) {
      int countWater = 0;
      for (int i = 0; i < 4; i++) {
         int diagonalX = nextCor[j].second + diagX[i];
         int diagonalY = nextCor[j].first + diagY[i];
         if (diagonalY < 0 || diagonalY >= boardSize || diagonalX < 0 ||
             diagonalX >= boardSize) {
            continue;
         }
         if (boardTemp[diagonalY][diagonalX] > 0) {
            countWater++;
         }
      }
      boardTemp[nextCor[j].first][nextCor[j].second] += countWater;

      visited[nextCor[j].first][nextCor[j].second] = true;
   }
}

void bfs(int commandNum) {
   nextCor.clear();  // 대각선 위치 체크할 위치들 매 라운드마다 초기화

   if (commandNum == command) {  // 비바람 다 불면 리턴
      return;
   }

   memset(visited, false, sizeof(visited));
   int boardTemp[MAX_N][MAX_N];
   copyBoard(board, boardTemp);  // 현재 단계의 비바람일때 보드 복사해놓기

   while (!clouds.empty()) {
      int nowX = clouds.front().second;
      int nowY = clouds.front().first;
      int dir = rain[commandNum].first;
      int speed = rain[commandNum].second;

      int nextX, nextY;
      // 구름 움질일때 보드의 왼&오 + 위&아래 연결되게끔
      if (nowX + dx[dir] * speed < 0) {
         nextX = (abs(boardSize + (nowX + dx[dir] * speed) % boardSize)) %
                 boardSize;
      } else {
         nextX = (nowX + dx[dir] * speed) % boardSize;
      }
      if (nowY + dy[dir] * speed < 0) {
         nextY = (abs(boardSize + (nowY + dy[dir] * speed) % boardSize)) %
                 boardSize;
      } else {
         nextY = (nowY + dy[dir] * speed) % boardSize;
      }

      boardTemp[nextY][nextX] += 1;  // 구름 움직인 위치에 비 1만큼 내림
      nextCor.push_back(make_pair(nextY, nextX));  // 대각선 체크하기 위해
      clouds.pop_front();
   }

   checkDiag(boardTemp);
   copyBoard(boardTemp, board);
   getNextCloudSet();
   bfs(commandNum + 1);
}

int main(void) {
   cin >> boardSize >> command;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         cin >> board[i][j];
      }
   }
   for (int i = 0; i < command; i++) {
      int dir, speed;
      cin >> dir >> speed;
      rain.push_back(make_pair(dir - 1, speed));
   }
   // 초기 구름 위치
   clouds.push_back(make_pair(boardSize - 1, 0));
   clouds.push_back(make_pair(boardSize - 1, 1));
   clouds.push_back(make_pair(boardSize - 2, 0));
   clouds.push_back(make_pair(boardSize - 2, 1));

   bfs(0);  // 넘겨주는 인자는 몇번째 비바람인지
   cout << countWater(boardSize);
}
