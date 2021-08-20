/*
    작성자: 김지수
    작성일: 2021/08/21
    백준 -- 작업 (2056번)
    문제:
    - 수행해야 할 작업 N개 & 각각 수행하는데 걸리는 시간이 주어짐
    - 작업들 사이에는 선행 관계라는 게 있음
    - 모든 작업을 완료하기 위한 최소 시간을 출력하라
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10001;
int workTime[MAX_N];       // 각 노드수행할때 걸리는 시간
int cache[MAX_N];          // 노드수행까지 최대 시간
vector<int> graph[MAX_N];  // 작업 & 선행 관계

int dp(int node) {
   int& ret = cache[node];
   if (node == 1) {
      return workTime[node];  // 첫번째 노드는 선행 노드가 없어서
   }
   if (ret != -1) {
      return ret;
   } else {
      int temp = 0;
      for (int i = 0; i < graph[node].size(); i++) {
         // 모든 선행 노드까지 걸리는 시간 확인 후 최대 시간에 해당 노드수행만
         // 할때 소요 시간 더함
         int prevNode = graph[node][i];
         temp = max(temp, dp(prevNode));
      }
      ret = temp + workTime[node];
   }
   return ret;
}

int main(void) {
   memset(cache, -1, sizeof(cache));
   ios::sync_with_stdio(false);
   cin.tie(0);

   int numWork;
   cin >> numWork;
   for (int i = 1; i <= numWork; i++) {
      int time, prevNodeNum;
      cin >> time >> prevNodeNum;
      workTime[i] = time;
      for (int j = 0; j < prevNodeNum; j++) {
         int node;
         cin >> node;
         graph[i].push_back(node);
      }
   }

   int answer = 0;
   for (int i = 1; i <= numWork; i++) {
      answer = max(dp(i), answer);
   }

   cout << answer;
}