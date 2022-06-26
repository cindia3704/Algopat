/*
    작성자: 김지수
    작성일: 2022/06/26
    백준 -- Gaaaaaaaaaarden (2910번)
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector> 
#include <deque>
#define MAX 51
#define FLOWER -2
using namespace std; 

// NESW
const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int height,width; 
int greenCount,redCount; 
int board[MAX][MAX];
vector<pair<int,int> > possiblePos; // 배양액을 뿌릴 수 있는 땅
bool chosenLand[MAX*MAX];
deque<pair<int,int> > selectedLand;
int selectedLandIdx[MAX*MAX];
int selectedGreenLandIdx[MAX*MAX];

bool chosenGreenLand[MAX*MAX];

struct BLOCK{
    int y,x;
    int time; 
    char RG; 
};

deque<BLOCK> selectedGreenLand;


int greenVisited[MAX][MAX];
int redVisited[MAX][MAX];

int ans = 0;

void bfs(){
    int flowerCount = 0;
    while(!selectedGreenLand.empty()){
        BLOCK now = selectedGreenLand.front();
        selectedGreenLand.pop_front();
        // 현재 보려는 위치에 꽃이 있으면 무시 
        if(greenVisited[now.y][now.x]==FLOWER || redVisited[now.y][now.x] == FLOWER){
            continue;
        }else{
            for(int i=0;i<4;i++){
                // 상하좌우 보면서
                int nextY = now.y + dy[i];
                int nextX = now.x + dx[i];
                if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
                    continue;
                }
                // 다음위치가 꽃이면 무시 
                if(greenVisited[nextY][nextX]==FLOWER || redVisited[nextY][nextX] == FLOWER){
                    continue;
                }
                // 초록 배양액일 경우 
                if(now.RG == 'G'){
                    // 다음위치에 초록이 안갔고, 호수가 아닐때 
                    if(greenVisited[nextY][nextX] == -1 && board[nextY][nextX]!=0){
                        // 빨간배양액이 해당 위치에 도달한 시간 & 초록시간이 같으면 꽃으로 업데이트 & 꽃개수 ++ 
                        if(redVisited[nextY][nextX] == now.time+1){
                            redVisited[nextY][nextX] = FLOWER;
                            greenVisited[nextY][nextX] = FLOWER; 
                            flowerCount++;
                        }
                        // 아니면 큐에 넣어주기 
                        else if(redVisited[nextY][nextX]==-1){
                            greenVisited[nextY][nextX] = now.time+1;
                            BLOCK b;
                            b.RG = now.RG;
                            b.time = now.time+1;
                            b.x = nextX; 
                            b.y = nextY; 
                            selectedGreenLand.push_back(b);
                        }
                    
                    } 
                }
                else{
                    if(redVisited[nextY][nextX] == -1 && board[nextY][nextX]!=0){
                        if(greenVisited[nextY][nextX] == now.time+1){
                            redVisited[nextY][nextX] = FLOWER;
                            greenVisited[nextY][nextX] = FLOWER; 
                            flowerCount++;
                        }
                        else if(greenVisited[nextY][nextX]==-1){
                            redVisited[nextY][nextX] = now.time+1;
                            BLOCK b;
                            b.RG = now.RG;
                            b.time = now.time+1;
                            b.x = nextX; 
                            b.y = nextY; 
                            selectedGreenLand.push_back(b);
                        }
                    }
                }
            }
        }
    }
    if(flowerCount > ans){
        ans = flowerCount;
    }
}

void chooseGreenLands(int pickCount, int start){
    // 초록 배양액 뿌릴 위치 다 구하면 위치들 다 큐에 넣기 
    if(pickCount == greenCount){
        memset(greenVisited,-1,sizeof(greenVisited));
        memset(redVisited,-1,sizeof(redVisited));
        selectedGreenLand.clear();
            int greenNum=0;
            int redNum = 0;
            // 초록에 포함 안되어있는 위치들은 빨강으로 넣기 
         for(int i=0;i<greenCount+redCount;i++){
             pair<int,int> now = possiblePos[selectedLandIdx[i]];
             bool found = false;
             for(int j=0;j<greenCount;j++){

                 pair<int,int> next = possiblePos[selectedGreenLandIdx[j]];

                 if(next == now){
                     BLOCK b; 
                     b.RG = 'G';
                     b.y=next.first;
                     b.x = next.second;
                     b.time = 0;
                    greenVisited[next.first][next.second] = 0;
                    selectedGreenLand.push_back(b);
                    found = true;
                    greenNum++;
                    break;
                 }
             }
            if(!found){
                BLOCK b; 
                b.RG = 'R';
                b.y=now.first;
                b.x = now.second;
                b.time = 0;
                selectedGreenLand.push_back(b);
                redVisited[now.first][now.second] = 0;
                redNum++;
            }
         }

         if(redNum == redCount && greenNum == greenCount){
            bfs();
         }
         return;
    }else if(start>=redCount+greenCount && pickCount<greenCount){
        return;
    }
    for(int i=start;i<greenCount+redCount;i++){
        // 여기서 chooseLand()에서 고른 땅들의 인덱스 중에서 골라야함 
        int idx = selectedLandIdx[i];
        if(!chosenGreenLand[idx]){
            chosenGreenLand[idx] = true;
            selectedGreenLandIdx[pickCount] = idx;
            chooseGreenLands(pickCount+1,i+1);
            chosenGreenLand[idx] = false;
        }
    }
}

void chooseLand(int pickCount, int start){
    // 배양액 뿌릴 위치 다 구하면 
    if(pickCount == greenCount+redCount){
        // 그 위치들 중 초록 배양약 뿌릴 위치 구하기 
        memset(chosenGreenLand,false,sizeof(chosenGreenLand));
        chooseGreenLands(0,0);
        return; 
    }

    for(int i=start;i<possiblePos.size();i++){
        if(!chosenLand[i]){
            chosenLand[i] = true;
            selectedLandIdx[pickCount] = i;
            chooseLand(pickCount+1,i+1);
            chosenLand[i] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>height>>width;
    cin>>greenCount>>redCount; 
    
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j]; 
            if(board[i][j] == 2){
                possiblePos.push_back(make_pair(i,j));
            }
        }
    }

    // 배양액 뿌릴수 있는 땅 중 빨 & 초 배양에 뿌릴 땅 고르기 
    memset(chosenLand,false,sizeof(chosenLand));
    chooseLand(0,0);

    cout<<ans;

}