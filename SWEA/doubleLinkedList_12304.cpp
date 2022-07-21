/*
    작성자: 김지수
    작성일: 2022/07/21
    SWEA -- 기초 Double Linked List 연습 (12304번)
*/

#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node head;

bool canAddNode(int data){
	Node* prevNode = &head;
	while (prevNode->next != nullptr) {
		prevNode = prevNode->next; 
		if (prevNode->data == data) {
			return false;
		}
	}
	return true; 
}


Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	head.prev = nullptr;
	head.next = nullptr; 
	nodeCnt = 0;
	return; 
}

void addNode2Head(int data)
{	
	if (canAddNode(data)) {
		Node* prevNode = &head;
		Node* newNode = getNode(data);
		newNode->prev = prevNode;
		newNode->next = prevNode->next;
		head.next = newNode;
	}
	return;
}

void addNode2Tail(int data)
{
	if (canAddNode(data)) {
		Node* prevNode = &head;
		while (prevNode->next != nullptr) {
			prevNode = prevNode->next;
		}

		Node* newNode = getNode(data);
		newNode->prev = prevNode;
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
	return; 
}

void addNode2Num(int data, int num)
{
	if (canAddNode(data)) {
		Node* prevNode = &head;
		for (int i = 1; i < num; i++) {
			prevNode = prevNode->next;
		}
		Node* newNode = getNode(data);
		newNode->next = prevNode->next;
		newNode->prev = prevNode;
		prevNode->next = newNode;
	}
	return; 
}

int findNode(int data)
{
	Node* prevNode = &head;
	int idx = 1;
	while (prevNode->next != nullptr) {
		prevNode = prevNode->next;
		if (prevNode->data == data) {
			return idx;
		}
		idx++;
	}
}

void removeNode(int data)
{	
	if (!canAddNode(data)) {
		Node* prevNode = &head;
		while (prevNode->next != nullptr && prevNode->next->data != data) {
			prevNode = prevNode->next;
		}

		Node* nowNode = prevNode->next;
		if (nowNode->next != nullptr) {
			nowNode->next->prev = prevNode;
		}
		prevNode->next = nowNode->next;
	}
	return;
}

int getList(int output[MAX_NODE])
{	
	Node* prevNode = &head;
	int idx = 0;
	while (prevNode->next != nullptr) {
		prevNode = prevNode->next; 
		output[idx] = prevNode->data;
		idx++;
	}
	return idx; 
}

int getReversedList(int output[MAX_NODE])
{
	Node* prevNode = &head;
	int idx = 0;
	int temp[MAX_NODE];
	while (prevNode->next != nullptr) {
		prevNode = prevNode->next;
		temp[idx] = prevNode->data;
		idx++;
	}
	for (int j = 0; j<idx; j++) {
		output[j] = temp[idx - j - 1];
	}
	
	return idx;
}
