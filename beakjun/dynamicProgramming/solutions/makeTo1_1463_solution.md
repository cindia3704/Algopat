# 1로 만들기 - 백준 1463번 풀이 
   
## 문제 
정수 x에 사용할수 있는 연산은: 
* x % 3 == 0 ➡️ x/3 
* x % 2 == 0 ➡️ x/2
* x-1
정수 x가 입력 되었을때 위 3개의 연산을 적절히 사용해서 1을 만드려함. 이때 연산을 사용하는 횟수의 최솟값은? 
   
## 왜 Dynamic programming으로 푸는가? 
1. 최적 부분 구조 -- 큰 문제를 작은 문제로 나눌 수 있다 
2. 중복되는 부분 문제 -- 동일한 작은 문제를 반복적으로 해결 

ex) 주어진 정수 = 10인 경우
* 10 /2 ➡️ 5 
* 10 -1 ➡️ 9   
그리고 또 이에 대해서 3개의 연산을 동일하게 적용 가능!   
### 그림을 보면:    
* 4에 대해서 총 3번
* 3에 대해서 총 5번 
* 2에 대해서 총 9번   
__결국 같은 수에 대해 같은 연산을 반복하게 됨__ 
<img width="858" alt="스크린샷 2021-03-09 오전 12 14 24" src="https://user-images.githubusercontent.com/52744390/110340259-68529d00-806c-11eb-917f-462cd39f4835.png">   

   
## 코드 
1. 일단 메모이제이션을 할 배열 선언 -- long long으로 하는 이유: 입력의 최대값 = 10^6 ( 전역 변수 )
2. 메모이제이션 할때 사용할 배열을 처음엔 -1로 초기화 ➡️ memset이용 (main 함수에서) 
```cpp
   long long cache[1000001];
   memset(cache, -1, sizeof(cache));
```
3. Top down approach 동적프로그래밍 방식 적용 
```cpp
  long long makeTo1(long long input) {
   long long &ret = cache[input];

   if (input == 1) {
      ret = 0;
      return ret;
   }
   if (ret != -1) {
      return ret;
   }

   ret = makeTo1(input - 1) + 1;
   if (input % 3 == 0) {
      ret = min(ret, makeTo1(input / 3) + 1);
   }
   if (input % 2 == 0) {
      ret = min(ret, makeTo1(input / 2) + 1);
   }

   return ret;
}
```
* 1이 들어올 경우 ➡️ 수행할 연산 수 = 0 (기저사례) 
* ret가 -1이 아닐 경우 ➡️ 이미 이전에 해당 input에 대한 계산이 완료되서 메모이제이션 되었다는 뜻 
* input-1은 항상 수행하는 이유? ➡️ 3의 배수 또는 2의 배수가 아닐 경우에는 무조건 -1을 수행해야하고 + 만약 배수일 경우 가장 작은 값을 선택해야하기 때문!  
