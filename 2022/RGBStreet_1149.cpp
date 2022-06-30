/*
    작성자: 김지수
    작성일: 2022/06/30
    백준 -- RGB 거리 (1149번)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std; 

int RGBWeight[MAX][3];
int cache[MAX][3];

int calcRoadWeight(int n,int lastColor){
    int & ret = cache[n][lastColor];
    if(n<0){
        return 0;
    }
    if(ret!=-1){
        return ret; 
    }else{
        if(lastColor == 0){
            return ret = min(calcRoadWeight(n-1,1),calcRoadWeight(n-1,2))+RGBWeight[n-1][0];
        }
        if(lastColor == 1){
            return ret = min(calcRoadWeight(n-1,0),calcRoadWeight(n-1,2))+RGBWeight[n-1][1];
        }
        if(lastColor == 2){
            return ret = min(calcRoadWeight(n-1,1),calcRoadWeight(n-1,0))+RGBWeight[n-1][2];
        }
        return ret;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int houseNum;
    cin>>houseNum;
    
    for(int i=0;i<houseNum;i++){
        for(int j=0;j<3;j++){
            cin>>RGBWeight[i][j];
        }
    }
    memset(cache,-1,sizeof(cache));

    int lastR=calcRoadWeight(houseNum,0);
    int lastG=calcRoadWeight(houseNum,1);
    int lastB=calcRoadWeight(houseNum,2);
    
    cout<<min(min(lastR,lastG),lastB);
    
    
}