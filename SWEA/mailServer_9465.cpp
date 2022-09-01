
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
using namespace std; 

#define INIT         0
#define SENDMAIL     1
#define GETCOUNT     2
#define DELETEMAIL   3
#define SEARCHMAIL   4

 void init(int N, int K);
 void sendMail(char subject[], int uID, int cnt, int rIDs[]);
 int getCount(int uID);
 int deleteMail(int uID, char subject[]);
 int searchMail(int uID, char text[]);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

#define MAX_WORD 10000
static char Word[MAX_WORD][11];

static int N, W, minR, maxR, SW;

static int mSeed;
static int pseudo_rand(void)
{
	mSeed = mSeed * 214013 + 2531011;
	return (mSeed >> 16) & 0x7FFF;
}

static void make_string(int seed)
{
	mSeed = seed;

	for (int i = 0; i < W; ++i) {
		int length = 5 + pseudo_rand() % 6;
		for (int k = 0; k < length; ++k) {
			Word[i][k] = 'a' + pseudo_rand() % 26;
		}
		Word[i][length] = '\0';
	}
}

static void send_mail(int seed)
{
	char str[200];
	int pos = 0;

	mSeed = seed;

	int wcnt = 1 + pseudo_rand() % SW;
	for (int i = 0; i < wcnt; ++i) {
		int widx = pseudo_rand() % W;
		for (int k = 0; k < 10; ++k) {
			if (Word[widx][k] == '\0') break;
			str[pos++] = Word[widx][k];
		}
		str[pos++] = ' ';
	}
	str[pos - 1] = '\0';

	int uid = pseudo_rand() % N;
	int rcnt = minR + pseudo_rand() % (maxR - minR + 1);
	int rids[50];
	for (int i = 0; i < rcnt; ++i) {
		rids[i] = pseudo_rand() % N;
	}

	sendMail(str, uid, rcnt, rids);
}

static int delete_mail(int uid, int seed)
{
	char str[200];
	int pos = 0;

	mSeed = seed;

	int wcnt = 1 + pseudo_rand() % SW;
	for (int i = 0; i < wcnt; ++i) {
		int widx = pseudo_rand() % W;
		for (int k = 0; k < 10; ++k) {
			if (Word[widx][k] == '\0') break;
			str[pos++] = Word[widx][k];
		}
		str[pos++] = ' ';
	}
	str[pos - 1] = '\0';

	return deleteMail(uid, str);
}

static int run(int answer)
{
	int Q, K, cmd, sample, seed, param1, param2, ret;
	char str[30];

	scanf("%d %d %d %d", &Q, &sample, &N, &K);
	if (sample == 0) {
		scanf("%d %d %d %d %d", &W, &minR, &maxR, &SW, &seed);
		make_string(seed);
	}
    //cout<<"Q: "<<Q<<" k "
	init(N, K);

	for (int i = 1; i < Q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
		case SENDMAIL:
			if (sample == 1) {
				int uid, rcnt;
				int rids[10];
				scanf("%s %d %d", str, &uid, &rcnt);
				for (int k = 0; k < rcnt; ++k) scanf("%d", &rids[k]);
				for (int k = 0; k < 30; ++k) {
					if (str[k] == '\0') break;
					if (str[k] == '_') str[k] = ' ';
				}
				sendMail(str, uid, rcnt, rids);
			}
			else {
				scanf("%d", &seed);
				send_mail(seed);
			}
			break;
		case GETCOUNT:
			scanf("%d %d", &param1, &param2);
			ret = getCount(param1);
            cout<<"GET COUNT : "<<ret<<"  ans:"<<param2<<endl;
			if (ret != param2){
				answer = 0;
                cout<<"WRONG!!"<<endl;
            }
			break;
		case DELETEMAIL:
			if (sample == 1) {
				int uid;
				scanf("%d %s %d", &param1, str, &param2);
				for (int k = 0; k < 30; ++k) {
					if (str[k] == '\0') break;
					if (str[k] == '_') str[k] = ' ';
				}
				ret = deleteMail(param1, str);
                cout<<"DELETE MAIL : "<<ret<<"  ans:"<<param2<<endl;
				if (ret != param2){
					answer = 0;
                    cout<<"WRONG!!"<<endl;
                }
			}
			else {
				scanf("%d %d %d", &param1, &seed, &param2);
				ret = delete_mail(param1, seed);
                cout<<"DELETE MAIL : "<<ret<<"  ans:"<<param2<<endl;
				if (ret != param2){
					answer = 0;
                    cout<<"WRONG!!"<<endl;
                }
			}
			break;
		case SEARCHMAIL:
			scanf("%d %s %d", &param1, str, &param2);
			ret = searchMail(param1, str);
            cout<<"SEARCH MAIL : "<<ret<<"  ans:"<<param2<<endl;
			if (ret != param2){
                cout<<"WRONG!!"<<endl;
				answer = 0;
            }
			break;
		default:
			break;
		}
	}

	return answer;
}


int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, Mark;
	scanf("%d %d", &T, &Mark);

	for (int tc = 1; tc <= T; tc++) {
		printf("#%d %d\n", tc, run(Mark));
	}

	return 0;
}
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#define MAX 26
#define MAIL_MAX 10011
#define WORD_MAX 11
#define USER_MAX 1001
using namespace std; 
int wordNum;
int mailNum;
int mailLimit;
int arrLimit;

struct TrieNode{
    TrieNode* child[MAX];
    bool terminal;
    int idxNum;
    int cnt=0;

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
            //cout<<"cnt: "<<cnt<<endl;
            if(cnt==0){
                terminal = true;
                idxNum = ++wordNum;
                cnt++;
            }else{
                cnt++;
            }
            return idxNum;
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
                return idxNum;
            }else{
                return -1;
            }
        }
        int next = *key-'a';
        if(child[next]==NULL){
            return -1;
        }
        return child[next]->find(key+1);
    }

};


TrieNode *trie;
int mailWords[MAIL_MAX][WORD_MAX]; // 각 메일에 있는 단어들 
int mailLists[USER_MAX][MAIL_MAX];
int front[USER_MAX];
int rear[USER_MAX];

int getSize(int user){
    int temp = rear[user] - front[user];
    if(temp<0){
        return temp+arrLimit;
    }else{
        return temp;
    }
}

vector<string> getWords(char *key){
    //cout <<" get Word!!"<<endl;
    vector<string> ans;  
    char *word = strtok(key," ");
    while(word!=NULL){
        //cout<<"word:" <<word<<endl;
        ans.push_back(word);
        word = strtok(NULL," ");
    }
    return ans; 
}

void init(int N, int K){
    delete trie;
    wordNum = 0;
    mailNum = 0;
    mailLimit = K;
    arrLimit = K+10;
    trie = new TrieNode();
    memset(mailLists,-1,sizeof(mailLists));
    memset(mailWords,-1,sizeof(mailWords));
    memset(front,0,sizeof(front));
    memset(rear,0,sizeof(rear));
    return;
}

void sendMail(char subject[], int uID, int cnt, int rIDs[]){
   // cout<<"SEND MAIL!!"<<endl;
    vector<string> newWords = getWords(subject);
    int idx=0;
    for(int i=0;i<newWords.size();i++){
        int wordIdx = trie->insert(newWords[i].c_str());
       // cout<<"newWord: "<<newWords[i]<<"  idx:"<<wordIdx<<endl;
        mailWords[mailNum][idx] = wordIdx;
        idx++;
    }

    for(int i=0;i<cnt;i++){
        int user = rIDs[i];
        int userF = front[user];
        int userR = rear[user];
        mailLists[user][userR] = mailNum;
        rear[user] = (rear[user]+1)%(arrLimit);
       // cout<<"=====user: "<<user<<"  size:"<<getSize(user)<<"  mailLim:"<<mailLimit<<endl;;
        if(getSize(user) > mailLimit){
            mailLists[user][userF] = -1;
            front[user] = (front[user]+1)%(arrLimit);
        }
        //cout<<"front: "<<front[user]<<" rear:"<<rear[user]<<endl;
    }
    mailNum++;
    return;
}
int getCount(int uID){
    //cout<<"get Count USER: "<<uID<<" "<< getSize(uID)<<endl;
    return getSize(uID);
}

int deleteMail(int uID, char subject[]){
    //cout<<"DELETE MAIL"<<endl;
    vector<string> newWords = getWords(subject);
    vector<int> wordList;
    for(int i=0;i<newWords.size();i++){
        int wordIdx = trie->find(newWords[i].c_str());
       // cout<<"newWord: "<<newWords[i]<<"  idx:"<<wordIdx<<endl;
        wordList.push_back(wordIdx);        
    }
    if(wordList.size()==0){
        return 0;
    }

    int deleteCnt =0;
    int nowIdx = front[uID];
    
    while(true){
        int mailIdx = mailLists[uID][nowIdx];
        bool found = true;
       // cout<<"now:"<<nowIdx<<" mailIDX:"<<mailIdx<<endl;
        if(mailWords[mailIdx][wordList.size()]!=-1){
            found = false;
        }else{
            for(int i=0;i<WORD_MAX;i++){
                if(mailWords[mailIdx][i]==-1){
                    if(i<wordList.size()){
                        found = false;
                    }
                    break;
                }
                if(mailWords[mailIdx][i] == wordList[i]){
                    continue;
                }else{
                    found = false;
                    break;
                }
                
            }
        }
        if(found){
            deleteCnt++;
        }
        else{
            int moveIdx = (nowIdx - deleteCnt) < 0 ? (nowIdx-deleteCnt + arrLimit):nowIdx-deleteCnt;
            mailLists[uID][moveIdx] = mailLists[uID][nowIdx];
        }
        nowIdx = (nowIdx+1)%arrLimit;
        if(nowIdx == rear[uID]){
            break;
        }
    }
    rear[uID] = (rear[uID] - deleteCnt)<0 ? (rear[uID] - deleteCnt+arrLimit) : (rear[uID] - deleteCnt);
    //cout<<"rear:"<<rear[uID]<<endl;
   //cout<<"DELETE CNT: "<<deleteCnt<<endl;
    return deleteCnt;
}

int searchMail(int uID, char text[]){
   // cout<<"SEARCH MAIL"<<endl;
    int wordIdx = trie->find(text);

    int mailCnts = getSize(uID);
    int start = front[uID];
    int searchCnt = 0;
    for(int i=0;i<mailCnts;i++){
        int now = (start+i)%arrLimit;
        int mailIdx = mailLists[uID][now];
        //cout<<"now: "<<now<<"  mailIDX:"<<mailIdx<<endl;
        for(int i=0;i<WORD_MAX;i++){
            if(mailWords[mailIdx][i] == -1){
                break;
            }
            if(mailWords[mailIdx][i]==wordIdx){
                //cout<<"found!!: "<<i<<"  == "<<wordIdx<<endl;
                searchCnt++;
                break;
            }
        }
    } 
    //cout<<"SERACH CNT: "<<searchCnt<<endl;
    return searchCnt;
}

