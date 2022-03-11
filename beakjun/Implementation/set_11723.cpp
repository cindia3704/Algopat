/*
    작성자: 김지수
    작성일: 2022/03/11
    백준 -- 집합 (11723번)
*/

#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool haveNum[21];

void execute(string command) {
   int num;
   if (command == "add") {
      cin >> num;
      haveNum[num] = true;
   } else if (command == "remove") {
      cin >> num;
      haveNum[num] = false;
   } else if (command == "check") {
      cin >> num;
      if (!haveNum[num]) {
         cout << 0 << '\n';
      } else {
         cout << 1 << '\n';
      }
   } else if (command == "toggle") {
      cin >> num;
      haveNum[num] = !haveNum[num];
   } else if (command == "all") {
      memset(haveNum, true, sizeof(haveNum));
   } else if (command == "empty") {
      memset(haveNum, false, sizeof(haveNum));
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int numCommands;
   cin >> numCommands;

   memset(haveNum, false, sizeof(haveNum));
   while (numCommands--) {
      string command;
      cin >> command;
      execute(command);
   }
}