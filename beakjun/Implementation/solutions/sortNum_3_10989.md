# 수 정렬하기 3 - 백준 10989번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/10989
<img width="1192" alt="스크린샷 2021-05-18 오전 11 13 42" src="https://user-images.githubusercontent.com/52744390/118580033-1c3d7a80-b7ca-11eb-8407-5803657aaca9.png">

## 풀이: 
* [수 정렬하기 2](https://github.com/cindia3704/Algopat/blob/main/beakjun/Implementation/sortNum2_2751.cpp) 와 매우 유사해 보이지만, 시간제한 & 메모리 제한에 주의해야한다! 
* 입력의 최대 = 10,000,000 이기 때문에, 이를 모두 배열에 저장하면 메모리 초과가 난다. 
* 따라서 카운팅 정렬 해야함!! 
* 카운틴 정렬이란? ➡️ 배열의 인덱스 값 갖는 수 들어오면 해당 값 + 1. 
```
예) 1이 입력으로 들어옴 ➡️ 배열[1] = 1 
    1이 입력으로 다시 들어옴 ➡️ 배열[1]=2
    3이 입력으로 들어옴 ➡️ 배열[0] = 0, 배열 [1] = 2, 배열[2] = 0, 배열[3] = 1   
```

## Code: 
1. 입력 받음
```cpp
   ios::sync_with_stdio(false);
   int n;
   cin >> n;
   int nums[MAX_NUM];
   memset(nums, 0, sizeof(nums));
   
   int maxNum = 0;
   for (int i = 0; i < n; i++) {
      int num;
      cin >> num;
      nums[num]++;
      if (maxNum < num) {
         maxNum = num;
      }
   }
```
* n = 입력의 크기 
* nums = 카운팅 정렬 적용할 배열 
* maxNum = 입력된 수 중 가장 큰 수 ➡️ 필요한 이유? 출력시 배열의 어느 index까지 봐야할지 알려줌 
* nums[num]++ = 현재 입력 받은 수를 index로 갖는 배열의 element 증가시키기 
   
2. 출력  
```cpp
   for (int i = 0; i <= maxNum; i++) {
      while (nums[i] > 0) {
         cout << i << "\n";
         nums[i]--;
      }
   }
```

```
예) 배열이 다음과 같을 때 : 0  5  1  3  0  0  4
- maxNum = 6
- 1이 입력으로 5번 들어왔고, 2는 1면, 3은 3번, 4는 0번, 5는 0번, 6은 4번 들어옴. 
```
* 수를 오름차순으로 정렬해야하기 때문에, 인덱스 0 부터, maxNum까지 반복문 돌며, 해당 index의 배열값이 0 이 될때까지 인덱스 출력 
* 주의!! cout / cin 쓰면 시간초과 남!! 따라서    ios::sync_with_stdio(false); 추가! 

    
## 결과: 
<img width="924" alt="스크린샷 2021-05-18 오전 11 27 29" src="https://user-images.githubusercontent.com/52744390/118581123-092baa00-b7cc-11eb-8966-8f8ad8fd6a34.png">
