/*
    작성자: 김지수
    작성일: 2021/04/28
    백준 -- 가장 긴 바이토닉 부분 수열 (11722번)
    문제:수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ...
   SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
    - 예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은
   바이토닉 수열이지만
   - {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이
   아니다.
   - 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴
   수열의 길이를 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1000;
vector<int> seq;
vector<int> ans;
int n;

int getMaxIncreasing(int midPoint) {
   int cache[MAX_N] = {
       0,
   };
   if (midPoint == 0) {  // for문이 1부터 시작 ==> 예외!
      return 0;
   }
   int maxNum = 0;
   //가장 긴 증가하는 부분 수열 찾기!
   for (int i = 1; i <= midPoint; i++) {
      int compNum = seq[i];
      for (int j = i - 1; j >= 0; j--) {
         if (seq[j] < seq[i] && seq[j] < seq[midPoint]) {
            cache[i] = max(cache[j] + 1, cache[i]);
         }
      }
      maxNum = max(maxNum, cache[i]);
   }
   return maxNum;
}

int getMaxDecreasing(int midPoint) {
   int cache[MAX_N] = {
       0,
   };
   int maxNum = 0;
   //가장 긴 감소하는 부분수열 찾아야함 --> 뒤에서부터 보면 가장 긴 증가하는
   //부분 수열!
   for (int i = n - 2; i >= midPoint; i--) {
      int compNum = seq[i];
      for (int j = i + 1; j < n; j++) {
         if (seq[j] < seq[i] && seq[j] < seq[midPoint]) {
            cache[i] = max(cache[j] + 1, cache[i]);
         }
      }
      maxNum = max(maxNum, cache[i]);
   }
   return maxNum;
}

int main(void) {
   cin >> n;
   int answer = 0;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }

   for (int i = 0; i < n; i++) {
      //중간점 기준으로 양끝에서 가장 긴 증가하는 부분 수열 구하고 더함!
      int first = getMaxIncreasing(i);
      int second = getMaxDecreasing(i);
      answer = max(answer, (first + second));
   }
   // answer+1 하는 이유 : 1,1,1와 같은 입력 대비!
   cout << answer + 1 << endl;
}