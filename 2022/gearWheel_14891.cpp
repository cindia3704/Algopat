/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 톱니바퀴 (14891번)
*/

#include <iostream>
#include <deque>
#include <cstring> 
#define N 0
#define S 1 
using namespace std; 
deque<int> wheels[4];
bool visited[4];

// 네 톱니바퀴의 점수의 합을 출력
int getScore(){
    int sum=0;
    for(int i=0;i<4;i++){
        if(wheels[i][0] == S){
            switch (i)
            {
                case 0:
                    sum+=1;
                    break;
                case 1:
                    sum+=2;
                    break;
                case 2:
                    sum+=4;
                break;
                case 3:
                    sum+=8;
                    break;
                default:
                    break;
            }
        }
    }
    return sum;
}

void turn(int wheelNum,int dir){
    if(dir == 1){
        int temp = wheels[wheelNum].back();
        wheels[wheelNum].pop_back();
        wheels[wheelNum].push_front(temp);
    }else if(dir ==-1){
        int temp= wheels[wheelNum].front();
        wheels[wheelNum].pop_front();
        wheels[wheelNum].push_back(temp);
    }
    return;
}

// dir: 0 - 회전 안함 , 1 - 시계방향 -1 = 반시계방향 
void turnWheel(int wheelNum,int dir){
    int left = wheels[wheelNum][6];
    int right = wheels[wheelNum][2];
    
    //톱니바퀴 A를 회전할 때, 그 옆에 있는 톱니바퀴 B와 서로 맞닿은 톱니의 극이 다르다면, B는 A가 회전한 방향과 반대방향으로 회전
    if(dir!=0){
        turn(wheelNum,dir);

        if(wheelNum-1>=0){
            int corresponding = wheels[wheelNum-1][2];
            if(!visited[wheelNum-1]){
                visited[wheelNum-1] = true;

                if(corresponding == left){
                    turnWheel(wheelNum-1,0);
                }else{
                    turnWheel(wheelNum-1,dir*-1);
                }
            }
        }

        if(wheelNum+1<4){
            int corresponding = wheels[wheelNum+1][6];
            if(!visited[wheelNum+1]){
                visited[wheelNum+1] = true;
                if(corresponding == right){
                    turnWheel(wheelNum+1,0);
                }else{
                    turnWheel(wheelNum+1,dir*-1);
                }
            }
        }
    }
    return;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<4;i++){
        string wheel;
        cin>>wheel;
        for(int j=0;j<wheel.size();j++){
            wheels[i].push_back(wheel[j]-'0');
        }
    }

    int totalTurn;
    cin>>totalTurn;
    
    while(totalTurn--){
        int wheelNum, dir; 
        cin>>wheelNum>>dir;
        memset(visited,false,sizeof(visited));
        visited[wheelNum-1] = true;

        turnWheel(wheelNum-1,dir);
    }

    cout<<getScore();

}