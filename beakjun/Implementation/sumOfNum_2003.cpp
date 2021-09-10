/*
    작성자: 김지수
    작성일: 2021/09/10
    백준 -- 수들의 합 2 (10950번)
    문제:N개의 수로 된 수열 A[1], A[2], …, A[N] 이 있다. 이 수열의 i번째 수부터
   j번째 수까지의 합 A[i] + A[i+1] + … + A[j-1] + A[j]가 M이 되는 경우의 수를
   구하는 프로그램
   ** TWO POINTER!!
*/

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int length, wanted;
   cin >> length >> wanted;
   vector<int> seq;
   for (int i = 0; i < length; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }
   int end = 0, count = 0, sum = 0;
   for (int i = 0; i < length; i++) {
      while (end < length && sum < wanted) {
         sum += seq[end];
         end++;
      }
      if (sum == wanted) {
         count++;
      }
      sum -= seq[i];
   }
   cout << count;
}