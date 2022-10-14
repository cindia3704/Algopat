/*
    작성자: 김지수
    작성일: 2022/10/14
    코드트리 -- 격자 숫자 놀이 (22번)
*/

#include <iostream>
#include <deque>
#include <cstring> 
#include <algorithm>
#define MAX 101
using namespace std; 

int tarY,tarX,tarNum;
int height,width;
int board[MAX][MAX];
int cnt[MAX];

bool check(){
    if(height<tarY || width<tarX){
        return false;
    }
    if(board[tarY][tarX] == tarNum){
        return true;
    }else{
        return false;
    }
}

bool cmp(pair<int,int> &a, pair<int ,int > &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

void checkRow(){
    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp));
    int maxH =height;
    int maxW = 0;
    for(int i=0;i<height;i++){
        deque<pair<int,int> > freq;
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<width;j++){
            cnt[board[i][j]]++;
        }
        for(int j=0;j<width;j++){
            if(cnt[board[i][j]]>0 && board[i][j]>0){
                freq.push_back(make_pair(board[i][j],cnt[board[i][j]]));
                cnt[board[i][j]] =0;
            }
        }
        sort(freq.begin(),freq.end(),cmp);
        int freqSize = freq.size()*2;
        maxW = max(maxW,freqSize);
        int j=0;
        while(!freq.empty()){
            temp[i][j++] = freq.front().first;
            temp[i][j++] = freq.front().second;
            freq.pop_front();
            if(j>=100){
                break;
            }
        }
    }
    width = maxW;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            board[i][j] = temp[i][j];
        }
    }
}

void checkCol(){
    int temp[MAX][MAX];
    memset(temp,0,sizeof(temp));
    int maxH =0;
    int maxW = width;
    for(int i=0;i<width;i++){
        deque<pair<int,int> > freq;
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<height;j++){
            cnt[board[j][i]]++;
        }
        for(int j=0;j<width;j++){
            if(cnt[board[j][i]]>0 && board[j][i]>0){
                freq.push_back(make_pair(board[j][i],cnt[board[j][i]]));
                cnt[board[j][i]] =0;
            }
        }
        sort(freq.begin(),freq.end(),cmp);
        int freqSize = freq.size()*2;
        maxH = max(maxH,freqSize);
        int j=0;
        while(!freq.empty()){
            temp[j++][i] = freq.front().first;
            temp[j++][i] = freq.front().second;
            freq.pop_front();
            if(j>=100){
                break;
            }
        }
    }
    height = maxH;
    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            board[j][i] = temp[j][i];
        }
    }

}
void print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void startGame(){
    int stage=0;
    bool found = false; 
    found = check();
    while(stage<=100 && !found){
        stage++;
        if(height>=width){
            checkRow();
        }else{
            checkCol();
        }
        found = check();
        if(found){
            break;
        }
    }
    if(found){
        cout<<stage;
    }else{
        cout<<-1;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    height = 3;
    width = 3;
    cin>>tarY>>tarX>>tarNum;
    tarX--;
    tarY--;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            cin>>board[i][j];
        }
    }
    startGame();
}