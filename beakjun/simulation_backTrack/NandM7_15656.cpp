/*
    작성자: 김지수
    작성일: 2021/09/14
    백준 -- N과 M (7) (15649번)
    문제:
    - N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인
   수열을 모두 구하는 프로그램을 작성
        -  N개의 자연수 중에서 M개를 고른 수열
        - 같은 수를 여러 번 골라도 된다.
*/

#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 8;
int seqSize, countNum;
int choice[MAX_N];
int comb[MAX_N];

void getCombination(int depth) {
   if (depth == countNum) {
      for (int i = 0; i < depth; i++) {
         cout << comb[i] << " ";
      }
      cout << "\n";
      return;
   }

   for (int i = 0; i < seqSize; i++) {
      comb[depth] = choice[i];
      getCombination(depth + 1);
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> seqSize >> countNum;
   for (int i = 0; i < seqSize; i++) {
      cin >> choice[i];
   }
   // 결과가 사전순 이라 정렬
   sort(choice, choice + seqSize);
   getCombination(0);
}