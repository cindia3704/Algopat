
/*
    작성자: 김지수
    작성일: 2022/08/31
    SWEA -- 문자열 암호화
*/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int n, char init_string[]);
extern int change(char string_A[], char string_B[]);
extern void result(char ret[]);

static int seed = 5;  // seed can be changed
static int pseudo_rand(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

#define MAXL (50005)
#define DUMMY_LEN (5959)

static int init_string_len = 0, char_type = 0, query_cnt = 0;
static char dummy1[DUMMY_LEN];
static char init_string[MAXL];
static char dummy2[DUMMY_LEN];
static char result_string[MAXL];
static char dummy3[DUMMY_LEN];
static char user_ans_string[MAXL];
static char dummy4[DUMMY_LEN];
static char string_A[4], string_B[4];


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main() {
	setbuf(stdout, NULL);
//	freopen("sample_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	int total_score = 0;
	for (int TC = 1; TC <= T; TC++) {
		int score = 100;
		scanf("%d%d%d%d", &seed, &init_string_len, &char_type, &query_cnt);
		
		for (int i = 0; i < init_string_len; i++)
		{
			init_string[i] = pseudo_rand() % char_type + 'a';
		}
		init_string[init_string_len] = '\0';

		init(init_string_len, init_string);

		string_A[3] = string_B[3] = '\0';
		for (int i = 0; i < query_cnt; i++)
		{
			for (int k = 0; k < 3; k++)
			{
				string_A[k] = pseudo_rand() % char_type + 'a';
				string_B[k] = pseudo_rand() % char_type + 'a';
			}
			int user_ans = change(string_A, string_B);
			int ans;
			scanf("%d", &ans);

			if (ans != user_ans)
			{
				score = 0;
			}
		}

		result(user_ans_string);
		scanf("%s", result_string);

		for (int i = 0; i < init_string_len; i++)
		{
			if (result_string[i] != user_ans_string[i])
			{
				score = 0;
				break;
			}
		}

		total_score += score;
		printf("#%d %d\n", TC, score);
	}
	printf("Total score : %d\n", total_score/T);

	return 0;
}

void printDDL(struct Node* head)
{
    while (head != NULL)
    {
       
        printf("%d ⇔ ", head->data);
         head = head->next;
    }
 
    printf("NULL");
}
 
 

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define MAX_NODE 50002
#define MAX_HASH 18000
using namespace std; 
struct Node {
	int data;
    int hash;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
Node* hashList[MAX_HASH];

int nodeCnt;
int strLen;
Node* hashCache[MAX_NODE];
char *str;
int changedIdx[MAX_NODE];


int getHash(int idx){
    return (str[idx]-'a')*(26*26)+(str[idx+1]-'a')*26+(str[idx+2]-'a');
}

int getHashString(const char *key){
    return (key[0]-'a')*(26*26)+(key[1]-'a')*26+(key[2]-'a');
}

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

bool removeNode(struct Node** headRef,Node * target)
{
    //cout<<"remove: "<<data<<endl;
   
    Node ** p = headRef;

    while (*p != nullptr && (*p)->data !=target->data) {
        p = &(*p)->next;
    }
    if((*p)->data == target->data){
        Node * a = *p;
        //cout<<"P :"<<*p<<"  a:"<<a<<endl;
        // *p = (*p)->next;
        
        if((*p)->next !=nullptr){
            (*p)->next->prev = (a)->prev;
        }
        *p = (*p)->next;
        return true;
    }
    return false;
}



void push(struct Node** headRef, Node* newNode)
{
   // Node* nowNode = getNode(data);
    newNode->prev = nullptr;
    newNode->next = *headRef;
 
    // 기존 헤드 노드의 `prev`를 새 노드를 가리키도록 변경
    if (*headRef != nullptr) {
        (*headRef)->prev = newNode;
    }
 
    // 헤드 포인터 업데이트
    *headRef = newNode;
}

void split(struct Node* head, struct Node** a, struct Node** b)
{
    struct Node* slow = head;
    struct Node* fast = head->next;
 
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    *b = slow->next;
    slow->next = nullptr;
}
 
// 두 개의 정렬된 목록의 노드를 병합하는 재귀 함수
// 정렬된 단일 목록으로
struct Node* merge(struct Node* a, struct Node* b)
{
    // 기본 케이스
    if (a == nullptr) {
        return b;
    }
 
    if (b == nullptr) {
        return a;
    }
 
    if (a->data < b->data)
    {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = nullptr;
        return a;
    }
    else {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = nullptr;
        return b;
    }
}
 
void mergesort(struct Node** head)
{
    // 기본 케이스: 0 또는 1 노드
    if (*head == nullptr || (*head)->next == nullptr) {
        return;
    }
 
    // 머리를 `a`와 `b` 하위 목록으로 분할
    struct Node* a = *head, *b = nullptr;
    split(*head, &a, &b);
 
    // 하위 목록을 재귀적으로적으로 정렬
    mergesort(&a);
    mergesort(&b);
 
    // 두 개의 정렬된 목록을 병합합니다.
    *head = merge(a, b);
}
 


void init(int n, char init_string[])
{
    //cout<<"init: "<<init_string<<endl;
    for(int i=0;i<MAX_HASH;i++){
        hashList[i] = nullptr;
        hashCache[i] = nullptr;
    }
	nodeCnt = 0;
    strLen = n;
    str = init_string;
    for(int i=0;i<n-2;i++){
        int hashNum = getHash(i);
       // cout<<"\nhash: "<<hashNum<<" i:"<<i<<endl;
        hashCache[i] = getNode(i);
        hashCache[i]->hash = hashNum;
        push(&hashList[hashNum],hashCache[i]);
        printDDL(hashList[hashNum]);
    }
	return; 
}

int change(char string_A[], char string_B[]){
    //cout<<"\nchange  "<<"a: "<<string_A<<"  b:"<<string_B<<endl;
    int hashNum = getHashString(string_A);

    int changeCnt = 0;
    int idx = -1;
    mergesort(&hashList[hashNum]);
    printDDL(hashList[hashNum]);
    Node* prevNode = hashList[hashNum];
	while (prevNode!= nullptr) {
        int firstIdx = prevNode->data;
       // cout<<"idx:"<<idx<< "  first:"<<firstIdx<<endl;

        if(firstIdx < idx){
            prevNode = prevNode->next;
            continue;
        }
       // cout<<"\nfirstIdx: "<<firstIdx<<" chang:"<<changeCnt<<endl;
        changedIdx[changeCnt++] = firstIdx;
        str[firstIdx] = string_B[0];
        str[firstIdx+1] = string_B[1];
        str[firstIdx+2] = string_B[2];
       // prevNode = prevNode->next;
        idx = firstIdx+3;
    }

   //cout<<" start & end   changCnt: "<<changeCnt<<endl;
    for(int i = 0;i<changeCnt;i++){
        int start = (changedIdx[i]-2)<0 ? 0: changedIdx[i]-2;
        int end = (changedIdx[i]+2) >=strLen-2 ? strLen-3:changedIdx[i]+2;
        //cout<<"idx: "<<changedIdx[i]<<"  start:"<<start<<"  end:"<<end<<endl;
        for(int k=start;k<=end;k++){
            int originalHashNum = getHash(k);
            //cout<<"changed Hash: "<<originalHashNum<<"  original: "<<hashCache[k]->hash<<endl;
            if(hashCache[k]->hash == originalHashNum){
                continue;
            }
            else{
                if(removeNode(&hashList[hashCache[k]->hash],hashCache[k])){
                //removeNode(&hashList[hashCache[k]],k);
                 //cout<<"\n===AF REMOVE===="<<endl;
                //printDDL(hashList[hashCache[k]->hash]);
                    hashCache[k]->hash = originalHashNum;
                    push(&hashList[originalHashNum],hashCache[k]);
                }
            }
        }
    }
    return changeCnt; 

}
 void result(char ret[]){
    for(int i=0;i<strLen;i++){
        ret[i] = str[i];
    }
 }
