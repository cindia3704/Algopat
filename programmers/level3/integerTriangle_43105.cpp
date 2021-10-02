/*
    작성자: 김지수
    작성일: 2021/09/25
    programmers -- 정수 삼각형 (43105번)
    // 주의!! triangle을 dp 매개변수로 넘겨주면 효율설 하나도 통과 못함!!
   전역으로 빼주자!
*/

#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
const int MAX_N = 501;
int cache[MAX_N][MAX_N];
vector<vector<int>> t;

int dp(int y, int x) {
   int &ret = cache[y][x];

   if (y == t.size() - 1) {
      return t[y][x];
   }
   if (ret != -1) {
      return ret;
   } else {
      int temp1 = dp(y + 1, x) + t[y][x];
      int temp2 = dp(y + 1, x + 1) + t[y][x];
      ret = max(temp1, temp2);
   }
   return ret;
}

int solution(vector<vector<int>> triangle) {
   int answer = 0;
   t = triangle;
   memset(cache, -1, sizeof(cache));
   answer = dp(0, 0);
   return answer;
}