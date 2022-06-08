/*
    작성자: 김지수
    작성일: 2022/06/08
    백준 -- 암호 만들기 (1759번)
*/

#include <algorithm>
#include <iostream>
#include <set>
#define MAX 16
using namespace std;

int pwLength, alphabetNum;
char alphbets[MAX];
set<string> combinations;

bool checkValid(string pw) {
   int countVowel = 0;      // 모음개수
   int countConsonant = 0;  // 자음개수
   for (int i = 0; i < pwLength; i++) {
      if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' ||
          pw[i] == 'u') {
         countVowel++;
      } else {
         countConsonant++;
      }
   }
   if (countVowel >= 1 && countConsonant >= 2) {
      return true;
   } else {
      return false;
   }
}

void makeComb(int pickNum, int start, string comb) {
   // 암호 길이 충족
   if (pickNum == pwLength) {
      // 중복 제거
      if (combinations.find(comb) == combinations.end()) {
         // 1개 이상 모음 & 2개이상 자음
         bool isValid = checkValid(comb);
         if (isValid) {
            combinations.insert(comb);
            cout << comb << '\n';
         }
      }
      return;
   } else {
      for (int i = start; i < alphabetNum; i++) {
         string temp = comb + alphbets[i];
         makeComb(pickNum + 1, i + 1, temp);
      }
   }
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> pwLength >> alphabetNum;
   for (int i = 0; i < alphabetNum; i++) {
      cin >> alphbets[i];
   }
   // 사전순
   sort(alphbets, alphbets + alphabetNum);
   makeComb(0, 0, "");
}