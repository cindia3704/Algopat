/*
    작성자: 김지수
    작성일: 2021/10/11
    백준 -- 최소 스패닝 트리 (1197번)
    문제:
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int nodeNum, edgeNum;
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

bool cmp(Node a, Node b) { return a.w < b.w; }
int main(void) {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> nodeNum >> edgeNum;
   int parent[nodeNum + 1];
   for (int i = 1; i <= nodeNum; i++) {
      parent[i] = i;
   }
   vector<Node> edgeList;
   for (int i = 0; i < edgeNum; i++) {
      int node1, node2, weight;
      cin >> node1 >> node2 >> weight;
      Node n;
      n.n1 = node1;
      n.n2 = node2;
      n.w = weight;
      edgeList.push_back(n);
   }
   sort(edgeList.begin(), edgeList.end(), cmp);
   int sum = 0;
   for (int i = 0; i < edgeList.size(); i++) {
      bool cycle = findParent(parent, edgeList[i].n1, edgeList[i].n2);
      if (!cycle) {
         unionParent(parent, edgeList[i].n1, edgeList[i].n2);
         sum += edgeList[i].w;
      }
   }
   cout << sum;
}