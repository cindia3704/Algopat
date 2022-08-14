/*
    작성자: 김지수
    작성일: 2022/08/15
    백준 -- 물통 (2251번)
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <set> 
#define MAX 201
using namespace std; 

struct Bottle{
    int amount;
    int limit; 
};

bool visited[MAX][MAX][MAX];
set<int> ans; 

void dfs(Bottle a, Bottle b, Bottle c){
    if(a.amount == 0){
        ans.insert(c.amount);
    }
    visited[a.amount][b.amount][c.amount] = true; 

    // a->b로 
    if(a.amount>0){
        // b에 더 넣을 수 있을때 
        if(b.amount<b.limit){
            // b에 더 넣을 수 있는 용량 
            int AtoBMove = b.limit-b.amount; 
            int nextB = (AtoBMove>=a.amount) ? b.amount+a.amount : b.limit;
            int AtoBLeft = (AtoBMove>=a.amount) ? 0 : a.amount-AtoBMove;
            if(AtoBLeft >=0){
                if(!visited[AtoBLeft][nextB][c.amount]){

                    Bottle aNext,bNext;
                    aNext.amount = AtoBLeft;
                    aNext.limit = a.limit;
                    bNext.amount = nextB; 
                    bNext.limit = b.limit;
                    dfs(aNext,bNext,c);
                }
            }
        }
    }
    // a->c로 
    if(a.amount>0){
        // c에 더 넣을 수 있을때 
        if(c.amount<c.limit){
            // c에 더 넣을 수 있는 용량 
            int AtoCMove = c.limit-c.amount; 
            int nextC = (AtoCMove>=a.amount) ? c.amount+a.amount : c.limit;
            int AtoCLeft = (AtoCMove>=a.amount) ? 0 : a.amount-AtoCMove;
            if(AtoCLeft >=0){
                if(!visited[AtoCLeft][b.amount][nextC]){
                    Bottle aNext,cNext;
                    aNext.amount = AtoCLeft;
                    aNext.limit = a.limit;
                    cNext.amount = nextC;
                    cNext.limit = c.limit;
                    
                    dfs(aNext,b,cNext);
                }
            }
        }
    }
    // b->c로 
    if(b.amount>0){
        // c에 더 넣을 수 있을때 
        if(c.amount<c.limit){
            // c에 더 넣을 수 있는 용량 
            int BtoCMove = c.limit-c.amount; 
            int nextC = (BtoCMove>=b.amount) ? c.amount+b.amount : c.limit;
            int BtoCLeft = (BtoCMove>=b.amount) ? 0 : b.amount-BtoCMove;
            if(BtoCLeft >=0){
                if(!visited[a.amount][BtoCLeft][nextC]){
                    Bottle bNext,cNext;
                    bNext.amount = BtoCLeft; 
                    bNext.limit = b.limit;
                    cNext.amount = nextC;
                    cNext.limit = c.limit;
                    dfs(a,bNext,cNext);
                }
            }
        }
    }
    // b->a로 
    if(b.amount>0){
        // a에 더 넣을 수 있을때 
        if(a.amount<a.limit){
            // a에 더 넣을 수 있는 용량 
            int BtoAMove = a.limit-a.amount; 
            int nextA = (BtoAMove>=b.amount) ? a.amount+b.amount : a.limit;
            int BtoALeft = (BtoAMove>=b.amount) ? 0 : b.amount-BtoAMove;
            if(BtoALeft >=0){
                if(!visited[nextA][BtoALeft][c.amount]){
                    Bottle aNext,bNext;
                    aNext.amount = nextA;
                    aNext.limit = a.limit;
                    bNext.amount = BtoALeft; 
                    bNext.limit = b.limit;
                   
                    dfs(aNext,bNext,c);
                }
            }
        }
    }
    // c->a로 
    if(c.amount>0){
        // a에 더 넣을 수 있을때 
        if(a.amount<a.limit){
            // a에 더 넣을 수 있는 용량 
            int CtoAMove = a.limit-a.amount; 
            int nextA = (CtoAMove>=c.amount) ? a.amount+c.amount : a.limit;
            int CtoALeft = (CtoAMove>=c.amount) ? 0 : c.amount-CtoAMove;
            if(CtoALeft >=0){
                if(!visited[nextA][b.amount][CtoALeft]){
                    Bottle aNext,cNext;
                    aNext.amount = nextA;
                    aNext.limit = a.limit;
                    cNext.amount = CtoALeft;
                    cNext.limit = c.limit;
                    dfs(aNext,b,cNext);
                }
            }
        }
    }
    // c->b로 
    if(c.amount>0){
        // b에 더 넣을 수 있을때 
        if(b.amount<b.limit){
            // b에 더 넣을 수 있는 용량 
            int CtoBMove = b.limit-b.amount; 
            int nextB = (CtoBMove>=c.amount) ? b.amount+c.amount : b.limit;
            int CtoBLeft = (CtoBMove>=c.amount) ? 0 : c.amount-CtoBMove;
            if(CtoBLeft >=0){
                if(!visited[a.amount][nextB][CtoBLeft]){
                    Bottle bNext,cNext;
                   
                    bNext.amount = nextB; 
                    bNext.limit = b.limit;
                    cNext.amount = CtoBLeft;
                    cNext.limit = c.limit;
                    dfs(a,bNext,cNext);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    Bottle startA, startB,startC;
    startA.amount = 0;
    startB.amount = 0;
    cin>>startA.limit>>startB.limit>>startC.limit;
    startC.amount = startC.limit;

    memset(visited,false,sizeof(visited));
    dfs(startA,startB,startC);
    
    for(set<int>::iterator it = ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }
}
