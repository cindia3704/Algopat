/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 사칙연산 유효성 검사 (1233번)
*/

#include <iostream>
#include <stack>
#define MAX 501
using namespace std;

struct Node{
    char data;
    Node * left;
    Node * right;
};

Node* root; 
Node nodeList[MAX];
bool isPossible = true;
stack<char> s;

void init(){
    root = nullptr;
}

Node * newNode(char data, int pos){
    nodeList[pos].data = data;
    nodeList[pos].left = nullptr;
    nodeList[pos].right = nullptr;
    return &nodeList[pos];
}

// 중위순회로 값들 stack에 넣어줌 
void traversal(Node * node){
    if(node == nullptr){
        return;
    }
    traversal(node ->left);
    s.push(node->data);
    traversal(node->right);
}

int main(int argc, char** argv)
{
	for(int test_case = 1; test_case <= 10; ++test_case)
	{
        isPossible = true;
        init();
        int nodeNum;
        cin>>nodeNum;
        for(int i=0;i<nodeNum;i++){
            int pos;
            char data; 
            cin>>pos>>data; 
            Node * nowNode = newNode(data,pos);
            if(cin.get()!='\n'){
                int leftNum;
                cin>>leftNum;
                nowNode->left = &nodeList[leftNum];
                if(cin.get()!='\n'){
                    int rightNum;
                    cin>>rightNum;
                    nowNode->right = &nodeList[rightNum];
                }
            }
        }
        root = &nodeList[1];
        cout<<"#"<<test_case<<" ";
        traversal(root);
        // 유효하기 위해서는 숫자-연산-숫자 이렇게 나와야함 
        bool isNum = true;
        while(!s.empty()){
            if(isNum){
                if(s.top()=='+' || s.top() == '-' || s.top() == '*'|| s.top() == '/'){
                    isPossible = false;
                }
            }else{
                if((s.top()!='+' && s.top() != '-' && s.top() != '*'&& s.top() != '/')){
                    isPossible = false;
                }
            }
            isNum = !isNum;
            s.pop();
        }
        cout<<isPossible<<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}