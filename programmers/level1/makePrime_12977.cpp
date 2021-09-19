/*
    작성자: 김지수
    작성일: 2021/09/19
    programmers -- 소수 만들기 (12977번)
*/
#include <iostream>
#include <vector>
using namespace std;
int answer = 0;
bool visited[1001];
int com[3];

bool isPrime(int n) {
   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
         return false;
      }
   }
   return true;
}

void makeComb(vector<int> nums, int depth, int start) {
   if (depth == 3) {
      int sum = 0;
      for (int i = 0; i < 3; i++) {
         sum += com[i];
      }
      if (isPrime(sum) == true) {
         answer++;
      }
      return;
   }
   if (start > nums.size()) {
      return;
   } else {
      for (int i = start; i < nums.size(); i++) {
         if (!visited[i]) {
            visited[i] = true;
            com[depth] = nums[i];
            makeComb(nums, depth + 1, i + 1);
            visited[i] = false;
         }
      }
   }
}

int solution(vector<int> nums) {
   fill(visited, visited + 1001, false);
   makeComb(nums, 0, 0);
   return answer;
}