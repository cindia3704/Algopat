/*
    작성자: 김지수
    작성일: 2021/09/13
    백준 -- N과 M (2) (15650번)
    문제:
    - 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두
   구하는 프로그램
   - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
*/

#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 9;
int comb[MAX_N];
bool visited[MAX_N];
int n, m;

void dfs(int depth, int start) {
   if (depth == m) {
      for (int i = 0; i < m; i++) {
         cout << comb[i] << " ";
      }
      cout << "\n";
      return;
   }
   if (start > n) {
      return;
   } else {
      for (int i = start; i <= n; i++) {
         if (!visited[i]) {
            comb[depth] = i;
            visited[i] = true;
            dfs(depth + 1, i + 1);
            visited[i] = false;
         }
      }
   }
}

int main(void) {
   cin >> n >> m;
   memset(visited, false, sizeof(visited));
   dfs(0, 1);
}