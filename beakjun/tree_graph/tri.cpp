#include <cstdio>
#include <iostream>
#include <string>
const int MAX_N = 26;
using namespace std;

struct Tri_Node {
   Tri_Node *child[MAX_N];
   Tri_Node() {
      for (int i = 0; i < MAX_N; i++) {
         child[i] = NULL;
      }
   }
   ~Tri_Node() {
      for (int i = 0; i < MAX_N; i++) {
         if (child[i] != NULL) {
            delete child[i];
         }
      }
   }
   int toNum(char c) { return tolower(c) - 'a'; }

   void insert(const char *words) {
      if (*words == '\0') {
         return;
      }
      int nextIdx = toNum(*words);
      if (child[nextIdx] == NULL) {
         child[nextIdx] = new Tri_Node();
      }
      child[nextIdx]->insert(words + 1);
   }

   bool find(const char *words) {
      int nextIdx = toNum(*words);
      if (*words == '\0') {
         return true;
      }
      if (child[nextIdx] == NULL) {
         return false;
      }
      return child[nextIdx]->find(words + 1);
   }
};

int main(void) {
   Tri_Node tri;
   tri.insert("hi");
   tri.insert("hill");
   tri.insert("ball");

   cout << tri.find("hi") << endl;
   cout << tri.find("hello") << endl;
}