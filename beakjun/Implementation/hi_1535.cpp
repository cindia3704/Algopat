/*
    작성자: 김지수
    작성일: 2021/10/06
    백준 -- 안녕 (1535번)
    문제:
*/

#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N = 20;
int numPeople;
int happiness[MAX_N];
int loseStrength[MAX_N];
bool visited[MAX_N];
int maxHappy = -1;

void sayHi(int number, int strength, int happy) {
   if (strength <= 0) {
      return;
   }
   if (number == numPeople) {
      maxHappy = max(maxHappy, happy);
      return;
   }
   sayHi(number + 1, strength, happy);
   sayHi(number + 1, strength - loseStrength[number],
         happy + happiness[number]);
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   fill(visited, visited + MAX_N, false);
   cin >> numPeople;
   for (int i = 0; i < numPeople; i++) {
      cin >> loseStrength[i];
   }
   for (int i = 0; i < numPeople; i++) {
      cin >> happiness[i];
   }
   sayHi(0, 100, 0);
   cout << maxHappy;
}