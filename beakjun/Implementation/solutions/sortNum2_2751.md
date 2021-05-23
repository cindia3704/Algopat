# 수 정렬하기 2 - 백준 2751번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/2751
<img width="1152" alt="스크린샷 2021-05-23 오후 8 19 30" src="https://user-images.githubusercontent.com/52744390/119258340-2fa27880-bc04-11eb-8f0d-fc7c53fe7fef.png">

## 풀이: 
* cpp 의 sort() 함수 사용하면 오름차순 정렬 가능! 

```cpp
int main(void) {
   int n;
   cin >> n;
   vector<int> seq;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      seq.push_back(num);
   }
   sort(seq.begin(), seq.end());
   for (int i = 0; i < seq.size(); i++) {
      cout << seq[i] << "\n";
   }
}
```
* 먼저 입력받는 숫자들을 벡터에 저장한다 
* sort()를 이용하여 벡터에 저장한 수를 오름차순 정렬한다 

## 결과: 
<img width="924" alt="스크린샷 2021-05-23 오후 8 21 31" src="https://user-images.githubusercontent.com/52744390/119258411-78f2c800-bc04-11eb-877c-48a3bd808d34.png">


