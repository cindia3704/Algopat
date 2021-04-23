/*
    작성자: 김지수
    작성일: 2021/04/24
    백준 -- 스타트와 링크 (14889번)
    문제:
    - 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은
    총 N명이고 신기하게도 N은 짝수이다.
    - 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.
    - 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는
    능력치이다.
    - 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를
   수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는
   능력치는 Sij와 Sji이다.
   - 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.
*/

#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_PLAYER = 20 + 1;
int graph[MAX_PLAYER][MAX_PLAYER];
int totalPlayer;
int minVal = 987654321;
vector<int> group1;
bool visited[MAX_PLAYER];

void findMinDiff(int numPeople, int startNode) {
   group1.push_back(startNode);
   visited[startNode] = true;

   if (numPeople == totalPlayer / 2) {
      vector<int> group2;
      int group1Sum = 0;
      int group2Sum = 0;

      // group1에 없는건 다 group2로 넣음
      for (int i = 1; i <= totalPlayer; i++) {
         if (find(group1.begin(), group1.end(), i) == group1.end()) {
            group2.push_back(i);
         }
      }

      // 1,2,3이 그룹이면 (1,2)+(2,1)+(1,3)+(3,1)+(2,3)+(3,2)가 groupSum이 된다.
      for (int j = 0; j < totalPlayer / 2 - 1; j++) {
         for (int i = j + 1; i < totalPlayer / 2; i++) {
            group1Sum += graph[group1[j]][group1[i]];
            group1Sum += graph[group1[i]][group1[j]];

            group2Sum += graph[group2[j]][group2[i]];
            group2Sum += graph[group2[i]][group2[j]];
         }
      }

      int diff = abs(group1Sum - group2Sum);
      minVal = min(diff, minVal);
   }

   for (int i = startNode + 1; i <= totalPlayer; i++) {
      if (!visited[i]) {
         findMinDiff(numPeople + 1, i);
         group1.erase(remove(group1.begin(), group1.end(), i));
         visited[i] = false;
      }
   }
}

int main(void) {
   memset(visited, false, sizeof(visited));
   cin >> totalPlayer;
   for (int i = 1; i <= totalPlayer; i++) {
      for (int j = 1; j <= totalPlayer; j++) {
         int strength;
         cin >> strength;
         graph[i][j] = (strength);
      }
   }
   findMinDiff(1, 1);
   cout << minVal << endl;
}