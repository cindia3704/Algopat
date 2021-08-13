/*
    작성자: 김지수
    작성일: 2021/08/13
    백준 -- 정식당 (17479번)
    문제:
    - A개의 "일반메뉴", B개의 "특별메뉴", C개의 "서비스메뉴"로 나뉘어져 있다
    - 일반메뉴= 자유롭게 주문 가능
    - 특별메뉴는 일반메뉴에서 총 20,000원 이상을 주문해야 주문할 수 있다
    - 서비스메뉴는 일반메뉴와 특별메뉴에서 총 50,000원 이상을 주문해야 주문 가능
   - 서비스메뉴는 단 하나만 주문가능
   - 옳은 주문이면 "Okay"를, 그렇지 않은 주문이라면 "No"를 출력
*/

// 주의: search 할때 시간초과때문에 map 이용!!
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct MENU {
   long price, type;
   string name;
};
map<string, long> a;
map<string, long> b;
vector<string> c;

int main(void) {
   int aCount, bCount, cCount, orderCount;
   long aPrice = 0, bPrice = 0, cNum = 0;
   cin >> aCount >> bCount >> cCount;
   for (int i = 0; i < aCount; i++) {
      string name;
      long price;
      cin >> name;
      cin >> price;
      a.insert(make_pair(name, price));
   }
   for (int i = 0; i < bCount; i++) {
      string name;
      long price;
      cin >> name;
      cin >> price;
      b.insert(make_pair(name, price));
   }
   for (int i = 0; i < cCount; i++) {
      string menu;
      cin >> menu;
      c.push_back(menu);
   }
   cin >> orderCount;
   for (int i = 0; i < orderCount; i++) {
      string name;
      cin >> name;
      if (a.find(name) != a.end()) {
         aPrice += a.find(name)->second;
      } else if (b.find(name) != b.end()) {
         bPrice += b.find(name)->second;
      } else {
         cNum++;
      }
   }
   if (cNum > 1 || (aPrice < 20000 && bPrice > 0) ||
       (aPrice + bPrice < 50000 && cNum > 0)) {
      cout << "No";
      return 0;
   } else {
      cout << "Okay";
      return 0;
   }
}