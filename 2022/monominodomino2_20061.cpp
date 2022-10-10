/*
    작성자: 김지수
    작성일: 2022/10/10
    백준 -- 모노미노도미노 2 (17779번)
*/

#include <iostream>
#include <cstring>
using namespace std; 
int score=0;
int insertCnt;
int green[6][4];
int blue[4][6];

void printGreen(){
    cout<<"\n===GREEN==="<<endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            cout<<green[i][j]<<" ";
        }
        cout<<endl;
    }
}

void printBlue(){
    cout<<"\n===Blue==="<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            cout<<blue[i][j]<<" ";
        }
        cout<<endl;
    }
}


void removeGreenBottom(int cnt){
    for(int i=5;i>5-cnt;i--){
        for(int j=0;j<4;j++){
            green[i][j] = 0;
        }
    }

    for(int i=5-cnt;i>=0;i--){
        for(int j=0;j<4;j++){
            green[i+cnt][j] = green[i][j];
            green[i][j] =0;
        }
    }
}

void removeBlueBottom(int cnt){
    for(int j=5;j>5-cnt;j--){
        for(int i=0;i<4;i++){
            blue[i][j] = 0;
        }
    }
    for(int i=5-cnt;i>=0;i--){
        for(int j=0;j<4;j++){
            blue[j][i+cnt] = blue[j][i];
            blue[j][i] = 0;
        }
    }
}

void insertToGreen(int type,int y,int x){
    if(type==1){
        int nextY;
        int ny=0;
        for(int i=0;i<6;i++){
            nextY = ny+1;
            if(nextY>=6){
                nextY--;
                break;
            }
            if(green[nextY][x]==0){
                ny=nextY;
            }else{
                nextY--;
                break;
            }
        }
        green[nextY][x] =1;
    }else if(type==3){
        int y1=0;
        int x1=x;
        int y2=y1+1;
        int x2=x; 
        int nextY1,nextY2;
        for(int i=0;i<6;i++){
            nextY1 = y1+1;
            nextY2 = y2+1;
            if(nextY1>=6 || nextY2>=6){
                nextY1--;
                nextY2--;
                break;
            }
            if(green[nextY1][x1]==0 && green[nextY2][x2]==0){
                y1=nextY1;
                y2=nextY2;
            }else{
                nextY1--;
                nextY2--;
                break;
            }
        }
        green[nextY1][x1] =1;
        green[nextY2][x2] =1;
    }else{
        int y1=0;
        int x1=x;
        int y2=0;
        int x2=x+1; 
        int nextY1,nextY2;
        for(int i=0;i<5;i++){
            nextY1 = y1+1;
            nextY2 = y2+1;
            if(nextY1>=6 || nextY2>=6){
                nextY1--;
                nextY2--;
                break;
            }
            if(green[nextY1][x1]==0 && green[nextY2][x2]==0){
                y1=nextY1;
                y2=nextY2;
            }else{
                nextY1--;
                nextY2--;
                break;
            }
        }
        green[nextY1][x1] =1;
        green[nextY2][x2] =1;
    }
}
void insertToBlue(int type,int y,int x){
    if(type==1){
        int nextX;
        int nx = 0;
        for(int i=0;i<6;i++){
            nextX = nx+1;
            if(nextX>=6){
                nextX--;
                break;
            }
            if(blue[y][nextX]==0){
                nx=nextX;
            }else{
                nextX--;
                break;
            }
        }

        blue[y][nextX] =1;
    }else if(type==3){
        int y1=y;
        int x1=0;
        int y2=y+1;
        int x2=0; 
        int nextX1,nextX2;
        for(int i=0;i<6;i++){
            nextX1 = x1+1;
            nextX2 = x2+1;
            if(nextX1>=6 || nextX2>=6){
                nextX1--;
                nextX2--;
                break;
            }
            if(blue[y1][nextX1]==0 && blue[y2][nextX2]==0){
                x1=nextX1;
                x2=nextX2;
            }else{
                nextX1--;
                nextX2--;
                break;
            }
        }
        blue[y1][nextX1] =1;
        blue[y2][nextX2] =1;
    }else{
        int y1=y;
        int x1=0;
        int y2=y;
        int x2=x1+1; 
        int nextX1,nextX2;
        for(int i=0;i<5;i++){
            nextX1 = x1+1;
            nextX2 = x2+1;
            if(nextX1>=6 || nextX2>=6){
                nextX1--;
                nextX2--;
                break;
            }
            if(blue[y1][nextX1]==0 && blue[y2][nextX2]==0){
                x1=nextX1;
                x2=nextX2;
            }else{
                nextX1--;
                nextX2--;
                break;
            }
        }
        blue[y1][nextX1] =1;
        blue[y2][nextX2] =1;
    }
}

void gravityGreen(int y){
    for(int i=y-1;i>=0;i--){
        for(int j=0;j<4;j++){
            green[i+1][j] = green[i][j];
        }
    }
}

void gravityBlue(int x){
    for(int j=x-1;j>=0;j--){
        for(int i=0;i<4;i++){
            blue[i][j+1] = blue[i][j];
        }
    }
}

void checkCol(){
    for(int i=5;i>=0;){
        bool found = true;
        for(int j=0;j<4;j++){
            if(green[i][j]==0){
                found = false;
            }
        }
        if(found){
            for(int j=0;j<4;j++){
                green[i][j] = 0;
            }
            score++;
            gravityGreen(i);
        }else{
            i--;
        }
    }
}

void checkRow(){
    for(int j=5;j>=0;){
        bool found = true;
        for(int i=0;i<4;i++){
            if(blue[i][j]==0){
                found = false;
            }
        }
        if(found){
            for(int i=0;i<4;i++){
                blue[i][j] = 0;
            }
            score++;
            gravityBlue(j);
        }else{
            j--;
        }
    }
}

void checkTwo(){
    int cnt = 0;
    for(int i=0;i<2;i++){
        bool found = false;
        for(int j=0;j<4;j++){
            if(green[i][j]!=0){
                found = true;
            }
        }
        if(found){
            cnt++;
        }
    }
    if(cnt>0){
        removeGreenBottom(cnt);
    }
}

void checkTwoBlue(){
    int cnt = 0;
    for(int j=0;j<2;j++){
        bool found = false;
        for(int i=0;i<4;i++){
            if(blue[i][j]!=0){
                found = true;
            }
        }
        if(found){
            cnt++;
        }
    }
    if(cnt>0){
        removeBlueBottom(cnt);
    }
}

void insert(int type,int y,int x){
    insertToGreen(type,y,x);
    checkCol();
    checkTwo();
    insertToBlue(type,y,x);
    checkRow();
    checkTwoBlue();
}

int countBlueBlock(){
    int sum = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<6;j++){
            sum+=blue[i][j];
        }
    }
    return sum;
}
int countGreenBlock(){
    int sum = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<4;j++){
            sum+=green[i][j];
        }
    }
    return sum;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cin>>insertCnt; 
    for(int i=0;i<insertCnt;i++){
        int t,y,x;
        cin>>t>>y>>x;
        insert(t,y,x);
    }
    cout<<score<<"\n";
    cout<<countBlueBlock()+countGreenBlock();
}