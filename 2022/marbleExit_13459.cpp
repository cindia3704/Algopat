/*
    작성자: 김지수
    작성일: 2022/10/12
    백준 -- 구슬 탈출 (13459번)
*/
#include <iostream>
#include <cstring>
#define MAX 11
using namespace std; 

// W S E N
const int dy[4] = {0,1,0,-1};
const int dx[4] = {-1,0,1,0};

int height,width;
bool found = false; 
char board[MAX][MAX];
char tempArr[MAX][MAX];
int pick[10];

void print(){
    cout<<"\n====print==="<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool OOB(int y,int x){
    return (y<0 || y>=height || x<0 || x>=width);
}

//0 = nothing, 1 = red only, 2 =blue 
int turn(int dir){
    bool redExit = false;
    bool blueExit = false;
    // W 
    if(dir == 0){
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(board[i][j]=='B' || board[i][j]=='R'){
                    int ny = i;
                    int nx = j;
                    bool foundNext= false;
                    while(true){
                        int nextY = ny+dy[dir];
                        int nextX = nx+dx[dir];
                        if(OOB(nextY,nextX)){
                            break;
                        }
                        if(board[nextY][nextX] == '.'){
                            ny = nextY;
                            nx = nextX;
                            foundNext = true;
                        }else if(board[nextY][nextX] == 'O'){
                            if(board[i][j]=='B'){
                                blueExit = true;
                                board[i][j]='.';
                            }else{
                                redExit = true;
                                board[i][j]='.';
                            }
                            break;
                        }else{
                            break;
                        }
                    }
                    if(foundNext){
                        board[ny][nx] = board[i][j];
                        board[i][j] = '.';
                    }
                }
            }
        }
    }else if(dir == 1){ // S
        for(int i=height-1;i>=0;i--){
            for(int j=0;j<width;j++){
                if(board[i][j]=='B' || board[i][j]=='R'){
                    int ny = i;
                    int nx = j;
                    bool foundNext= false;
                    while(true){
                        int nextY = ny+dy[dir];
                        int nextX = nx+dx[dir];
                        if(OOB(nextY,nextX)){
                            break;
                        }
                        if(board[nextY][nextX] == '.'){
                            ny = nextY;
                            nx = nextX;
                            foundNext = true;
                        }else if(board[nextY][nextX] == 'O'){
                            if(board[i][j]=='B'){
                                blueExit = true;
                                board[i][j]='.';
                            }else{
                                redExit = true;
                                board[i][j]='.';
                            }
                            break;
                        }else{
                            break;
                        }
                    }
                    if(foundNext){
                        board[ny][nx] = board[i][j];
                        board[i][j] = '.';
                    }
                }
            }
        }
    }else if(dir == 2){ // E
        for(int i=0;i<height;i++){
            for(int j=width-1;j>=0;j--){
                if(board[i][j]=='B' || board[i][j]=='R'){
                    int ny = i;
                    int nx = j;
                    bool foundNext= false;
                    while(true){
                        int nextY = ny+dy[dir];
                        int nextX = nx+dx[dir];
                        if(OOB(nextY,nextX)){
                            break;
                        }
                        if(board[nextY][nextX] == '.'){
                            ny = nextY;
                            nx = nextX;
                            foundNext = true;
                        }else if(board[nextY][nextX] == 'O'){
                            if(board[i][j]=='B'){
                                blueExit = true;
                                board[i][j]='.';
                            }else{
                                redExit = true;
                                board[i][j]='.';
                            }
                            break;
                        }else{
                            break;
                        }
                    }
                    if(foundNext){
                        board[ny][nx] = board[i][j];
                        board[i][j] = '.';
                    }
                }
            }
        }
    }else { // N
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(board[i][j]=='B' || board[i][j]=='R'){
                    int ny = i;
                    int nx = j;
                    bool foundNext= false;
                    while(true){
                        int nextY = ny+dy[dir];
                        int nextX = nx+dx[dir];
                        if(OOB(nextY,nextX)){
                            break;
                        }
                        if(board[nextY][nextX] == '.'){
                            ny = nextY;
                            nx = nextX;
                            foundNext = true;
                        }else if(board[nextY][nextX] == 'O'){
                            if(board[i][j]=='B'){
                                blueExit = true;
                                board[i][j]='.';
                            }else{
                                redExit = true;
                                board[i][j]='.';
                            }
                            break;
                        }else{
                            break;
                        }
                    }
                    if(foundNext){
                        board[ny][nx] = board[i][j];
                        board[i][j] = '.';
                    }
                }
            }
        }
    }
    if(redExit==false && blueExit == false){
        return 0;
    }else if(blueExit == true){
        return 2;
    }else if(redExit==true && blueExit==false){
        return 1;
    }
}

void calc(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = tempArr[i][j];
        }
    }

    int temp;
    for(int i=0;i<10;i++){
        temp = turn(pick[i]);        
        if(temp==1){
            found = true;
            break;
        }else if(temp ==2){
            break;
        }
    }
}

void makeComb(int pickCount){
    if(!found){
        if(pickCount == 10){
            calc();
            return;
        }
        for(int i=0;i<4;i++){
            pick[pickCount] = i;
            makeComb(pickCount+1);
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
            tempArr[i][j] = l[j];
            board[i][j] = l[j];
        }
    }

    makeComb(0);
   
    cout<<found;
}