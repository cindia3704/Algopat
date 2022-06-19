/*
    작성자: 김지수
    작성일: 2022/06/19
    백준 -- 상범 빌딩 (6593번)
*/

#include <iostream> 
#include <queue>
#include <cstring> 
#define MAX 31
using namespace std; 

const int dx[6]={0,1,0,-1,0,0};
const int dy[6] ={-1,0,1,0,0,0};
const int dz[6]={0,0,0,0,-1,1}; 

char building[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
long long ans = 987654321;

struct POS{
    int lev,y,x; 
    long long count;
};

void bfs(int startL,int startY,int startX,int exitY,int exitX,int exitL,int level,int height,int width){
    // cout<<"START:"<<startL<<" "<<startY<<" "<<startX<<endl;
    // cout<<"EXIT:"<<exitL<<" "<<exitY<<" "<<exitX<<endl;

    queue<POS> q;     
    POS start; 
    start.lev = startL;
    start.y = startY;
    start.x = startX; 
    start.count = 0;
    q.push(start);
    visited[startL][startY][startX] = true;

    while(!q.empty()){
        int nowL = q.front().lev;
        int nowY = q.front().y;
        int nowX = q.front().x; 
        long long nowCount = q.front().count;
        //cout<<"NOW:"<<nowL<<"  "<<nowY<<"  "<<nowX<<"   count:"<<nowCount<<endl;
        if(nowL == exitL && nowY ==exitY && nowX == exitX){
            if(ans>nowCount){
                ans = nowCount;
            }
        }
        q.pop();
        for(int i=0;i<6;i++){
            int nextL = nowL +dz[i];
            int nextY = nowY + dy[i];
            int nextX = nowX +dx[i];
            //cout<<"NEXT i:"<<i<<" --  "<<nextL<<"  "<<nextY<<"  "<<nextX<<"   count:"<<nowCount<<endl;

            if(nextL <0 || nextL >=level || nextY <0 || nextY >=height || nextX <0 ||nextX >=width){
                continue;
            }
            else {
                if(!visited[nextL][nextY][nextX] && (building[nextL][nextY][nextX]=='.' || building[nextL][nextY][nextX]=='E')){
                    visited[nextL][nextY][nextX] = true;
                    POS next;
                    next.count = nowCount+1; 
                    next.lev = nextL;
                    next.y = nextY;
                    next.x = nextX; 
                    q.push(next);
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int level,height,width; 
    while(true){
        cin>>level>>height>>width;
        if((level ==0 && height == 0 && width == 0)){
            break;
        }
        memset(visited,false,sizeof(visited));

        int startY,startX,startL;
        int exitY,exitX,exitL; 
        for(int i=0;i<level;i++){
            for(int j=0;j<height;j++){
                string l; 
                cin>>l;
                for(int k=0;k<l.size();k++){
                    building[i][j][k] = l[k];
                    if(l[k] == 'S'){
                        startL = i;
                        startY = j;
                        startX = k;
                    }
                     if(l[k] == 'E'){
                        exitL = i;
                        exitY = j;
                        exitX = k;
                    }
                }
            }
        }
        bfs(startL,startY,startX,exitY,exitX,exitL,level,height,width);

        if(ans == 987654321){
            cout<<"Trapped!"<<'\n';
        }else{
            cout<<"Escaped in "<<ans<<" minute(s)."<<'\n';
        }
        ans =987654321;

    }
    
    
}