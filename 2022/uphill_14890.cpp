/*
    작성자: 김지수
    작성일: 2022/06/29
    백준 -- 경사로 (14890번)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#define MAX 101
using namespace std; 

int boardSize, l;
int board[MAX][MAX];

bool checkRoadRow(int row){
    stack<pair<int,bool> > s; 
    bool checkNext = false;
    int countNext = 0;
    int next = -1;
    for(int i=0;i<boardSize;i++){
        int now = board[row][i];
        if(checkNext){
            if(now == next){
                countNext++;
                s.push(make_pair(now,true));
                if(countNext == l){
                    checkNext = false;
                    countNext = 0;
                    next = -1;
                }
                continue;
            }else{
                return false;
            }
        }
        if(s.empty()){
            s.push(make_pair(now,false));
        }else{
            if(now == s.top().first){
                s.push(make_pair(now,false));
            }else if(now > s.top().first && (now - s.top().first == 1)){
                for(int i=0;i<l;i++){
                    if(s.empty()){
                        return false;
                    }else{
                        if(s.top().first == now-1 && s.top().second == false){
                            s.pop();
                        }else{
                            return false;
                        }
                    }
                }
                s.push(make_pair(now,false));
            }else if(now<s.top().first && s.top().first-now == 1){
                checkNext = true;
                countNext = 1; 
                next = now;
                s.push(make_pair(now,true));
                if(countNext == l){
                    checkNext = false;
                    countNext = 0;
                    next = -1;
                }
            }else{
                return false;
            }
        }
    }

    if(checkNext){
        return false;
    }else{
        return true;
    }
}

bool checkRoadCol(int col){
    stack<pair<int,bool> > s; 
    bool checkNext = false;
    int countNext = 0;
    int next = -1;
    for(int i=0;i<boardSize;i++){
        int now = board[i][col];
        if(checkNext){
            if(now == next){
                countNext++;
                s.push(make_pair(now,true));
                if(countNext == l){
                    checkNext = false;
                    countNext = 0;
                    next = -1;
                }
                continue;
            }else{
                return false;
            }
        }
        if(s.empty()){
            s.push(make_pair(now,false));
        }else{
            if(now == s.top().first){
                s.push(make_pair(now,false));
            }else if(now > s.top().first && (now - s.top().first == 1)){
                for(int i=0;i<l;i++){
                    if(s.empty()){
                        return false;
                    }else{
                        if(s.top().first == now-1 && s.top().second == false){
                            s.pop();
                        }else{
                            return false;
                        }
                    }
                }
                s.push(make_pair(now,false));
            }else if(now<s.top().first && s.top().first-now == 1){
                checkNext = true;
                countNext = 1; 
                next = now;
                s.push(make_pair(now,true));
                if(countNext == l){
                    checkNext = false;
                    countNext = 0;
                    next = -1;
                }
            }else{
                return false;
            }
        }
    }

    if(checkNext){
        return false;
    }else{
        return true;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>boardSize>>l;
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            cin>>board[i][j];
        }
    }

    int countRoad=0;
    for(int i=0;i<boardSize;i++){
        bool possible = checkRoadRow(i);
        if(possible){
            countRoad++;
        }
    }
    for(int i=0;i<boardSize;i++){
        bool possible = checkRoadCol(i);
        if(possible){
            countRoad++;
        }
    }

    cout<<countRoad;

}