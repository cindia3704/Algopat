/*
    작성자: 김지수
    작성일: 2022/07/18
    백준 -- 2차원 배열과 연산 (17140번)
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std; 
int r,c,k;
int board[MAX][MAX];
int ans = -1;   // 답 못찾으면 -1 
bool found = false;

void makeComb(int h,int w,int time){
    if(time > 101){ // 최대 100이니까, 101 넘어가면 그만 돌림 , ans는 업데이트 안함 
        found = true;
        return;
    }
    if(board[r-1][c-1] == k){   // 답찾으면 found 처리 & 답 업데이트 
        found = true;
        ans = time; 
        return;
    }

    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp));    // 모든 자리 모두 0으로 세팅 
    
    if(h>=w){   // 행의 개수 ≥ 열의 개수인 경우 R연산 
        vector<pair<int,int> > r[h];    // 각 행에 대해 pair로 <나온 횟수, 숫자>
        int freq[101];  // 숫자가 100 까지 가능 
        for(int i=0;i<h;i++){
            memset(freq,0,sizeof(freq));    // 각 행에 대해 숫자 나온 횟수 0으로 초기화 
            for(int j=0;j<w;j++){   
                if(board[i][j]>0){  // 숫자가 0보다 큰경우에만 횟수 ++ 
                    freq[board[i][j]]++;
                }
            }
            for(int k=0;k<w;k++){   // 횟수가 0보다 크면 
                if(freq[board[i][k]]>0){    // 각행에 횟수, 숫자로 넣어주고, 횟수 0으로 세팅 (같은 숫자 여러번 안넣기 위헤)
                    r[i].push_back(make_pair(freq[board[i][k]],board[i][k]));
                    freq[board[i][k]] = 0;
                }
            }
            sort(r[i].begin(),r[i].end());  // 횟수 적게 나온순, 숫자 작은 순으로 정렬
        }
        int tempW = 0;
        for(int i=0;i<h;i++){
            if(tempW<r[i].size()*2){    // 최대 열 업데이트 
                tempW = r[i].size()*2;
            }
            int idx = 0;
            for(int j=0;j<r[i].size();j++){ // temp 에 새로 넣기 
                temp[i][idx] = r[i][j].second;
                idx++;
                temp[i][idx] = r[i][j].first;
                idx++;
            }
        }

        for(int i=0;i<h;i++){   // 보드에 temp 복사
            for(int j=0;j<tempW;j++){
                board[i][j] = temp[i][j];
            }
        }
        makeComb(h,tempW,time+1);
    }
    if(h<w){    //행의 개수 < 열의 개수인 경우 C연산 
        vector<pair<int,int> > c[w]; 
        int freq[101];
        for(int i=0;i<w;i++){
            memset(freq,0,sizeof(freq));
            for(int j=0;j<h;j++){
                if(board[j][i]>0){
                    freq[board[j][i]]++;
                }
            }
            for(int k=0;k<h;k++){
                if(freq[board[k][i]]>0){
                    c[i].push_back(make_pair(freq[board[k][i]],board[k][i]));
                    freq[board[k][i]]=0;
                }
            }
            sort(c[i].begin(),c[i].end());
        }
        int tempH = 0;
        for(int i=0;i<w;i++){
            if(tempH<c[i].size()*2){
                tempH = c[i].size()*2;
            }
            int idx = 0;
            for(int j=0;j<c[i].size();j++){
                temp[idx][i] = c[i][j].second;
                idx++;
                temp[idx][i] = c[i][j].first;
                idx++;
            }
        }

        for(int i=0;i<tempH;i++){
            for(int j=0;j<w;j++){
                board[i][j] = temp[i][j];
            }
        }
        makeComb(tempH,w,time+1);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>r>>c>>k;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>board[i][j];
        }
    }
    makeComb(3,3,0);
    cout<<ans;
}