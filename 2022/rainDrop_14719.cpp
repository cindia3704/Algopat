/*
    작성자: 김지수
    작성일: 2022/09/07
    백준 -- 빗물 (14719번)
*/

#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std; 
int heights[MAX];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w;
    cin>>h>>w;
    for(int i=0;i<w;i++){
        cin>>heights[i];
    }
    int sum = 0;

    for(int i=0;i<w;i++){
        int maxR = *max_element(heights,heights+i);
        int maxL = *max_element(heights+i,heights+w);
        int now = heights[i];
        if(min(maxR,maxL) - now>0){
            sum+=min(maxR,maxL) - now;
        }
    }
    cout<<sum;
}