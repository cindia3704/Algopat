/*
    작성자: 김지수
    작성일: 2022/07/29
    백준 -- 드래곤 커브 (15685번)
*/

#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#define MAX 101
using namespace std; 
//오 위 왼 아
const int dx[4]={1,0,-1,0};
const int dy[4] = {0,-1,0,1};

int map[MAX][MAX];
// 세대 정의 
struct Generation{
    int idx; 
    vector<int> dirs; 
};

// 세대별 방향 저장 (n번째 세대는 n-1~0세대의 방향들을 모두 90도 돌린것)
deque<Generation> dirList;

void calcDirs(int dir,int gen){
    Generation newGen;
    newGen.idx = gen;
    // 계산하는 세대가 0이면 dir그대로 넣기 
    if(gen==0){
        newGen.dirs.push_back(dir);
    }else{
        // 현재 세대의 방향들 => 이전세대를 뒤에서부터 보면서 90도 돌린것 
        for(int i=gen-1;i>=0;i--){
            Generation now = dirList[i];
            for(int k=now.dirs.size()-1;k>=0;k--){
                int newDir = (now.dirs[k]+1)%4; // 90도 돌리기 
                newGen.dirs.push_back(newDir);
            }
        }
    }
    dirList.push_back(newGen);
}

void fillBoard(int sy,int sx){
    int nowY = sy;
    int nowX = sx; 
    // 0세대부터 보면서 
    for(int i=0;i<dirList.size();i++){
        Generation now = dirList[i];
        // 차례대로 다음 위치 구하고 방문하는 위치 1 저장 
         for(int j=0;j<now.dirs.size();j++){
             int nowDir = now.dirs[j];
             map[nowY][nowX] = 1; 
             nowY=nowY+dy[nowDir];
             nowX = nowX+dx[nowDir];
             map[nowY][nowX] = 1;
             
         }
    }
}

int cntSqr(){
    int squares = 0;
    // 사각형에 속하는 꼭지점 모두 방문시 squares ++ 
    for(int i=0;i<MAX-1;i++){
        for(int j=0;j<MAX-1;j++){
            if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]){
                squares++;
            }
        }
    }
    return squares;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 드래곤커드 개수 입력 
    int curveCnt; 
    cin>>curveCnt;

    // 각 드래곤 커브 
    for(int i=0;i<curveCnt;i++){
        dirList.clear();
        int cy,cx,cdir,cgen;
        cin>>cx>>cy>>cdir>>cgen;
        for(int g=0;g<=cgen;g++){
            calcDirs(cdir,g);
        }
        fillBoard(cy,cx);
    }
    cout<<cntSqr();
}