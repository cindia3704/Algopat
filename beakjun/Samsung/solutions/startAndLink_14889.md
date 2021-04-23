# 스타트와 링크 - 백준 14889번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/14889   
<img width="1171" alt="스크린샷 2021-04-24 오전 6 52 03" src="https://user-images.githubusercontent.com/52744390/115933311-94fe2f00-a4c9-11eb-8659-a5404643a4c5.png">
<img width="1171" alt="스크린샷 2021-04-24 오전 6 52 23" src="https://user-images.githubusercontent.com/52744390/115933327-a0e9f100-a4c9-11eb-9074-0177da2cad6f.png">
   
## 풀이: 
* 먼저, 스타트 팀과 링크 팀은 같은 수의 팀원을 갖고 있다. 
* 먼저 전체 인원을 (전체인원/2)만큼의 팀원을 갖는 두 팀으로 나눠야한다. 
* 팀으로 나눌때, 모든 경우의 수를 생각해야함! 
* 한팀이 정해지면, 다른 한팀은 상대편에 속하지 않은 인원으로 구성 가능! 
* 각 loop마다 1. 각 팀의 팀원 정해져야하고, 2. 각 팀의 능력치가 다 더해져야하고, 3.두 팀의 능력치 차를 구해 4.지금까지 나온 최소 능력치차와 비교하여 업데이트 해줘야함. 

## Code: 
1. 변수 선언 
```cpp
const int MAX_PLAYER = 20 + 1;
int graph[MAX_PLAYER][MAX_PLAYER];
int totalPlayer;
int minVal = 987654321;
vector<int> group1;
```
* MAX_PLAYER 이 20 + 1인 이유: 최대 인원 = 20 BUT 넘버링을 1부터 시작! ➡️ 1~21까지! 
* graph ➡️ 모든 팀원별로 팀원간 능력치 입력받아 저장하는 배열 
* minVal = 최종 답! <-- 처음에 987654321인 이유 = 업데이트 할때를 고려! 
* group1 = 스타트 팀의 팀원들을 저장하는 벡터! (element = 사람(node)의 번호)

2. 2차원 배열에 각 팀원간 능력치 저장 
```cpp
   cin >> totalPlayer;
   for (int i = 1; i <= totalPlayer; i++) {
      for (int j = 1; j <= totalPlayer; j++) {
         int strength;
         cin >> strength;
         graph[i][j] = (strength);
      }
   }
```
3. 팀의 인원이 아직 다 차지 않았을때 ➡️ 루프 돌면서 모든 가능한 조합 확인 
```cpp
group1.push_back(startNode);
for (int i = startNode + 1; i <= totalPlayer; i++) {
      findMinDiff(numPeople + 1, i);
      group1.erase(remove(group1.begin(), group1.end(), i));
   }
```
* 해당 코드는 findMinDiff()함수 안에 있음! 
* 먼저 findMinDiff() 불려지면 현재 노드를 group1에 추가 <-- 팀원 추가!
* 재귀로 호출한 다음에 erase해서 방금 다녀온 노드(사람)을 group1에서 없앰! ➡️ backtracking!
   
4. 팀의 인원 모두 찼을때 ➡️ 상대팀 구성 & 팀의 능력치 합 구함 
```cpp
if (numPeople == totalPlayer / 2) {
      vector<int> group2;
      int group1Sum = 0;
      int group2Sum = 0;

      // group1에 없는건 다 group2로 넣음
      for (int i = 1; i <= totalPlayer; i++) {
         if (find(group1.begin(), group1.end(), i) == group1.end()) {
            group2.push_back(i);
         }
      }

      // 1,2,3이 그룹이면 (1,2)+(2,1)+(1,3)+(3,1)+(2,3)+(3,2)가 groupSum이 된다.
      for (int j = 0; j < totalPlayer / 2 - 1; j++) {
         for (int i = j + 1; i < totalPlayer / 2; i++) {
            group1Sum += graph[group1[j]][group1[i]];
            group1Sum += graph[group1[i]][group1[j]];

            group2Sum += graph[group2[j]][group2[i]];
            group2Sum += graph[group2[i]][group2[j]];
         }
      }

      int diff = abs(group1Sum - group2Sum);
      minVal = min(diff, minVal);
   }
```
* 한 팀의 팀원 모두 모아졌을때 = 한팀의 인원이 (전체인원/2)일때 
* 스타트 팀이 모두 결정되었으면, 링크팀은 스타트 팀에 속하지 않은 사람들로 구할수 있음!
* 링크 팀은 스타트 팀이 바뀔때 마다 초기화한 후 값 설정해야하므로, 해당 if문 들어올때마다 새로 할당!
* 예) 1,2,3번 팀원이 한팀에 속해 있으면, 능력치 합을 구할때 다음과 같이 구함:    
$$ S_1,2 + S_2,1 + S_1,3 + S_3,1 + S_2,3 + S_3,2 $$   
따라서 이중 루프로 처리!   
* 그 후 능력치 차 구할때 어느 팀의 능력치 합이 더 클지 모르므로 abs()사용! 
* 현재의 minVal과 비교한후 update! 

## 결과: 
<img width="928" alt="스크린샷 2021-04-24 오전 7 12 37" src="https://user-images.githubusercontent.com/52744390/115934627-751c3a80-a4cc-11eb-83f9-82dab2613b3e.png">
