/*
    작성자: 김지수
    작성일: 2022/07/21
    백준 -- 마법사 상어와 파이어볼 (20056번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#include <deque>
#define MAX 51
using namespace std; 

const int dx[8]={0,1,1,1,0,-1,-1,-1};
const int dy[8]={-1,-1,0,1,1,1,0,-1};
const int dirEvenOrOdd[4] = {0,2,4,6};
const int dirDiff[4] = {1,3,5,7};
int boardSize, totalFireball, totalTurn;

struct FIREBALL{
    int y,x;
    int weight,speed,dir;
};

struct BLOCK{
    vector<FIREBALL> lists;
};

deque<FIREBALL> fireballList; 

int calcPos(int pos){
    int ans;
    if(pos<0){
        ans = (boardSize-(abs(pos)%boardSize))%boardSize;
    }else{
        ans=pos%boardSize;
    }
    return ans;
}

int calcWeightSum(){
    int sum=0;
    for(int i=0;i<fireballList.size();i++){
        sum+=fireballList[i].weight;
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>totalFireball>>totalTurn;
    for(int i=0;i<totalFireball;i++){
        FIREBALL now; 
        cin>>now.y>>now.x>>now.weight>>now.speed>>now.dir;
        now.y--;
        now.x--;
        fireballList.push_back(now);
    }

    while(totalTurn--){ 
        BLOCK board[MAX][MAX];
        //모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다
        while(!fireballList.empty()){
            FIREBALL now = fireballList.front();
            int nextY = now.y + dy[now.dir]*now.speed;
            int nextX = now.x+ dx[now.dir]*now.speed; 
            //행과 열은 1번부터 N번까지 번호가 매겨져 있고, 1번 행은 N번과 연결되어 있고, 1번 열은 N번 열과 연결되어 있다
            nextY = calcPos(nextY);
            nextX = calcPos(nextX);
            now.y = nextY;
            now.x = nextX;

            board[nextY][nextX].lists.push_back(now);
            fireballList.pop_front();
        }

        // 격자 돌면서 
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                int listSize = board[i][j].lists.size();
                // 해당 칸에 파이어볼 있는 경우 
                if(listSize>0){
                    // 파이어볼이 2개 이상인 경우 
                    if(listSize>=2){

                        int sumWeight = 0;
                        int sumSpeed =0;
                        bool isAllOdd = true;
                        bool isAllEven = true;

                        for(int k=0;k<listSize;k++){

                            FIREBALL n = board[i][j].lists[k];
                            sumWeight+=n.weight;
                            sumSpeed +=n.speed;
                            //해당 칸에 있는 파이어볼의 방향이 모두 홀 / 짝인지 확인 
                            if(n.dir%2==0){
                                isAllOdd = false;
                            }else{
                                isAllEven = false; 
                            }
                        }
                        //질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
                        int indiW = floor((float)sumWeight / 5.0);
                        //속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다
                        int indiS = floor((float)sumSpeed / (float)listSize);
                        // 질량이 0인 파이어볼은 소멸되어 없어진다.
                        if(indiW>0){
                            for(int num=0;num<4;num++){
                                FIREBALL next;
                                next.y = i;
                                next.x = j;
                                next.weight = indiW;
                                next.speed = indiS;
                                if(isAllEven || isAllOdd){
                                    next.dir = dirEvenOrOdd[num];
                                }else{
                                    next.dir = dirDiff[num];
                                }
                                fireballList.push_back(next);
                            }
                        }
                    }else{
                        // 파이어볼이 1개인 경우, 질량이 0이 아니면 fireballList에 넣어줌 
                        if(board[i][j].lists.at(0).weight>0){
                            fireballList.push_back(board[i][j].lists.at(0));
                        }
                    }
                }
                board[i][j].lists.clear();
            }
        }
    }
    //이동을 K번 명령한 후, 남아있는 파이어볼 질량의 합
    cout<<calcWeightSum();
}   