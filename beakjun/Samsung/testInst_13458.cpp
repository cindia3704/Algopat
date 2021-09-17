/*
    작성자: 김지수
    작성일: 2021/09/17
    백준 -- 시험 감독 (13458번)
*/

#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int testPlace, head, sub;
   cin >> testPlace;
   vector<int> peopleInPlace;
   for (int i = 0; i < testPlace; i++) {
      int people;
      cin >> people;
      peopleInPlace.push_back(people);
   }
   cin >> head >> sub;
   long long total = 0;

   for (int i = 0; i < testPlace; i++) {
      total += 1;
      int studentsLeft = peopleInPlace[i] - head;
      int numExtraSubInstructor = ceil((float)studentsLeft / (float)sub);

      if (numExtraSubInstructor > 0) {
         total += numExtraSubInstructor;
      }
   }
   cout << total;
}