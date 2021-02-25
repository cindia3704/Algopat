/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 트리의 순회(2263번)
    문제:n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이
   매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때,
   프리오더를 구하는 프로그램을 작성하시오.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> inorder;
vector<int> postorder;
int position[100001];

void getPreorder(int inStart, int inEnd, int postStart, int postEnd) {
   // cout << "inStart: " << inStart << " inEnd: " << inEnd
   //      << " postStart: " << postStart << " postEnd:" << postEnd << endl;
   if (inStart > inEnd || postStart > postEnd) {
      return;
   }

   int root = postorder[postEnd];
   int idx = position[root];
   int leftTreeSize = idx - inStart;
   cout << root << " ";
   getPreorder(inStart, idx - 1, postStart, postStart + leftTreeSize - 1);
   getPreorder(idx + 1, inEnd, postStart + leftTreeSize, postEnd - 1);
   return;
}

int main(void) {
   int nodeCount;
   cin >> nodeCount;
   for (int i = 0; i < nodeCount; i++) {
      int input;
      cin >> input;
      inorder.push_back(input);
   }
   for (int i = 0; i < nodeCount; i++) {
      int input;
      cin >> input;
      postorder.push_back(input);
      position[inorder[i]] = i;
   }

   getPreorder(0, nodeCount - 1, 0, nodeCount - 1);
}