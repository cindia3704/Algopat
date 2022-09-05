/*
    작성자: 김지수
    작성일: 2022/09/05
    백준 -- 달력 (20207번)
*/

#include <iostream>
#include <algorithm>
#define MAX 366
using namespace std;

int schedCnt; 
int calendar[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>schedCnt;
    int minDay = 365;
    int maxDay = 0;
    for(int i=0;i<schedCnt;i++){
        int start,end;
        cin>>start>>end;
        minDay = min(start,minDay);
        maxDay = max(end,maxDay);
        for(int j=start;j<=end;j++){
            calendar[j]++;
        }
    }
    int sum = 0;
    int w = 0;
    int h = 0;
    for(int i=minDay;i<=maxDay;i++){
        if(calendar[i]!=0){
            w++;
            h = max(h,calendar[i]);
        }else{
            sum+=w*h;
            w=0;
            h=0;
        }
    }
    sum+=w*h;
    cout<<sum;
}