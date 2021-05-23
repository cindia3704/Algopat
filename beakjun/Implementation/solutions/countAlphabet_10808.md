# 알파벳 개수 - 백준 10808번 풀이

## 문제: 
link : https://www.acmicpc.net/problem/10808
<img width="1154" alt="스크린샷 2021-05-23 오후 8 13 00" src="https://user-images.githubusercontent.com/52744390/119258112-47c5c800-bc03-11eb-93c7-ff3711f66643.png">

## 풀이: 
* 입력받은 문자열에 각 알파벳이 몇번 등장하는지 출력해야하므로, 알파벳 a~z의 개수를 저장할 크기 26짜리 배열을 선언한후 0으로 초기화 한다. 
* 문자열을 한 단어씩 잘라서 char 을 -'a'하면 위에서 만든 배열에서의 해당 알파벳의 인덱스를 알수 있음 
* 인덱스를 알아내면 배열[인덱스]의 값을 1 증가 시킨다 

## Code: 
```cpp
int main(void) {
   string input;
   cin >> input;
   int alphabets[26];
   memset(alphabets, 0, sizeof(alphabets));

   for (int i = 0; i < input.length(); i++) {
      char letter = input[i];
      int index = letter - 'a';
      alphabets[index]++;
   }

   for (int i = 0; i < 26; i++) {
      cout << alphabets[i] << " ";
   }
}
```
* input = 입력받는 문자열 (모두 소문자로 이루어져 있음) 
* alphabets 는 a~z까지의 알파벳의 개수(input에 등자 횟수)를 기록하기 위한 배열 
* memset을 이용하여 alphabets의 모든 원소를 0으로 초기화 
* for 문을 이용하여 input문자열을 한 글자씩 쪼개어 index 알아낸 후 알파벳 개수 업데이트 

## 결과: 
<img width="936" alt="스크린샷 2021-05-23 오후 8 17 49" src="https://user-images.githubusercontent.com/52744390/119258279-f36f1800-bc03-11eb-935a-246fdec2203b.png">
