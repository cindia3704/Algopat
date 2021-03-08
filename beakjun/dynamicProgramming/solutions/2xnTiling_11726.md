# 2xn 타일링 - 백준 11726번 풀이 
 
## 문제 
2xn의 사각형을을 
* 2x1 또는 
* 1x2
타일로 채울수 있는 방법의 수? 
   
### 그림을 보면:    
* n=1 ➡️ 1개 
* n=2 ➡️ 2개 
* n=3 ➡️ 3개 
* n=4 ➡️ 5개 
  ... 
* n=9 ➡️ 55개   
__결국 n = (n-1) + (n-2)__ 
![IMG_3311ECDE1B39-1](https://user-images.githubusercontent.com/52744390/110392382-319c7700-80ac-11eb-956c-327a797e515b.jpeg)
 

   
## 코드 (Top down) 
1. 일단 메모이제이션을 할 배열 선언 
2. 메모이제이션 할때 사용할 배열을 처음엔 -1로 초기화 ➡️ memset이용 (main 함수에서) 
```cpp
   int cache[1001];
   memset(cache, -1, sizeof(cache));
```
3. Top down approach 동적프로그래밍 방식 적용 
```cpp
  int tiling(int n) {
    int &ret = cache[n];
    if (n <= 1) {
      ret = 1;
      return ret;
    }
    if (ret != -1) {
      return ret;
    }
    ret = tiling(n - 1) % MAX + tiling(n - 2) % MAX;
    return ret;
  }
```
* 1보다 작은 n ➡️ 1 반환 (기저 사례) 
* ret가 -1이 아닐 경우 ➡️ 이미 이전에 해당 input에 대한 계산이 완료되서 메모이제이션 되었다는 뜻 
* (a + b)%c = ((a%c) + (b%c))%c
   
# 2xn 타일링2 - 백준 11727번 풀이 
* 여기는 2x2 타일이 추가됨 ➡️ 그냥 n-2에 해당하는 걸 한번 더 더해주면 됨! 
```cpp
  ret = tiling(n - 1) % MAX + tiling(n - 2) % MAX +tiling(n - 2) % MAX;
```
