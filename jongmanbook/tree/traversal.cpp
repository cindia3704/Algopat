/*
    작성자: 김지수
    작성일: 2021/02/25
    종만북 -- TRAVERSAL, 난이도: 하
    문제: 어떤 이진 트리를 전위 순회했을 때 노드들의 방문 순서와, 중위
   순회했을때 노드들의 방문 순서가 주어졌다고 하자. 이 트리를 후위 순회했을 때
   각 노드들을 어떤 순서대로 방문하게 될지 계산하는 프로그램
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sliceTree(const vector<int>& v, int start, int end) {
   return vector<int>(v.begin() + start, v.begin() + end);
}

vector<int> getPostOrder(vector<int>& postorder, const vector<int>& preorder,
                         const vector<int>& inorder) {
   int treeSize = preorder.size();
   if (treeSize == 0) {
      return postorder;
   }

   int root = preorder[0];
   int leftTreeSize =
       find(inorder.begin(), inorder.end(), root) - inorder.begin();
   int rightTreeSize = treeSize - leftTreeSize - 1;

   getPostOrder(postorder, sliceTree(preorder, 1, leftTreeSize + 1),
                sliceTree(inorder, 0, leftTreeSize));
   getPostOrder(postorder, sliceTree(preorder, leftTreeSize + 1, treeSize),
                sliceTree(inorder, leftTreeSize + 1, treeSize));
   postorder.push_back(root);
   return postorder;
}

int main(void) {
   int testCase, numNode, input;
   vector<vector<int> > preorderList;
   vector<vector<int> > inorderList;
   vector<vector<int> > postorderList;
   vector<int>::iterator ptr;
   cin >> testCase;
   for (int i = 0; i < testCase; i++) {
      cin >> numNode;
      vector<int> preorder;
      vector<int> inorder;
      vector<int> postorder;
      for (int j = 0; j < numNode; j++) {
         cin >> input;
         preorder.push_back(input);
      }
      preorderList.push_back(preorder);
      for (int j = 0; j < numNode; j++) {
         cin >> input;
         inorder.push_back(input);
      }
      inorderList.push_back(inorder);
      postorderList.push_back(getPostOrder(postorder, preorder, inorder));
   }
   for (int i = 0; i < testCase; i++) {
      for (ptr = postorderList[i].begin(); ptr != postorderList[i].end();
           ++ptr) {
         cout << *ptr << " ";
      }
      cout << endl;
   }
}
