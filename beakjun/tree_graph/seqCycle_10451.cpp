/*
    작성자: 김지수
    작성일: 2021/09/19
    백준 -- 순열 사이클 (13460번)
    문제:
    - 1부터 N까지 정수 N개로 이루어진 순열이 주어질때 사이클 개수 구하라
*/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1001;
bool visited[MAX_N];
int sequence[MAX_N];
int getCycle(int start) {
   visited[start] = true;
   int next = sequence[start];
   while (true) {
      visited[next] = true;
      if (next == start) {
         break;
      }
      next = sequence[next];
   }
   return 1;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int tc;
   cin >> tc;
   while (tc--) {
      int seqLength;
      cin >> seqLength;
      memset(sequence, -1, sizeof(sequence));
      memset(visited, false, sizeof(visited));
      for (int i = 1; i <= seqLength; i++) {
         cin >> sequence[i];
      }
      int sum = 0;
      for (int i = 1; i <= seqLength; i++) {
         if (!visited[i]) {
            sum += getCycle(i);
         }
      }
      cout << sum << endl;
   }
}