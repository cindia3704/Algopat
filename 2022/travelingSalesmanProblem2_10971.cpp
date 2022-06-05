/*
    작성자: 김지수
    작성일: 2022/06/05
    백준 -- 외판원 순회2 (1182번)
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#define MAX 11
using namespace std;
int totalCity;
int cost = 987654321;
int weight[MAX][MAX];
bool visited[MAX];

void makeComb(int nowPick, int nowNode, int nowSum, int start) {
   // 시작점 정해져있으니, 그후 방문하는 개수 = 총 도시 -1
   if (nowPick == totalCity - 1) {
      // 마지막 도시에서 시작도시로 갈수 있어야함
      if (weight[nowNode][start] != 0) {
         nowSum += weight[nowNode][start];
         // 지금까지 구한 비용보다 작을경우 업데이트
         if (nowSum < cost) {
            cost = nowSum;
         }
      }
      return;
   } else {
      // 모든 도시 돌며 방문 안한 도시를 다음 후보로 봄
      for (int i = 0; i < totalCity; i++) {
         if (visited[i] == false) {
            // 현 도시에서 다음 도시로 갈수 있어야함
            if (weight[nowNode][i] == 0) {
               continue;
            } else {
               // 방문처리
               visited[i] = true;
               makeComb(nowPick + 1, i, nowSum + weight[nowNode][i], start);
               visited[i] = false;
            }
         }
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> totalCity;
   for (int i = 0; i < totalCity; i++) {
      for (int j = 0; j < totalCity; j++) {
         cin >> weight[i][j];
      }
   }
   for (int i = 0; i < totalCity; i++) {
      // 시작점으로 돌아와야하기 때문에 시작점 지정 & 방문처리
      memset(visited, false, sizeof(visited));
      visited[i] = true;
      makeComb(0, i, 0, i);
   }
   cout << cost;
}