/*
    작성자: 김지수
    작성일: 2021/10/11
    백준 -- 여행 가자 (1976번)
    문제:
*/
#include <iostream>
#include <vector>
using namespace std;
int cityNum, tripCityNum;
struct Node {
   int n1, n2, w;
};
int getParent(int parent[], int x) {
   if (parent[x] == x) return x;
   return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
   a = getParent(parent, a);
   b = getParent(parent, b);
   if (a < b)
      parent[b] = a;
   else
      parent[a] = b;
}

bool findParent(int parent[], int a, int b) {
   a = getParent(parent, a);
   b = getParent(parent, b);
   if (a == b)
      return true;
   else
      return false;
}

int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> cityNum >> tripCityNum;
   int parent[cityNum + 1];
   for (int i = 1; i <= cityNum; i++) {
      parent[i] = i;
   }
   vector<Node> edges;
   for (int i = 0; i < cityNum; i++) {
      for (int j = 0; j < cityNum; j++) {
         int num;
         cin >> num;
         if (num == 1) {
            Node n;
            n.n1 = i + 1;
            n.n2 = j + 1;
            n.w = 1;
            edges.push_back(n);
         }
      }
   }
   int tripSeq[tripCityNum];
   for (int i = 0; i < tripCityNum; i++) {
      cin >> tripSeq[i];
   }
   for (int i = 0; i < edges.size(); i++) {
      if (!findParent(parent, edges[i].n1, edges[i].n2)) {
         unionParent(parent, edges[i].n1, edges[i].n2);
      }
   }
   bool found = false;
   for (int i = 0; i < tripCityNum - 1; i++) {
      if (parent[tripSeq[i]] != parent[tripSeq[i + 1]]) {
         found = true;
         break;
      }
   }
   if (found) {
      cout << "NO";
   } else {
      cout << "YES";
   }
}