/*
    작성자: 김지수
    작성일: 2022/09/15
    백준 -- 스타트 택시 (19238번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 21
#define WALL -1
#define EMPTY -2
using namespace std; 

struct Block{
    int custIdx;
    int y, x;
    int distance; 
};

struct Cust{
    int sy,sx; 
    int ey,ex;
    bool done;
    int idx;
};

const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};

int boardSize,customerCnt; 
int taxiY,taxiX;
int fuelAmt;
bool canGo = true;
int ans;
int board[MAX][MAX];
bool visited[MAX][MAX];

vector<Cust> custList; 
vector<Block> nextCust;

void print(){
    cout<<"\n====BOARD"<<endl;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool cmp(Block &a, Block &b){
    if(a.distance == b.distance){
        if(a.y == b.y){
            return a.x<b.x;
        }
        return a.y<b.y;
    }
    return a.distance<b.distance;
}

void findDist(int y,int x){
    nextCust.clear();
    memset(visited,false,sizeof(visited));
    queue<pair<pair<int,int> , int> > q;
    q.push(make_pair(make_pair(y,x),0));
    visited[y][x] = true; 

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowDist = q.front().second;
        q.pop();

        if(board[now.first][now.second]>=0){
            Block newBlock;
            newBlock.y = now.first;
            newBlock.x = now.second;
            newBlock.distance = nowDist;
            newBlock.custIdx = board[now.first][now.second];
            nextCust.push_back(newBlock);
        }
            for(int i=0;i<4;i++){
                int nextY = now.first + dy[i];
                int nextX = now.second + dx[i];
                if(nextY < 0 || nextY >=boardSize || nextX <0 || nextX>=boardSize){
                    continue;
                }
                if(!visited[nextY][nextX] && board[nextY][nextX]!=WALL){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextY,nextX),nowDist+1));
                }
            }
        
    }
    sort(nextCust.begin(),nextCust.end(),cmp);
}

bool drive(Cust nowCustomer){
    memset(visited,false,sizeof(visited));
    queue<pair<pair<int,int> , int> > q;
    q.push(make_pair(make_pair(taxiY,taxiX),0));
    visited[taxiY][taxiX] = true; 

    while(!q.empty()){
        pair<int,int> now = q.front().first;
        int nowDist = q.front().second;
        q.pop();
        if(now.first == nowCustomer.ey && now.second == nowCustomer.ex){
            if(nowDist<=fuelAmt){
                fuelAmt-=nowDist;
                custList[nowCustomer.idx].done = true; 
                taxiY = now.first;
                taxiX = now.second;
                fuelAmt+=(nowDist*2);
                return true;
            }  
            return false;
        }else{
            for(int i=0;i<4;i++){
                int nextY = now.first + dy[i];
                int nextX = now.second + dx[i];
                if(nextY < 0 || nextY >=boardSize || nextX <0 || nextX>=boardSize){
                    continue;
                }
                if(!visited[nextY][nextX] && board[nextY][nextX]!=WALL){
                    visited[nextY][nextX] = true;
                    q.push(make_pair(make_pair(nextY,nextX),nowDist+1));
                }
            }
        }
    }
    return false;
}

void startGame(){
    for(int i=0;i<customerCnt;i++){
        findDist(taxiY,taxiX);
        if(nextCust.empty()){
            canGo = false;
            break;
        }else{
            Block nextCustomer = nextCust[0];
            if(nextCustomer.distance>fuelAmt){
                canGo = false;
                break;
            }else{
                taxiY = nextCustomer.y;
                taxiX = nextCustomer.x;
                fuelAmt-=nextCustomer.distance;
                board[nextCustomer.y][nextCustomer.x] = EMPTY;
                bool driveComplete = drive(custList[nextCustomer.custIdx]);
                if(!driveComplete){
                    canGo = false;
                    break;
                }
            }
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>boardSize>>customerCnt>>fuelAmt;
    
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            int num;
            cin>>num;
            if(num == 0){
                board[i][j] = EMPTY;
            }else{
                board[i][j] = WALL;
            }
        }
    }

    cin>>taxiY>>taxiX;
    taxiY--;
    taxiX--;
    for(int i=0;i<customerCnt;i++){
        Cust now; 
        cin>>now.sy>>now.sx>>now.ey>>now.ex;
        now.sy--;
        now.sx--;
        now.ey--;
        now.ex--;
        now.idx = i;
        board[now.sy][now.sx] = i;
        custList.push_back(now);
    }
    startGame();
    if(!canGo){
        ans = -1;
    }else{
        ans = fuelAmt;
    }
    cout<<ans;
}