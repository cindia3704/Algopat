/*
    작성자: 김지수
    작성일: 2021/10/23
    백준 -- 스타트 택시 (19238번)
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 21;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int boardSize, totalCustomer;
long long oilAmount;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool tempVisited[MAX_N][MAX_N];
struct Taxi {
   int y, x;
   long long usedOil;
};

struct Location {
   int sy, sx, ey, ex;
};
vector<Location> customerStartLoc;
int startY, startX;

pair<int, int> getNext(int sy, int sx) {
   vector<pair<int, int> > chooseFrom;
   queue<Taxi> t;
   memset(tempVisited, false, sizeof(tempVisited));
   Taxi start;
   start.y = sy;
   start.x = sx;
   start.usedOil = 0;
   t.push(start);
   tempVisited[sy][sx] = true;
   while (!t.empty()) {
      int nowY = t.front().y;
      int nowX = t.front().x;
      int nowUsedOil = t.front().usedOil;
      t.pop();
      if (board[nowY][nowX] > 0) {
         chooseFrom.push_back(make_pair(nowUsedOil, board[nowY][nowX] - 1));
      } else {
         for (int i = 0; i < 4; i++) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            int nextUsedOil = nowUsedOil + 1;

            if (nextY < 0 || nextX < 0 || nextY >= boardSize ||
                nextX >= boardSize) {
               continue;
            } else {
               if (!tempVisited[nextY][nextX] && board[nextY][nextX] >= 0) {
                  tempVisited[nextY][nextX] = true;
                  Taxi next;
                  next.y = nextY;
                  next.x = nextX;
                  next.usedOil = nextUsedOil;
                  t.push(next);
               }
            }
         }
      }
   }
   if (chooseFrom.size() > 0) {
      sort(chooseFrom.begin(), chooseFrom.end());
      int idx = chooseFrom[0].second;
      board[customerStartLoc[idx].sy][customerStartLoc[idx].sx] = 0;
      return chooseFrom[0];
   } else {
      return make_pair(-1, 0);
   }
}

bool comp(Location a, Location b) {
   if (a.sy != b.sy) {
      return a.sy < b.sy;
   } else {
      return a.sx < b.sx;
   }
}
long long bfs() {
   memset(visited, false, sizeof(visited));
   queue<Taxi> q;
   pair<int, int> p = getNext(startY, startX);
   if (p.first <= oilAmount && p.first != -1) {
      oilAmount -= p.first;
      Taxi s;
      s.y = customerStartLoc[p.second].sy;
      s.x = customerStartLoc[p.second].sx;
      s.usedOil = 0;
      q.push(s);
      visited[s.y][s.x] = true;
      while (!q.empty()) {
         int nowY = q.front().y;
         int nowX = q.front().x;
         long long nowUsedOil = q.front().usedOil;
         q.pop();
         if (nowUsedOil > oilAmount) {
            return -1;
         }
         if (nowY == customerStartLoc[p.second].ey &&
             nowX == customerStartLoc[p.second].ex) {
            oilAmount -= nowUsedOil;
            oilAmount += (2 * nowUsedOil);
            startY = nowY;
            startX = nowX;
            return oilAmount;
         }
         for (int i = 0; i < 4; i++) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];
            int nextUsedOil = nowUsedOil + 1;
            if (nextY < 0 || nextX < 0 || nextY >= boardSize ||
                nextX >= boardSize) {
               continue;
            } else {
               if (!visited[nextY][nextX] && board[nextY][nextX] != -1) {
                  visited[nextY][nextX] = true;
                  Taxi next;
                  next.y = nextY;
                  next.x = nextX;
                  next.usedOil = nextUsedOil;
                  q.push(next);
               }
            }
         }
      }
   } else {
      return -1;
   }
   return -1;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   // memset(doneRide, false, sizeof(doneRide));
   cin >> boardSize >> totalCustomer >> oilAmount;
   for (int i = 0; i < boardSize; i++) {
      for (int j = 0; j < boardSize; j++) {
         cin >> board[i][j];
         if (board[i][j] == 1) {
            board[i][j] = -1;
         }
      }
   }

   cin >> startY >> startX;
   startY--;
   startX--;
   for (int i = 0; i < totalCustomer; i++) {
      int sy, sx, ey, ex;
      Location loc;
      cin >> loc.sy >> loc.sx >> loc.ey >> loc.ex;
      loc.sy--;
      loc.sx--;
      loc.ey--;
      loc.ex--;
      customerStartLoc.push_back(loc);
   }
   sort(customerStartLoc.begin(), customerStartLoc.end(), comp);
   for (int i = 0; i < totalCustomer; i++) {
      Location loc = customerStartLoc[i];
      board[loc.sy][loc.sx] = i + 1;
   }
   long long ret = 0;
   for (int i = 0; i < totalCustomer; i++) {
      ret = bfs();
      if (ret == -1) {
         break;
      }
   }
   cout << ret;
}