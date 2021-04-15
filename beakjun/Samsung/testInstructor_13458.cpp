/*
    작성자: 김지수
    작성일: 2021/04/15
    백준 -- 시험 감독 (13458번)
    문제:
    - 총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다. i번 시험장에
   있는 응시자의 수는 Ai명이다.
   - 감독관은 총감독관과 부감독관으로 두 종류가 있다. 총감독관은 한 시험장에서
    감시할 수 있는 응시자의 수가 B명이고, 부감독관은 한 시험장에서 감시할 수
   있는 응시자의 수가 C명이다.
    - 각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명
   있어도 된다.

   각 시험장마다 응시생들을 모두 감시해야 한다. 이때, 필요한 감독관 수의
   최솟값을 구하는 프로그램을 작성하시오.
*/

#include <math.h>

#include <iostream>
#include <vector>
using namespace std;
vector<int> students;
int maxNumForMainInstr, maxNumForSubInstr;
long long totalInstructor;

void calculateNumInstrForRoom(int roomNum) {
   totalInstructor += 1;

   int studentsLeft = students[roomNum] - maxNumForMainInstr;
   int numExtraSubInstructor =
       ceil((float)studentsLeft / (float)maxNumForSubInstr);

   if (numExtraSubInstructor > 0) {
      totalInstructor += numExtraSubInstructor;
   }
}

int main(void) {
   int numTestRooms;
   cin >> numTestRooms;
   for (int i = 0; i < numTestRooms; i++) {
      int numStudents;
      cin >> numStudents;
      students.push_back(numStudents);
   }
   cin >> maxNumForMainInstr >> maxNumForSubInstr;

   for (int i = 0; i < numTestRooms; i++) {
      calculateNumInstrForRoom(i);
   }

   cout << totalInstructor << endl;
}