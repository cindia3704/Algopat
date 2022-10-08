/*
    작성자: 김지수
    작성일: 2022/10/08
    백준 -- 마법사 상어와 복제 (23290번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 1000001
using namespace std; 

const int dy[8]={0,-1,-1,-1,0,1,1,1};
const int dx[8]={-1,-1,0,1,1,1,0,-1};

const int sy[4]={-1,0,1,0};
const int sx[4]={0,-1,0,1};
int fishCnt,turnCnt;

struct Fish{
    int y,x;
    int dir; 
    bool alive;
};
vector<Fish> fishList;
vector<Fish> copyList;
vector<int> ways;
int wayFishCnt;

int smell[4][4];
void print(){
    for(int i=0;i<fishList.size();i++){
        if(fishList[i].alive){
            cout<<"FISH "<<fishList[i].y<<" , "<<fishList[i].x<<"  dir:"<<fishList[i].dir<<endl;
        }
    }
    cout<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<smell[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool OOB(int y,int x){
    if(y<0 || x<0 || y>=4 || x>=4){
        return true;
    }
    return false;
}

int countFish(){
    int cnt = 0;
    for(int i=0;i<fishList.size();i++){
        if(fishList[i].alive){
            cnt++;
        }
    }
    return cnt;
}

void copyFish(){
    copyList.clear();
    for(int i=0;i<fishList.size();i++){
        if(fishList[i].alive){
            copyList.push_back(fishList[i]);
        }
    }
}

void addCopyFish(){
    fishList.insert(fishList.end(),copyList.begin(),copyList.end());
}

int included(int y,int x){
    int ret =0;
    for(int i=0;i<fishList.size();i++){
        if(fishList[i].alive){
            if(fishList[i].y == y && fishList[i].x==x){
                ret++;
            }
        }
    }
    return ret;
}

void findWay(int sharkY,int sharkX){
    ways.clear();
    wayFishCnt=-1;
    bool visited[4][4];
    memset(visited,false,sizeof(visited));

    for(int i=0;i<4;i++){
        int nextY1 = sharkY + sy[i];
        int nextX1 = sharkX + sx[i];
        int tempCnt1=0;
        bool madeTrue1 = false;
        
        if(OOB(nextY1,nextX1)){
            continue;
        }
        else{
            if(!visited[nextY1][nextX1]){
                visited[nextY1][nextX1] = true;
                tempCnt1+=included(nextY1,nextX1);
                madeTrue1 = true;
            }
            for(int j=0;j<4;j++){
                int nextY2 = nextY1 + sy[j];
                int nextX2 = nextX1 + sx[j];
                int tempCnt2=0;
                bool madeTrue2 = false;
                if(OOB(nextY2,nextX2)){
                    continue;
                }
                else{
                    if(!visited[nextY2][nextX2]){
                        visited[nextY2][nextX2] = true;
                        tempCnt2+=included(nextY2,nextX2);
                        madeTrue2 = true;
                    }
                    for(int k=0;k<4;k++){
                        int nextY3 = nextY2 + sy[k];
                        int nextX3 = nextX2 + sx[k];
                        int tempCnt3=0;
                        bool madeTrue3 = false;
                        if(OOB(nextY3,nextX3)){
                            continue;
                        }else{
                            if(!visited[nextY3][nextX3]){
                                visited[nextY3][nextX3] = true;
                                tempCnt3+=included(nextY3,nextX3);
                                madeTrue3 = true;
                            }
                            if(wayFishCnt<tempCnt1+tempCnt2+tempCnt3){
                                wayFishCnt = tempCnt1+tempCnt2+tempCnt3;
                                ways.clear();  
                                ways.push_back(i);
                                ways.push_back(j);
                                ways.push_back(k);
                            }
                            if(madeTrue3){
                                visited[nextY3][nextX3] = false;
                            }
                        }
                    }
                    if(madeTrue2){
                        visited[nextY2][nextX2] = false;
                    }
                }
            }
            if(madeTrue1){
                visited[nextY1][nextX1] = false;
            }
        }
    }
    return;
    
}

pair<int,int> moveShark(int sharkY,int sharkX,int turn){
    int ny= sharkY;
    int nx = sharkX;
    for(int i=0;i<3;i++){
        int dir = ways[i];
        int nextY = ny+sy[dir];
        int nextX = nx+sx[dir];
        bool foundFish =false; 
        for(int idx=0;idx<fishList.size();idx++){
            if(fishList[idx].alive){
                if(nextY == fishList[idx].y && nextX == fishList[idx].x){
                    fishList[idx].alive = false; 
                    foundFish = true;
                }
            }
        }
        if(foundFish){
            smell[nextY][nextX] = turn;
        }
        ny = nextY;
        nx = nextX;
    }
    return make_pair(ny,nx);
}

int rotate(int dir){
    int ret = dir-1;
    if(ret<0){
        ret+=8;
    }
    return ret; 
}

void moveFish(int sharkY,int sharkX){
    for(int i=0;i<fishList.size();i++){
        Fish now = fishList[i];
        if(now.alive){
            int nextY,nextX;
            bool found = false;
            for(int k=0;k<8;k++){
                nextY = now.y+dy[now.dir];
                nextX = now.x+dx[now.dir];
                if(nextY<0 || nextX >=4||nextX<0||nextY>=4 || smell[nextY][nextX]>0 || (nextY==sharkY && nextX == sharkX)){
                    now.dir = rotate(now.dir);
                }else{
                    found = true;
                    break;
                }
            }
            if(found){
                fishList[i].y= nextY;
                fishList[i].x= nextX;
                fishList[i].dir = now.dir;
            }
        }
    }
}

void smellDisappear(int turn){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(smell[i][j]>0 && smell[i][j]==turn-2){
                smell[i][j] = 0;
            }
        }
    }
}

void startGame(int sharkY,int sharkX){
    for(int i=1;i<=turnCnt;i++){
        copyFish();
        moveFish(sharkY,sharkX);
        findWay(sharkY,sharkX);
        pair<int,int> pos =moveShark(sharkY,sharkX,i);
        sharkY = pos.first;
        sharkX = pos.second;
        smellDisappear(i);
        addCopyFish();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>fishCnt>>turnCnt;
    int sharkY,sharkX;
    for(int i=0;i<fishCnt;i++){
        Fish now;
        cin>>now.y>>now.x>>now.dir;
        now.x--;
        now.y--;
        now.dir--;
        now.alive = true;
        fishList.push_back(now);
    }
    cin>>sharkY>>sharkX;
    sharkY--;
    sharkX--;
    startGame(sharkY,sharkX);
    cout<<countFish();
}