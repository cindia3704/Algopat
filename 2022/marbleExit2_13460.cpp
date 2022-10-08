/*
    작성자: 김지수
    작성일: 2022/10/08
    백준 -- 구슬 탈출 2 (13460번)
*/

#include <iostream>
#include <cstring>
#define MAX 11 
using namespace std; 

const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

int height,width; 
bool found = false;
char board[MAX][MAX];
char temp[MAX][MAX];
int pick[MAX];

void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<temp[i][j]<<" ";
        }
        cout<<endl;
    }
}

int move(int dir){
    bool redExit = false;
    bool blueExit = false;

    if(dir == 0){
        for(int j=0;j<width;j++){
            for(int i=height-1;i>=0;i--){
                char now = temp[i][j];
                bool foundWay = false;
                if(now == 'R' || now=='B'){
                    int ny = i+1;
                    while(true){
                        if(ny<0 || ny>=height){
                            break;
                        }else{
                            if(temp[ny][j]=='.'){
                                foundWay = true;
                                ny++;
                            }else if(temp[ny][j]=='O'){
                                if(now == 'R'){
                                    redExit = true;
                                    temp[i][j] = '.';
                                }else{
                                    blueExit = true;
                                    temp[i][j] = '.';
                                }
                                foundWay = false;
                                break;
                            }else{
                                ny--;
                                break;
                            }
                        }
                    }
                    if(foundWay){
                        temp[i][j] = '.';
                        temp[ny][j] = now;
                    }
                }
            }
        }
    }else if(dir == 1){
        for(int j=0;j<width;j++){
            for(int i=0;i<height;i++){
                char now = temp[i][j];
                bool foundWay = false;
                if(now == 'R' || now=='B'){
                    int ny = i-1;
                    while(true){
                        if(ny<0 || ny>=height){
                            break;
                        }else{
                            if(temp[ny][j]=='.'){
                                foundWay = true;
                                ny--;
                            }else if(temp[ny][j]=='O'){
                                if(now == 'R'){
                                    redExit = true;
                                    temp[i][j] = '.';
                                }else{
                                    blueExit = true;
                                    temp[i][j] = '.';
                                }
                                foundWay = false;
                                break;
                            }else{
                                ny++;
                                break;
                            }
                        }
                    }
                    if(foundWay){
                        temp[i][j] = '.';
                        temp[ny][j] = now;
                    }
                }
            }
        }
    }else if(dir == 2){
        for(int j=0;j<height;j++){
            for(int i=width-1;i>=0;i--){
                char now = temp[j][i];
                bool foundWay = false;
                if(now == 'R' || now=='B'){
                    int nx = i+1;
                    while(true){
                        if(nx<0 || nx>=width){
                            break;
                        }else{
                            if(temp[j][nx]=='.'){
                                foundWay = true;
                                nx++;
                            }else if(temp[j][nx]=='O'){
                                if(now == 'R'){
                                    redExit = true;
                                    temp[j][i] = '.';
                                }else{
                                    blueExit = true;
                                    temp[j][i] = '.';
                                }
                                foundWay = false;
                                break;
                            }else{
                                nx--;
                                break;
                            }
                        }
                    }
                    if(foundWay){
                        temp[j][i] = '.';
                        temp[j][nx] = now;
                    }
                }
            }
        }
    }else if(dir == 3){
        for(int j=0;j<height;j++){
            for(int i=0;i<width;i++){
                char now = temp[j][i];
                bool foundWay = false;
                if(now == 'R' || now=='B'){
                    int nx = i-1;
                    while(true){
                        if(nx<0 || nx>=width){
                            break;
                        }else{
                            if(temp[j][nx]=='.'){
                                foundWay = true;
                                nx--;
                            }else if(temp[j][nx]=='O'){
                                if(now == 'R'){
                                    redExit = true;
                                    temp[j][i] = '.';
                                }else{
                                    blueExit = true;
                                    temp[j][i] = '.';
                                }
                                foundWay = false;
                                break;
                            }else{
                                nx++;
                                break;
                            }
                        }
                    }
                    if(foundWay){
                        temp[j][i] = '.';
                        temp[j][nx] = now;
                    }
                }
            }
        }
    }
    if(!redExit && !blueExit){
        return 0;
    }else if(redExit && !blueExit){
        return 1;
    }else{
        return 2;
    }
}

bool check(int turn){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            temp[i][j] = board[i][j];
        }
    }
    bool redExit = false;
    bool blueExit = false;
    for(int i=0;i<turn;i++){
        int dir = pick[i];
        int tempRet = move(dir); // 0 = nothing 1=only red 2=blue
        if(tempRet == 2){
            blueExit = true;
        }else{
            if(tempRet == 1){
                redExit = true;
            }
        }
    }
    if(redExit && !blueExit){
        return true;
    }else{
        return false;
    }
}

void makeComb(int pickCount,int targetCnt){
    if(!found){
        if(pickCount==targetCnt){
            if(check(pickCount)){
                found = true;
            }
            return;
        }
        for(int i=0;i<4;i++){
            pick[pickCount] = i;
            makeComb(pickCount+1,targetCnt);
        }
    }
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    
    cin>>height>>width;
    for(int i=0;i<height;i++){
        string l;
        cin>>l;
        for(int j=0;j<l.length();j++){
            board[i][j] = l[j];
        }
    }
 
    for(int i=1;i<=10;i++){
        makeComb(0,i);
        if(found){
            cout<<i;
            break;
        }
    }
    if(!found){
        cout<<-1;
    }
}