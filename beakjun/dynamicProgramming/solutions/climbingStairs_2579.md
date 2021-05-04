# 계단 오르기 - 백준 2579번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/2579 
<img width="1188" alt="스크린샷 2021-05-04 오후 7 58 04" src="https://user-images.githubusercontent.com/52744390/116993906-0b453180-ad13-11eb-9976-355ca9ebc400.png">
<img width="1188" alt="스크린샷 2021-05-04 오후 7 59 05" src="https://user-images.githubusercontent.com/52744390/116994028-2fa10e00-ad13-11eb-8c1b-dc10ce1ff25f.png">
    
## 풀이: 
* 먼저, 문제에서 마지막 계단은 반드시 밟아야 한다고 했기에, 마지막 계단에서 밑으로 내려가는 식으로 풀었다. 
![IMG_5B099E6B75D6-1](https://user-images.githubusercontent.com/52744390/116994462-b48c2780-ad13-11eb-8ad0-68e51507d091.jpeg)
* 위 이미지는 문제에서 제시한 예시를 가장 윗 계단부터 거꾸로 나열한 것이다. 
* 현재 위치가 가장 마지막 계단이라면, 재귀를 이용하여 DP로 풀떄, 다음으로 갈수 있는 계단은: 
    1. 현 위치를 밟고, 현 위치의 바로 앞을 무조건 지난후 현 위치에서 3개 앞에 있는 계단을 밟음 
    2. 현 위치를 밟고, 현 위치에서 2개 앞에 있는 계단을 밟음.   
* 현위치를 밟고 바로 앞 계단으로 재귀를 안넘긴 이유?
![IMG_0E56082C2F58-1](https://user-images.githubusercontent.com/52744390/116995071-8e1abc00-ad14-11eb-8e5e-4fbda51a2e87.jpeg)
* 위 그림처럼 next를 바로 앞 계단으로 한 후 재귀를 이어가면, next next에 올수 있는 계단은 바로 앞 or 앞앞이다. 
* 이때 next next가 바로 앞으로 가게 된다면, 연속한 3개의 계단을 밟게 됨 (문제 조건 만족 X)

## Code: 
1. 변수 선언 
```cpp
const int MAX_NUM = 10000;
vector<int> stairs;
int cache[MAX_NUM];
int numStairs;
```
* stairs = 입력 받는 계단에 적힌 숫자 
* cache = 현 위치까지 가장 큰 값 저장하는 배열 (처음에 -1로 초기화)
* numStairs = 입력 받는 계단의 수 

2. DP
```cpp
int findMaxSum(int start) {
   int &ret = cache[start];
   if (start < 0) {
      return 0;
   }
   if (start == 0) {
      return stairs[0];
   }
   if (ret != -1) {
      return ret;
   }
   int goOne = stairs[start] + stairs[start - 1] + findMaxSum(start - 3);
   int goTwo = stairs[start] + findMaxSum(start - 2);
   ret = max(goOne, goTwo);

   return ret;
}
```
* goOne = 현 위치 밟고, 바로 앞 밟음! 
* goTwo = 현 위치 밟고, 앞앞 자리 밟음
* 합이 가장 큰 것을 찾고 있기 때문에 max! 
* 범위 주의!! -- 현 위치가 0이하이면 그냥 0 반환(bc 이런 계단 없기 때문!) 
* 현 위치가 0이면 ➡️ 가장 첫번째 계단!! 따라서 밟아야함!(첫번쨰 계단은 연속된 3개의 계단 밟으면 안되는 조건에 포함 안된다고 문제에서 명시!) ➡️ 첫번째 계단의 수를 반환!
   
## 참고한 반례: 
link:https://www.acmicpc.net/board/view/61387
```
input:
6
10
3
2
1
100
100
output: 114
answer: 212

input:
11
1
6
4
7
3
7
5
2
1
5
3
output: 30
answer: 32
```
 
## 결과: 
<img width="929" alt="스크린샷 2021-05-04 오후 7 59 25" src="https://user-images.githubusercontent.com/52744390/116994072-3b8cd000-ad13-11eb-9879-8b4f964477d7.png">
