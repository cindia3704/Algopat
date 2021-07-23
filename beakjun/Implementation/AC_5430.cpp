/*
    작성자: 김지수
    작성일: 2021/07/24
    백준 -- AC (5430번)
    문제:
    - AC라는 새로운 언어 -->2가지 함수
    - 함수 R : 뒤집기 -- 배열에 있는 숫자의 순서를 뒤집는 함수
    - 함수 D: 버리기 -- 첫 번째 숫자를 버리는 함수 (빈배열에 D -> error)
*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
void handleFunc(string functions, string arrInput) {
   deque<int> arr;
   arrInput = arrInput.substr(1, arrInput.size() - 2);
   if (arrInput.size() > 0) {
      stringstream ss(arrInput);
      while (ss.good()) {
         string substr;
         getline(ss, substr, ',');

         arr.push_back(stoi(substr));
      }
   }

   bool properOrder = true;
   for (int i = 0; i < functions.length(); i++) {
      char command = functions[i];
      if (command == 'R') {
         properOrder = !properOrder;
      } else {
         if (arr.size() == 0) {
            cout << "error" << '\n';
            return;
         } else {
            if (properOrder)
               arr.pop_front();
            else
               arr.pop_back();
         }
      }
   }

   cout << "[";
   if (properOrder) {
      for (int i = 0; i < arr.size(); i++) {
         if (i == arr.size() - 1) {
            cout << arr[i];
         } else {
            cout << arr[i] << ",";
         }
      }
   } else {
      for (int i = arr.size() - 1; i >= 0; i--) {
         if (i == 0) {
            cout << arr[i];
         } else {
            cout << arr[i] << ",";
         }
      }
   }
   cout << "]\n";
}

int main(void) {
   int testCase;
   cin >> testCase;
   while (testCase--) {
      string functions, arrInput;
      int arrSize;
      cin >> functions;
      cin >> arrSize;
      cin >> arrInput;
      handleFunc(functions, arrInput);
   }
}