/*
    작성자: 김지수
    작성일: 2021/02/24
    백준 -- 트리 순회(1991번)
    문제:이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder
    traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을
    작성하시오.
*/

#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
   char left;
   char right;
};
struct TreeNode tree[100];
void preorder(char root) {
   if (root == '.') {
   } else {
      cout << root;
      preorder(tree[root].left);
      preorder(tree[root].right);
   }
}
void inorder(char root) {
   if (root == '.') {
   } else {
      inorder(tree[root].left);
      cout << root;
      inorder(tree[root].right);
   }
}
void postorder(char root) {
   if (root == '.') {
   } else {
      postorder(tree[root].left);
      postorder(tree[root].right);
      cout << root;
   }
}
int main(void) {
   int totalNode;
   cin >> totalNode;
   char topRoot;
   for (int i = 0; i < totalNode; i++) {
      char root, left, right;
      cin >> root >> left >> right;
      if (i == 0) {
         topRoot = root;
      }
      tree[root].left = left;
      tree[root].right = right;
   }
   preorder(topRoot);
   cout << endl;
   inorder(topRoot);
   cout << endl;
   postorder(topRoot);
}