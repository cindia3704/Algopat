/*
    작성자: 김지수
    작성일: 2021/10/03
    백준 -- 차이를 최대로 (10819번)
    문제:
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 9;
int seqSize;
int arr[MAX_N];
int seq[MAX_N];
bool visited[MAX_N];
int answer = -1;
int calc() {
   int sum = 0;
   for (int i = 0; i < seqSize - 1; i++) {
      sum += abs(arr[i] - arr[i + 1]);
   }
   return sum;
}

void makeCombination(int depth) {
   if (depth == seqSize) {
      int temp = calc();
      answer = (temp > answer) ? temp : answer;
   } else {
      for (int i = 0; i < seqSize; i++) {
         if (!visited[i]) {
            arr[depth] = seq[i];
            visited[i] = true;
            makeCombination(depth + 1);
            visited[i] = false;
         }
      }
   }
}
int main(void) {
   memset(visited, false, sizeof(visited));
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> seqSize;
   for (int i = 0; i < seqSize; i++) {
      cin >> seq[i];
   }
   makeCombination(0);
   cout << answer;
}