/*
    작성자: 김지수
    작성일: 2022/07/13
    백준 -- 사다리 조작 (15684번)
*/

#include <iostream>
#include <cstring> 
using namespace std; 
int width,ladderNum,height; 

int board[31][11];
bool foundAns = false;
int ans = -1; 

bool check(int y, int x){
    if(x==0){
        return (board[y][x+1]==0);
    }else{
        return ((board[y][x-1] == 0) && (board[y][x+1]==0));
    }
}

bool checkAns(){
    for(int i=1;i<=width;i++){
        int x=i;
        for(int j=1;j<=height;j++){
            if(board[j][x-1]){
                x--;
            }
            else if(board[j][x]){
                x++;
            }
    
        }
        if(i!=x){
            return false;
        }
    }
    return true;
}

void addLadder(int pickCount, int total,int y,int x){
    if(!foundAns){
        if(pickCount == total){
            bool temp = checkAns();
            if(temp == true){
                foundAns = true;
                ans = total;
            }
            return;
        }
        
        for(int i=y;i<=height;i++){
            for(int j=x;j<width;j++){
                if(board[i][j]==0 && check(i,j)){
                    board[i][j] = 1;
                    addLadder(pickCount+1,total,i,j);
                    board[i][j] = 0;
                }
            }
            x=0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>width>>ladderNum>>height;
    for(int i=0;i<ladderNum;i++){
        int y,x; 
        cin>>y>>x; 
        board[y][x] = 1; 
    }

    for(int i=0;i<=3;i++){
        addLadder(0,i,1,0);
        if(foundAns==true){
            break;
        }
    }
    cout<<ans; 

}