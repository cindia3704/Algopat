/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 암호문 3 (1230번)
*/

#include <iostream>
#define MAX_NODE 10000
using namespace std; 

struct NODE{
    int data;
    NODE *link;
};

NODE head; 
NODE node[MAX_NODE];
int nodeCnt;

void init(){
    head.link = nullptr; 
    nodeCnt = 0;
}

NODE* getNode(int data) {
   node[nodeCnt].data = data;
   node[nodeCnt].link = nullptr;
   return &node[nodeCnt++];
}

void deleteNode(NODE * prevNode){
    NODE * nowNode = prevNode->link;
    prevNode->link = nowNode->link;
    free(nowNode);
}


void addNodeAtPos(NODE *prevNode, int data){
    NODE * newNode = getNode(data);
    newNode->link = prevNode->link;
    prevNode->link = newNode;
}

void print(){
    NODE *nowNode = &head;
    for(int i=0;i<10;i++){
        nowNode= nowNode->link;
        cout<<nowNode->data<<" ";
    }
    cout<<"\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int test_case = 1;test_case<=10; test_case++){
        init();
        int originalLength;
        cin>>originalLength;

        NODE *prevNode = &head; 
        for(int i=0;i<originalLength;i++){
            int data; 
            cin>>data;
            addNodeAtPos(prevNode,data);
            prevNode=prevNode->link;
        }

        int commandNum;
        cin>>commandNum;
        for(int i=0;i<commandNum;i++){
            char command; 
            cin>>command;
            if(command == 'I'){
                NODE * nodeBF = &head;
                int numNode,totalNode;
                cin>>numNode>>totalNode;
                for(int idx = 0;idx<numNode;idx++){
                    nodeBF=nodeBF->link;
                }
                for(int n=0;n<totalNode;n++){
                    int d;
                    cin>>d;
                    addNodeAtPos(nodeBF,d);
                    nodeBF = nodeBF->link;
                }
            }else if(command == 'D'){
                int nodePos,deleteNum;
                cin>>nodePos>>deleteNum;
                NODE * nodeBF = &head;
                for(int pos = 0;pos<nodePos;pos++){
                    nodeBF = nodeBF->link;
                }
                for(int n=0;n<deleteNum;n++){
                    deleteNode(nodeBF);
                }

            }else{
                NODE * nodeBF = &head;
                int totalNode;
                cin>>totalNode;
                while(nodeBF->link!=nullptr){
                    nodeBF=nodeBF->link;
                }
                for(int n=0;n<totalNode;n++){
                    int d;
                    cin>>d;
                    addNodeAtPos(nodeBF,d);
                    nodeBF = nodeBF->link;
                }
            }
        }
        cout<<"#"<<test_case<<" ";
        print();
    }
}