# 알파벳 찾기 - 백준 10809번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/10809
<img width="1162" alt="스크린샷 2021-05-23 오후 8 02 41" src="https://user-images.githubusercontent.com/52744390/119257792-d6394a00-bc01-11eb-88e3-c3706ee23e63.png">

## 풀이: 
* 먼저, 해당 알파벳을 입력으로 받은 문자열에서 찾지 못하면 -1을 반환해야하므로 배열 초기화를 -1로 해줌! 
* 입력받은 문자열을 한 글자씩 자름 
* 문자열은 모두 소문자로 이루어져 있으므로 'a'를 빼주면 알파벳 순서가 숫자로 나옴 
```
예) 입력 = a ==> a - 'a' = 0 
   입력 = b ==> b - 'a' = 1
   입력 = c ==> c - 'a' = 2 
```
* 알파벳 하나하나의 개수를 기록하는 배열의 인덱스 = 알파벳 순서와 같음 
* 따라서 입력받은 문자열을 한 글자씩 자른 후, 알파벳 순서를 찾으면 해당 순서를 index로 갖는 element의 값을 해당 알파벳의 위치 (입력 문자열에서) 로 만들면 됨 
* 단, 문제에서 알파벳을 가장 처음 발견한 위치를 원하기 때문에, alphabets[i]가 -1인 경우만 업데이트 

## Code: 
```cpp
int main(void) {
   string input;
   cin >> input;

   int alphabets[26];
   memset(alphabets, -1, sizeof(alphabets));

   for (int i = 0; i < input.length(); i++) {
      char letter = input[i];
      int index = letter - 'a';
      if (alphabets[index] == -1) {
         alphabets[index] = i;
      }
   }
   for (int i = 0; i < 26; i++) {
      cout << alphabets[i] << " ";
   }
}
```
* 알파벳의 전체 수 = 26 ==> alphabets 배열의 크기를 26으로! 
* memset으로 alphabets의 모든 원소를 -1로 초기화 (못찾을 경우 -1로 출력해야하기 떄문) 
* 입력받은 문자열을 한 문자씩 반복문으로 돌며 alphabets 값 업데이트 

## 결과: 
<img width="934" alt="스크린샷 2021-05-23 오후 8 11 43" src="https://user-images.githubusercontent.com/52744390/119258067-19e08380-bc03-11eb-8985-5952071d2cad.png">
