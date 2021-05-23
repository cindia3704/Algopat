/*
    작성자: 김지수
    작성일: 2021/05/23
    백준 -- 덱 (10866)
    문제:
    - 정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는
   프로그램을 작성하시오.
    - push_front X: 정수 X를 덱의 앞에 넣는다.
    - push_back X: 정수 X를 덱의 뒤에 넣는다.
    - pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에
    들어있는 정수가 없는 경우에는 -1을 출력한다.
    - pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에
    들어있는 정수가 없는 경우에는 -1을 출력한다.
    - size: 덱에 들어있는 정수의 개수를 출력한다.
    - empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
    - front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는
   경우에는 -1을 출력한다.
    - back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는
    경우에는 -1을 출력한다.
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
queue<string> q;

string handleFunc(string input) {
   string token = input.substr(0, input.find(" "));
   if (token == "front") {
      if (q.empty()) {
         return "-1";
      } else {
         return q.front();
      }
   } else if (token == "empty") {
      if (q.empty()) {
         return "1";
      } else {
         return "0";
      }
   } else if (token == "size") {
      return to_string(q.size());
   } else if (token == "back") {
      if (q.empty()) {
         return "-1";
      } else {
         return q.back();
      }
   } else if (token == "push_front") {
      string num = input.substr(0 + token.size() + 1, input.find(" "));
      queue<string> q_;
      q_.push(num);
      while (q.size() > 0) {
         q_.push(q.front());
         q.pop();
      }
      q = q_;
      return "p";
   } else if (token == "push_back") {
      string num = input.substr(0 + token.size() + 1, input.find(" "));
      q.push(num);
      return "p";
   } else if (token == "pop_front") {
      if (q.empty()) {
         return "-1";
      } else {
         string ret = q.front();
         q.pop();
         return ret;
      }
   } else if (token == "pop_back") {
      if (q.empty()) {
         return "-1";
      } else {
         queue<string> q_;
         while (q.size() > 1) {
            q_.push(q.front());
            q.pop();
         }
         string ret = q.front();
         q = q_;
         return ret;
      }
   } else {
      return "wrong command";
   }
}
int main(void) {
   string n;
   getline(cin, n);
   int num = stoi(n);
   vector<string> ans;
   for (int i = 0; i < num; i++) {
      string input;
      getline(cin, input);
      string s = handleFunc(input);
      ans.push_back(s);
   }

   for (int i = 0; i < ans.size(); i++) {
      if (ans[i] != "p") {
         cout << ans[i] << endl;
      }
   }
}