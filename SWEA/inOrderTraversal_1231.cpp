/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 중위 순회 (1231번)
*/

#include <iostream>
#include <cstring>
#define MAX 101
using namespace std; 

struct Node{
    char data;
    Node *left;
    Node *right;
}; 

Node nodeList[MAX]; 
Node *root;

void init(){
    root = nullptr;
}

Node * newNode(char n,int nodeCnt){
    nodeList[nodeCnt].data = n;
    nodeList[nodeCnt].left = nullptr;
    nodeList[nodeCnt].right = nullptr;
    return &nodeList[nodeCnt++];
}

void traversal(Node * node){
    if(node == nullptr){
        return;
    }
    // 여기에 넣으면 전위 순회 
    traversal(node->left);
    cout<<node->data<<" ";  // 여기가 중위순회 
    traversal(node->right);
    // 여기에 넣으면 후위 순회 
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int testCase = 1; testCase<=10;testCase++){
        init();
        int nodeNum;
        cin>>nodeNum;
        for(int i=0;i<nodeNum;i++){
            int nowNodeNum;
            char nowData; 
            cin>>nowNodeNum;
            cin>>nowData;
            Node* nowNode = newNode(nowData,nowNodeNum);
            int leftNodeNum,rightNodeNum;
            if(cin.get()!='\n'){    // 각 라인마다 몇개의 입력이 공백 포함해서 들어올지 모를때 사용 
                cin>>leftNodeNum;
                 nowNode->left = &nodeList[leftNodeNum];
                if(cin.get()!='\n'){
                    cin>>rightNodeNum;
                    nowNode->right = &nodeList[rightNodeNum];
                }
            }
        }
        root = &nodeList[1];
        cout<<"#"<<testCase<<" ";
        traversal(root);
        cout<<"\n";

    }
}