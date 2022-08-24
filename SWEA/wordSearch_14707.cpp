#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern int add(char str[]);
extern int remove(char str[]);
extern int search(char str[]);

/////////////////////////////////////////////////////////////////////////

#define MAX_LEN 30
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_SEARCH 4

static bool run() {
	int q;
	scanf("%d", &q);

	char str[MAX_LEN + 1];
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%s %d", str, &ans);
				ret = add(str);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%s %d", str, &ans);
				ret = remove(str);
				if (ans != ret)
					okay = false;
				break;
			case CMD_SEARCH:
				scanf("%s %d", str, &ans);
				ret = search(str);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include <iostream>
#define MAX 26
using namespace std; 

struct TrieNode{
    TrieNode* child[MAX];
    bool terminal;
    int cnt = 0;

    TrieNode():terminal(false){
        for(int i=0;i<MAX;i++){
            child[i] = NULL;
        }
    }

    ~TrieNode(){
        for(int i=0;i<MAX;i++){
            if(child[i]!=NULL){
                delete child[i];
            }
        }
    }
    int insert(const char *key){
        if(*key==0){
            terminal = true;
            cnt++;
            return cnt;
        }
        int next = *key-'a';
        if(child[next] == NULL){
            child[next] = new TrieNode();
        }
        return child[next]->insert(key+1);
    }

int find(const char *key){
        if(*key == 0){
            if(terminal){
                return cnt;
            }else{
                return -1;
            }
        }
        if(*key=='?'){
            int ans = 0;
            for(int i=0;i<26;i++){
                if(child[i]!=NULL){
                    int tempCnt = child[i]->find(key+1);
                    if(tempCnt>0){
                        ans+=tempCnt;
                    }
                }
            }
            return ans;
        }else{
            int next = *key-'a';
            if(child[next] == NULL){
                return -1;
            }
            return child[next]->find(key+1);
        }
    }

    int remove(const char *key){
        if(*key == 0){
            if(terminal){
                int ans = cnt; 
                cnt = 0;
                terminal=false;
                return ans;
            }else{
                return -1;
            }
        }
       if(*key=='?'){
            int tempAns = 0;
            for(int i=0;i<26;i++){
                if(child[i]!=NULL){
                 int t = child[i]->remove(key+1);
                   if(t>0){
                     tempAns+=t;
                   }
                }
            }
            return tempAns;
        }else{
            int next = *key-'a';
            if(child[next] == NULL){
                return -1;
            }
            return child[next]->remove(key+1);
        }
    }
};

TrieNode *trie;

void init() {
    delete trie;
    trie = new TrieNode();
	return;
}

int add(char str[]) {
    //cout<<"ADD"<<endl;
    int tempAns = trie->insert(str);
    //cout<<"tempAns: "<<tempAns<<endl;
	return tempAns;
}

int remove(char str[]) {
    //cout<<"REMOVE!!"<<endl;
    int temp = trie->remove(str);
    if(temp < 0){
        temp = 0;
    }
   //cout<<"ret: "<<temp<<endl;
	return temp;
}

int search(char str[]) {
   // cout<<"SEARCH!!"<<endl;
    int temp = trie->find(str);
     if(temp < 0){
        temp = 0;
    }
   // cout<<"RET: "<<temp<<endl;
	return temp;
}