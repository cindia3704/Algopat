/*
    작성자: 김지수
    작성일: 2021/08/12
    백준 -- 근손실(18429번)
    문제:
    - 운동 중량 500을 소유한 대학원 -> 하루 지날때 마다 중량이 K만큼 감소
    - N개의 서로 다른 운동 키트를 가지고 있음
    - 하루에 1개의 키트 사용 -> N일 동안 1번씩만 사용가능
    - 운동 기간동안 항상 중량이 500이상으로 유지되도록 N일간 운동계획 세우려함
    - 어떤 시점에서라도 중량이 500보다 작아지면 안됨
    - N일 동안 N개의 운동 키트를 사용하는 모든 경우 중에서, 운동 기간동안 항상
   중량이 500 이상이 되도록 하는 경우의 수 구하라
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int answer = 0;
vector<int> kit;
// 키드의 중량이 같아도 다른 키트라 봐야해서 인덱스로 permutation
vector<int> indexs;

//매일 중량 500이상인지 확인
void checkPass(int loss) {
   int weight = 500;
   bool pass = true;
   for (int i = 0; i < indexs.size(); i++) {
      weight -= loss;
      weight += kit[indexs[i]];
      if (weight < 500) {
         return;
      }
   }
   answer++;
   return;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int days, loss;
   cin >> days >> loss;
   int idx = 0;

   for (int i = 0; i < days; i++) {
      int gain;
      cin >> gain;
      kit.push_back(gain);
      indexs.push_back(idx);
      idx++;
   }

   sort(indexs.begin(), indexs.end());
   do {
      checkPass(loss);
   } while (next_permutation(indexs.begin(), indexs.end()));

   cout << answer;
}