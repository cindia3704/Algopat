/*
    작성자: 김지수
    작성일: 2022/08/23
    SWEA -- 광고 시간 정하기 (9999번)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int l,n;
struct PeekTime{
    int start,end; 
    int nowSum;
    int sumTilnow;
};
vector<PeekTime> peekList; 

bool cmp(PeekTime &a, PeekTime &b){
    if(a.start == b.start){
        return a.end < b.end;
    }
    return a.start<b.start;
}

int findIdx(int st,int en,int tar){
    while(true){
        int mid = (st+en)/2;
        if(st>en){
            return en;
        }
        if(peekList[mid].start<=tar && peekList[mid].end>=tar){
            return mid;
        }else{
            if(peekList[mid].start>tar){
                en = mid-1;
            }else{
                st=mid+1;
            }
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
        peekList.clear();
        cin>>l>>n;
        int sumTotal = 0;
        for(int i=0;i<n;i++){
            PeekTime p;
            cin>>p.start>>p.end;
            p.nowSum = (p.end-p.start);
            sumTotal+=(p.end-p.start);
            p.sumTilnow = sumTotal;
            peekList.push_back(p);
        }

        int maxAdTime = 0;
        for(int i=0;i<n;i++){
            int startTime = peekList[i].start;
            int endTime = startTime+l;
            int targetIdx = findIdx(0,n-1,endTime);
            int sumTimeNow = peekList[targetIdx].sumTilnow - peekList[i].sumTilnow+peekList[i].nowSum;
           
            if(endTime<peekList[targetIdx].end){
                sumTimeNow-=(peekList[targetIdx].end - endTime);
            }
            maxAdTime = max(maxAdTime,sumTimeNow); 
        }
        cout<<"#"<<test_case<<" "<<maxAdTime<<'\n';
	}
	return 0;
}