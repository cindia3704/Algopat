/*
    작성자: 김지수
    작성일: 2022/07/24
    SWEA -- 수열 편집 (13501번)
*/

#include<iostream>
#define MAX 10000

using namespace std;

struct Node{
    int data;
    Node * link;
};

Node nodeList[MAX];
Node head; 
int nodeNum; 

void init(){
    head.link=nullptr; 
    nodeNum =0; 
}

Node* getNode(int data){
    nodeList[nodeNum].data = data;
    nodeList[nodeNum].link = nullptr;
    return &nodeList[nodeNum++];
}

void addNode(int num,int data){
    Node * prevNode = &head;
    for(int i=1;i<num;i++){
        prevNode = prevNode->link; 
    }
    Node * newNode = getNode(data);
    newNode ->link = prevNode->link;
    prevNode->link = newNode; 
}

void deleteNode(int num){
    Node * prevNode = &head;
    for(int i=0;i<num-1;i++){
        prevNode = prevNode->link; 
    }
    prevNode ->link = prevNode->link->link;
}

void changeNode(int num,int data){
    Node * prevNode = &head;
    for(int i=0;i<num;i++){
        prevNode = prevNode->link; 
    }
    prevNode ->data = data; 
}

void print(int target){
    Node * prevNode = &head;
    for(int i=0;i<target;i++){
        if(prevNode->link == nullptr){
            cout<<-1<<'\n';
            return;
        }
        prevNode = prevNode->link; 
    }
    cout<<prevNode->data<<'\n';
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        init();
        int seqLength,addNumTotal,targetIndex; 
        cin>>seqLength>>addNumTotal>>targetIndex; 
        
        for(int i=1;i<=seqLength;i++){
            int data;
            cin>>data; 
            addNode(i,data); 
           
        }
        

        for(int i=0;i<addNumTotal;i++){
            char command; 
            cin>>command;
            if(command == 'I'){
                int pos, data;
                cin>>pos>>data; 
                addNode(pos+1,data);
            }else if(command == 'D'){
                int pos;
                cin>>pos;
                deleteNode(pos+1);
            }else{
               int pos, data;
                cin>>pos>>data;
                changeNode(pos+1,data);  
            }

            
        }
		
        cout<<"#"<<test_case<<" ";
        print(targetIndex+1);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}