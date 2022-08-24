#include <iostream>
#define MAX 26
using namespace std; 

struct TrieNode{
    TrieNode* child[MAX];
    bool terminal;

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

    void insert(const char *key){
        if(*key==0){
            terminal = true;
            return;
        }
        int next = *key-'a';
        if(child[next] == NULL){
            child[next] = new TrieNode();
        }
        child[next]->insert(key+1);
    }

    bool find(const char *key){
        if(*key == 0){
            return true; 
        }
        int next = *key-'a';
        if(child[next] == NULL){
            return false;
        }
        return child[next]->find(key+1);
    }

};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    TrieNode *ptn = new TrieNode();
    ptn->insert("there");
    ptn->insert("the");
    ptn->insert("answer");
    ptn->insert("a");
    cout<<"insert DONE!!"<<endl;

    if(!ptn->find("hello")){
        cout<<"hello is in\n";
    }

    if(ptn->find("the")){
        cout<<"the is in\n";
    }
    
}