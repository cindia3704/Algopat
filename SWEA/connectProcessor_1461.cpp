/*
    작성자: 김지수
    작성일: 2022/07/27
    SWEA -- 프로세서 연결하기 (1461번)
*/

#include <iostream>
#include <cstring>
#include <vector> 
#define MAX 13

using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize;
int board[MAX][MAX];
vector<pair<int,int> > coreList; 
bool found = false;
int ans = 0x7fffffff;
bool usedCore[MAX];
int pickCore[MAX];
bool usedTurn[13][4];

int checkDir(int coreNum,int dir){
    int coreY = coreList[coreNum].first;
    int coreX = coreList[coreNum].second; 
    
    int edgeLength = 0;
    int nextY = coreY+dy[dir];
    int nextX = coreX+dx[dir];
    while(nextY>=0 && nextY<boardSize && nextX>=0 && nextX<boardSize){
        if(board[nextY][nextX]==0){
            edgeLength++;
            nextY+=dy[dir];
            nextX+=dx[dir];
        }else{
            return -1;
        }
    }
    return edgeLength;
}

void fillInEdge(int coreNum,int dir){
    int coreY = coreList[coreNum].first;
    int coreX = coreList[coreNum].second; 
    
    int edgeLength = 0;
    int nextY = coreY+dy[dir];
    int nextX = coreX+dx[dir];
    while(nextY>=0 && nextY<boardSize && nextX>=0 && nextX<boardSize){
        if(board[nextY][nextX]==0){
            board[nextY][nextX] = 2; 
            nextY+=dy[dir];
            nextX+=dx[dir];
        }
    }
    return ;
}

void takeOutEdge(int coreNum,int dir){
    int coreY = coreList[coreNum].first;
    int coreX = coreList[coreNum].second; 
    
    int edgeLength = 0;
    int nextY = coreY+dy[dir];
    int nextX = coreX+dx[dir];
    while(nextY>=0 && nextY<boardSize && nextX>=0 && nextX<boardSize){
        if(board[nextY][nextX]==2){
            board[nextY][nextX] = 0; 
            nextY+=dy[dir];
            nextX+=dx[dir];
        }
    }
    return ;
}


void pickTurn(int target, int start,int sumEdge){
    if(start == target){
        found = true;
        ans = min(ans,sumEdge);
        return;
    }

    int coreNum = pickCore[start];
    for(int dir = 0;dir <4;dir++){
        if(!usedTurn[coreNum][dir]){
            // 해당 코어를 해당 방향으로 넣을 수 있는지 확인 
            int temp = checkDir(coreNum,dir);
            if(temp==-1){
                continue;
            }else{
                // 넣을 수 있다면 넣고 
                usedTurn[coreNum][dir] = true;
                fillInEdge(coreNum,dir);
                pickTurn(target,start+1,sumEdge+temp);
                // 백트래킹으로 돌아오면 다시 간선 뺌 
                takeOutEdge(coreNum,dir);
                usedTurn[coreNum][dir] = false;
            }
            
        }
    }

}


void makeCombCore(int pickCount,int target, int start){
    if(pickCount == target){
        memset(usedTurn,false,sizeof(usedTurn));
        // 포함할 프로세서 보드에 나타내기 
        for(int i=0;i<target;i++){
            int coreNum = pickCore[i];
            board[coreList[coreNum].first][coreList[coreNum].second] = 1;
        }
        pickTurn(target,0,0);
        // 보드에서 이번에 포함했던 프로세서 빼기 
        for(int i=0;i<target;i++){
            int coreNum = pickCore[i];
            board[coreList[coreNum].first][coreList[coreNum].second] = 0;
        }
        return; 
    }
    // 가장자리에 있는 코어들을 제외한 코어들중 포함할 코어 선택 
    for(int i=start;i<coreList.size();i++){
        if(!usedCore[i]){
            usedCore[i] = true;
            pickCore[pickCount]= i;
            makeCombCore(pickCount+1,target,i);
            usedCore[i] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        memset(board,0,sizeof(board));
        found= false;
        ans = 0x7fffffff;
        coreList.clear();

        cin>>boardSize;
        int totalCoreCnt=0;
        for(int i=0;i<boardSize;i++){
            for(int j=0;j<boardSize;j++){
                cin>>board[i][j];
                // 가장자리에 있는 코어들은 놔두고, 아닌 코어들은 선택list에 넣은후 보드에서 빼기 
                if(board[i][j] == 1){
                    if(i!=0 && i!=boardSize-1 && j!=0 && j!=boardSize-1){
                        coreList.push_back(make_pair(i,j));
                        totalCoreCnt++;
                        board[i][j] = 0;
                    } 
                }
            }
        }

        // 가장자리가 아닌 코어들에대해 코어선택 
        for(int i=totalCoreCnt;i>=0;i--){
            memset(usedCore,false,sizeof(usedCore));

            // 코어많은 순으로 탐색해서 코어 많은 것중 답이 나왔다면 탐색 중지 
            if(!found){
                makeCombCore(0,i,0);
            }
        }

        if(!found){
            ans = -1;
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}