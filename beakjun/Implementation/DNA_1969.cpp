/*
    작성자: 김지수
    작성일: 2021/09/03
    백준 -- DNA (1969번)
    문제:
    - 이 DNA는 서로 다른 4가지의 뉴클레오티드의 첫 글자로 이루어짐
    - Hamming Distance = 같은 길이의 2 DNA에서 각 위치의 뉴클오티드 문자가 다른
   것의 개수
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<string> dna;
const char alpha[4] = {'A', 'C', 'T', 'G'};
const int MAX_N = 1000;
int counts[MAX_N][4];

int main(void) {
   memset(counts, 0, sizeof(counts));
   ios::sync_with_stdio(false);
   cin.tie(0);

   int dnaNum, dnaLength;
   cin >> dnaNum >> dnaLength;
   for (int i = 0; i < dnaNum; i++) {
      for (int j = 0; j < dnaLength; j++) {
         char nucleotide;
         cin >> nucleotide;
         switch (nucleotide) {
            case 'A':
               counts[j][0] += 1;
               break;
            case 'C':
               counts[j][1] += 1;
               break;
            case 'G':
               counts[j][2] += 1;
               break;
            case 'T':
               counts[j][3] += 1;
         }
      }
   }

   char answer[dnaLength];
   int sum = 0;
   for (int i = 0; i < dnaLength; i++) {
      int temp = 0;
      int index = 0;
      for (int j = 0; j < 4; j++) {
         if (counts[i][j] > temp) {
            temp = counts[i][j];
            index = j;
         }
      }
      sum += (dnaNum - temp);
      switch (index) {
         case 0:
            answer[i] = 'A';
            break;
         case 1:
            answer[i] = 'C';
            break;
         case 2:
            answer[i] = 'G';
            break;
         case 3:
            answer[i] = 'T';
      }
      cout << answer[i];
   }
   cout << endl;
   cout << sum;
}