/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 사칙연산 (1230번)
*/

#include<iostream>
#include <stack>
#include <string>
#define PLUS -1
#define MINUS -2
#define MULT -3
#define DIV -4
#define LPARAN -5
#define RPARAN -6
#define MAX 1001

using namespace std;

struct Node{
    int data; 
    Node * left; 
    Node * right;
};

Node * root; 
int nodeCnt;
Node nodelist[MAX];
stack<int> s;

void init(){
    root = nullptr;
}

Node * newNode(int data,int pos){
    nodelist[pos].data = data;
    nodelist[pos].left = nullptr;
    nodelist[pos].right = nullptr;
    return & nodelist[pos];
}

void traverse(Node * node){
    if(node == nullptr){
        return;
    }
    s.push(LPARAN);
    traverse(node->left);
    s.push(node->data);
    traverse(node->right);
    int next = s.top();
    if(next==LPARAN){
        s.pop();
    }else{
        int ret=0;
        s.pop();
        int op = s.top();
        if(op == LPARAN){
            ret = next; 
            s.pop();
        }else{
            s.pop();
            int num2 = s.top();
            s.pop();
            if(op == PLUS){
                ret =num2 +next;
            }else if(op == MINUS){
                ret= num2 - next;
            }else if(op == MULT){
                ret = num2*next;
            }else{
                if(next == 0){
                    ret = 0;
                }else{
                    ret = num2/next;
                }
            }
            s.pop();
        }
        s.push(ret);
    }
}

int main(int argc, char** argv)
{
	int test_case;
    
	for(test_case = 1; test_case <= 2; ++test_case)
	{
        init();
        int totalNode; 
        cin>>totalNode;
        
        for(int i=0;i<totalNode;i++){
            int nodeNum;
            cin>>nodeNum;
            string data; 
            cin>>data;
            if(data=="+" || data =="-" || data=="*" || data=="/"){
                int dataNum;
                if(data[0] == '+'){
                    dataNum = PLUS;
                }else if(data[0]=='-'){
                    dataNum = MINUS;
                }else if(data[0]=='*'){
                    dataNum = MULT;
                }else{
                    dataNum = DIV;
                }
               
                Node * nowNode = newNode(dataNum,nodeNum);
                if(cin.get()!='\n'){
                    int leftChild; 
                    cin>>leftChild;
                    nowNode->left = &nodelist[leftChild];
                    if(cin.get()!='\n'){
                        int rightChild; 
                        cin>>rightChild;
                        nowNode->right = & nodelist[rightChild]; 
                    }
                }
            }else{
                int datanum = stoi(data);
                Node * nowNode = newNode(datanum,nodeNum);
            }
            
        }
        root = &nodelist[1];
        traverse(root);
        cout<<"#"<<test_case<<" ";
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}