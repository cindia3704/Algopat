/*
    작성자: 김지수
    작성일: 2022/03/11
    백준 -- 통계학 (2108번)
*/

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> numbers;
int countFreq[8001];

void printResults() {
   sort(numbers.begin(), numbers.end());
   double avg;
   int mid, range;
   range = numbers[numbers.size() - 1] - numbers[0];
   mid = numbers[numbers.size() / 2];

   vector<int> freq;
   double sum = 0;
   int tempFreq = 0;
   int tempNum = -987654321;

   for (int i = 0; i < numbers.size(); i++) {
      sum += numbers[i];
      int idx;

      if (numbers[i] >= 0) {
         idx = 4001 + numbers[i];
      } else {
         idx = abs(numbers[i]);
      }

      if (countFreq[idx] == tempFreq && tempNum != numbers[i]) {
         freq.push_back(numbers[i]);
         tempNum = numbers[i];
      } else if (countFreq[idx] > tempFreq) {
         freq.clear();
         freq.push_back(numbers[i]);
         tempFreq = countFreq[idx];
         tempNum = numbers[i];
      }
   }
   sort(freq.begin(), freq.end());

   int ansFreq = freq[0];

   if (freq.size() > 1) {
      ansFreq = freq[1];
   }
   avg = sum / numbers.size();
   if (avg > -1 && avg < 0) {
      avg = abs(avg);
   }

   cout << floor(avg + 0.5) << '\n' << mid << '\n' << ansFreq << '\n' << range;
}
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);
   memset(countFreq, 0, sizeof(countFreq));

   int n;
   cin >> n;
   while (n--) {
      int num;
      cin >> num;
      numbers.push_back(num);
      if (num >= 0) {
         countFreq[4001 + num]++;
      } else {
         countFreq[abs(num)]++;
      }
   }

   printResults();
}
