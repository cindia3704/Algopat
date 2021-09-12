/*
    작성자: 김지수
    작성일: 2021/09/12
    백준 -- N과 M (1) (15649번)
    문제:
    - 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두
   구하는 프로그램
   - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 9;
bool visited[MAX_N];
int number, length;
int com[MAX_N];

void dfs(int count) {
   if (count == length) {
      for (int i = 0; i < length; i++) {
         cout << com[i] << " ";
      }
      cout << "\n";
      return;
   } else {
      for (int i = 1; i <= number; i++) {
         if (!visited[i]) {
            visited[i] = true;
            com[count] = i;
            dfs(count + 1);
            visited[i] = false;
         }
      }
   }
}

int main(void) {
   cin >> number >> length;
   memset(visited, false, sizeof(visited));
   dfs(0);
}