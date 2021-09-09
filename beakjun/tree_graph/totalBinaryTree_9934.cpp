/*
    작성자: 김지수
    작성일: 2021/09/10
    백준 --  완전 이진 트리 (9934번)
    문제: 결구 inorder traversal
*/

#include <tgmath.h>

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N = 1024;
int height;
struct Tree {
   int left, right;
};
Tree tree[MAX_N];

void findRoot(vector<int> visitOrder, int parentNode, int isLeft) {
   int rootIdx = visitOrder.size() / 2;  // 가운데 = 각 height에서 parent

   if (parentNode != -1) {
      // 루트 노드가 아닐때
      if (isLeft == 1) {
         tree[parentNode].left = visitOrder[rootIdx];
      } else {
         tree[parentNode].right = visitOrder[rootIdx];
      }
      if (visitOrder.size() == 1) {  // 리프노드면 반환
         return;
      }
   }
   //[begin,mid)
   vector<int> leftTree =
       vector<int>(visitOrder.begin(), visitOrder.begin() + rootIdx);
   //(mid,end]
   vector<int> rightTree =
       vector<int>(visitOrder.begin() + rootIdx + 1, visitOrder.end());
   findRoot(leftTree, visitOrder[rootIdx], 1);
   findRoot(rightTree, visitOrder[rootIdx], 0);
}

void printTree(int start) {
   int current = 1;
   queue<pair<int, int> > nodes;
   nodes.push(make_pair(1, start));
   while (!nodes.empty()) {
      int nowNode = nodes.front().second;
      int nowHeight = nodes.front().first;
      nodes.pop();
      if (nowHeight > height) {
         return;
      }
      if (nowNode == -1) continue;
      if (nowHeight > current) {
         current = nowHeight;
         cout << endl;
      }
      cout << nowNode << " ";
      nodes.push(make_pair((nowHeight + 1), tree[nowNode].left));
      nodes.push(make_pair((nowHeight + 1), tree[nowNode].right));
   }
}
int main(void) {
   cin >> height;
   int nodeNum = pow(2, height) - 1;
   vector<int> visitOrder;

   for (int i = 0; i < nodeNum; i++) {
      int node;
      cin >> node;
      visitOrder.push_back(node);
   }
   findRoot(visitOrder, -1, 0);
   printTree(visitOrder[visitOrder.size() / 2]);
}