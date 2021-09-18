/*
    작성자: 김지수
    작성일: 2021/09/18
    백준 -- 전화번호 목록(5052번)
    문제:
    - 전화번호 목록이 주어질 떄, 목록이 일관성 있는지 구하라
    - 일관성 유지하려면, 한 번호가 다른 번호의 접두사가 되면 안됨!
*/

#include <iostream>
#include <set>
#include <string>
#include <vector>
const int MAX_N = 10;
char input[10001][11];
using namespace std;

struct Tri_Node {
   bool finish;
   Tri_Node *child[10];
   Tri_Node() {
      finish = false;
      fill(child, child + MAX_N, nullptr);
   }
   ~Tri_Node() {
      for (int i = 0; i < MAX_N; i++) {
         if (child[i] != NULL) {
            delete child[i];
         }
      }
   }
   int toNum(char c) { return (c - '0'); }

   void insert(char *words) {
      if (*words == '\0') {
         finish = true;
      } else {
         int next = toNum(*words);

         if (child[next] == NULL) {
            child[next] = new Tri_Node();
         }
         child[next]->insert(words + 1);
      }
   }

   bool find(char *words) {
      int next = toNum(*words);
      if (*words == '\0') {
         return false;
      }
      if (finish == true) {
         return true;
      }
      return child[next]->find(words + 1);
   }
};

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int testCase;
   cin >> testCase;
   vector<string> ans;
   while (testCase--) {
      Tri_Node *tri = new Tri_Node();
      int phoneBookSize;
      cin >> phoneBookSize;

      for (int i = 0; i < phoneBookSize; i++) {
         cin >> input[i];
         tri->insert(input[i]);
      }

      bool found = false;
      for (int i = 0; i < phoneBookSize; i++) {
         if (tri->find(input[i])) {
            found = true;
         }
      }
      if (!found) {
         ans.push_back("YES");
      } else {
         ans.push_back("NO");
      }
   }
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
   }
}