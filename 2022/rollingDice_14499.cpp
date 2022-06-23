/*
    작성자: 김지수
    작성일: 2022/06/23
    백준 -- 주사위 굴리기 (14499번)
*/

#include <iostream>
#include <cstring> 
#define DICE_SUM 5
#define MAX 21
using namespace std;

const int dx[4]={1,-1,0,0}; // 동서북남
const int dy[4]={0,0,-1,1};

int diceNums[6];
int uen[3] = {0,2,1};

int height,width; 
int board[MAX][MAX];

void turn(int dir){
    int up = uen[0];
    int east = uen[1];
    int north = uen[2];
    switch (dir)
    {
    case 1: // 동쪽 (EAST)
        // 동쪽에 있던게 밑으로 즉 서쪽에 있던게 위로 
        uen[0] = DICE_SUM - east;
        // 위에 있던게 동쪽으로 & 남북은 그대로 유지 
        uen[1] = up; 
        break;
    case 2: // 서쪽 (WEST)
        // 동쪽에 있는게 위로  
        uen[0] = east;
        // 위에 있던게 서쪽으로 & 즉 밑에 있던게 동쪽으로 
        uen[1] = DICE_SUM - up; 
        break;
     case 3: // 북쪽 (NORTH)
        // 북쪽에 있던게 밑으로, 즉 남쪽에 있던게 위로  
        uen[0] = DICE_SUM - north;
        // 위에 있던게 북쪽으로
        uen[2] = up; 
        break;
     case 4: // 남쪽 (SOUTH)
        // 북쪽에 있던게 위로  
        uen[0] = north;
        // 위에 있던게 남쪽으로, 즉 밑에 있던게 북쪽으로
        uen[2] = DICE_SUM - up; 
        break;
    default:
        break;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(diceNums,0,sizeof(diceNums));
    int sy,sx; 
    int commandNum;

    cin>>height>>width>>sy>>sx>>commandNum;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }

    while(commandNum-- ){
        int direction; 
        cin>>direction;

        int nextY = sy+dy[direction-1];
        int nextX = sx+dx[direction-1];

        // 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시
        if(nextY <0 || nextY >=height || nextX <0 || nextX >=width){
            continue;
        }
        
        // 해당 방향으로 굴리기 
        turn(direction);
        // 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사
        if(board[nextY][nextX] == 0){
            board[nextY][nextX] = diceNums[DICE_SUM - uen[0]];
        }
        // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
        else{
            diceNums[DICE_SUM-uen[0]] = board[nextY][nextX];
            board[nextY][nextX] = 0;
        }
        sy = nextY;
        sx = nextX;
        // 이동했을 때 마다 상단에 쓰여 있는 값 출력
        cout<<diceNums[uen[0]]<<'\n';
    }   
}