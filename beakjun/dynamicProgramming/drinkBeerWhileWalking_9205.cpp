/*
    작성자: 김지수
    작성일: 2021/06/25
    백준 -- 맥주 마시면서 걸어가기 (9205번)
    문제:
    - 송도에 사는 상근이와 친구들은 송도에서 열리는 펜타포트 락 페스티벌에
   가려고 한다
    -출발은 상근이네 집에서 하고, 맥주가 20개 들어있는 박스 한개를 들고 가며,
   50미터에 한 병씩 마시려고 한다
    -  편의점에 들렸을 때, 빈 병은 버리고 새 맥주 병을 살 수 있다.
    -  0은 빈 칸, 1은 벽, 2는 바이러스의 위치이다.
    - 편의점, 상근이네 집, 펜타포트 락 페스티벌의 좌표가 주어진다.
    - 상근이와 친구들이 행복하게 페스티벌에 갈 수 있으면 "happy", 중간에 맥주가
   바닥나서 더 이동할 수 없으면 "sad"를 출력하라
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int storeNum;
const int MAX_N = 102;
vector<pair<int, int> > all;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];
bool found = false;

void dfs(int start, int end) {
   visited[start] = true;
   //목적지 도착
   if (start == end) {
      found = true;
      return;
   }

   // 현 위치에서 맥주 20개로 갈수 있는 노드 찾기
   for (int i = 0; i < storeNum + 2; i++) {
      if (graph[start][i] == 1 && visited[i] == false) {
         dfs(i, end);
      }
   }
}

int main(void) {
   int testcase;
   cin >> testcase;
   while (testcase--) {
      // testcase 마다 초기화
      memset(graph, 0, sizeof(graph));
      memset(visited, false, sizeof(visited));
      cin >> storeNum;
      // 편의점 개수 + 시작 & 끝 좌표
      for (int i = 0; i < storeNum + 2; i++) {
         int x, y;
         cin >> x >> y;
         all.push_back(make_pair(x, y));
      }

      // 어느게 시작위치 앞/뒤에 있는지 모름! 따라서 일단 각 좌표에 도달
      // 가능한지 확인
      for (int i = 0; i < all.size() - 1; i++) {
         for (int j = 0; j < all.size(); j++) {
            if ((abs(all[i].first - all[j].first) +
                 abs(all[i].second - all[j].second)) <= 1000) {
               graph[i][j] = 1;
            }
         }
      }
      // 시작 위치 (node 0)부터 dfs 탐색해서 도착점까지 갈수 있는지 확인
      dfs(0, storeNum + 1);
      cout << ((found == true) ? "happy" : "sad") << endl;

      // testcase 마다 초기화
      all.clear();
      found = false;
   }
}
