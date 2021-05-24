/*
    작성자: 김지수
    작성일: 2021/05/24
    백준 -- 큐 (10845)
    문제:
    - 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는
   프로그램을 작성하시오.
    - push X: 정수 X를 큐에 넣는 연산이다.
    - pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에
   들어있는 정수가 없는 경우에는 -1을 출력한다.
    - size: 큐에 들어있는 정수의 개수를 출력한다.
    - empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    - front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는
   경우에는 -1을 출력한다.
    - back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는
   경우에는 -1을 출력한다.
*/

#include <iostream>
#include <queue>
using namespace std;

int main(void) {
   int n, num;
   string command;
   cin >> n;
   queue<int> q;

   while (n--) {
      cin >> command;
      if (command == "push") {
         cin >> num;
         q.push(num);
      } else if (command == "pop") {
         if (q.empty()) {
            cout << -1 << endl;
         } else {
            cout << q.front() << endl;
            q.pop();
         }
      } else if (command == "size") {
         cout << q.size() << endl;
      } else if (command == "empty") {
         cout << (q.size() == 0 ? 1 : 0) << endl;
      } else if (command == "front") {
         if (q.empty()) {
            cout << -1 << endl;
         } else {
            cout << q.front() << endl;
         }
      } else {
         if (q.empty()) {
            cout << -1 << endl;
         } else {
            cout << q.back() << endl;
         }
      }
   }
}