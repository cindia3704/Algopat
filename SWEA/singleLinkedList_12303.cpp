/*
    작성자: 김지수
    작성일: 2022/07/21
    SWEA -- 기초 Single Linked List 연습 (12303번)
*/

#define MAX_NODE 10000

using namespace std;

struct Node {
   int data;
   Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node head;  // head는 포인터가 아니라 노드여야함 

// 중복값 넣기 안되서 넣어도 되는지 확인위한 함수 
bool findData(int data) {
   Node* n = &head;
   while (n->next!=nullptr) {
      n = n->next; 
      if (n->data == data) {
         return false;
      }
   }
   return true;
}

// 새 노드 할당 할때 사용 
Node* getNode(int data) {
   node[nodeCnt].data = data;
   node[nodeCnt].next = nullptr;
   return &node[nodeCnt++];
}

// 초기화 
void init()
{
   head.next = nullptr;
   nodeCnt = 0;
}

// 맨 앞에 새 데이터 추가 
void addNode2Head(int data)
{
    // 중복값없을 경우
   if (findData(data)) {
    // 노드 할당 & 데이터 저장후 
      Node* newNode = getNode(data);
      //추가할 노드의 next = 원래 헤드의 next 
      newNode->next = head.next;
      // 헤드의 다음이 현 노드를 바라보게 
      head.next = newNode;
   }
   return;
}

// 맨 뒤에 새 데이터 추가 
void addNode2Tail(int data)
{
    // 중복값 없을 경우 
   if (findData(data)) {
    // 헤드부터 다음으로 이동하며 다음이 nullptr일때 멈춤 
      Node* prevNode = &head;
      while (prevNode->next != nullptr) {
         prevNode = prevNode->next;
      }

        // 새 노드 할당 & 값 저장 후 
      Node* newNode = getNode(data);
      // nullptr 바로 직전 노드가 해당 노드를 바라보게 함 
      prevNode->next = newNode;
   }
   return;
}

void addNode2Num(int data, int num)
{   
    // 중복 값 없을 경우 
   if (findData(data)) {
    // 헤드부터 num-1만큼 이동 
      Node* prev = &head;
      for (int i = 1; i < num; i++) {
         prev = prev->next;
      }
      // 새 노드 할당 & 값 저장 
      Node* newNode = getNode(data);

      newNode->next = prev->next;
      prev->next = newNode;
   }
   return;
}

void removeNode(int data)
{
    // 헤드부터 보면서 다음 노드의 data 가 삭제하려는 데이터가 아닐때 계속 다음으로 이동 
   Node* prevNode = &head;
   while (prevNode->next != nullptr && prevNode->next->data != data) {
      prevNode = prevNode->next;
   }
   // 다음이 nullptr이 아닐경우 다음값을 해당 노드 건너뛰게 업데이트 
   if (prevNode->next != nullptr) {
      prevNode->next = prevNode->next->next;
   }

   return;
}

int getList(int output[MAX_NODE])
{   
   int idx=0;
   Node* prev = &head;
   while (prev->next!=nullptr) {
      prev = prev->next;
      output[idx] = prev->data;
      idx++;
   }
   output[idx] = prev->data;
   return idx;
}