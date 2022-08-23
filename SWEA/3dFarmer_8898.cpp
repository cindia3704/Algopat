/*
    작성자: 김지수
    작성일: 2022/08/23
    SWEA -- 3차원 농부 (8898번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
int cowCnt,horseCnt; 
vector<int> cowPos;

int findClostestCow(int target){
    int st= 0;
    int en = cowCnt-1; 
    int mid = (st+en)/2;
    if(target>cowPos[en]){
        return en;
    }
    if(target<cowPos[st]){
        return st; 
    }

    while(st<=en){
        mid = (st+en)/2;
        if(cowPos[mid] == target){
            return mid;
        }else{
            if(cowPos[mid]<target){
                st=mid+1;
            }else{
                en=mid-1; 
            }
        }
    }
    if(cowPos[mid]<target && mid+1<cowCnt && mid+1>=0){
        mid++;
    }
    return mid;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{   
        cowPos.clear();
        int minDist = 0x7fffffff;
        int minCnt = 0;

        cin>>cowCnt>>horseCnt;

        int cowX,horseX; 
        cin>>cowX>>horseX;
        int dx = abs(cowX-horseX);
        for(int i=0;i<cowCnt;i++){
            int x;
            cin>>x;
            cowPos.push_back(x);
        }
        sort(cowPos.begin(),cowPos.end());

        for(int i=0;i<horseCnt;i++){
            int horseY;
            cin>>horseY; 
            
            int cowIdx = findClostestCow(horseY);
                int cowY = cowPos[cowIdx];
                int dy = abs(horseY-cowY);
                int totalDist = dx+dy;
                if(minDist>totalDist){
                    minDist = totalDist;
                    minCnt = 1;
                }else if(minDist == totalDist){
                    minCnt++;
                }
                
                if(cowIdx>0 && cowIdx<cowCnt && cowPos[cowIdx]!=horseY){
                    int cowY2 = cowPos[cowIdx-1];
                    int dy2 = abs(horseY-cowY2);
                    int totalDist2 = dx+dy2; 
                    
                    if(minDist>totalDist2){
                        minDist = totalDist2;
                        minCnt = 1;
                    }else if(minDist == totalDist2){
                        minCnt++;
                    }
                }

        }
        cout<<"#"<<test_case<<" "<<minDist<<" "<<minCnt<<'\n';
	}
	return 0;
}