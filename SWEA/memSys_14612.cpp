/*
    작성자: 김지수
    작성일: 2022/08/31
    SWEA -- 메모리 시스템 (14612번)
*/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

 void init(int N);
 int allocate(int mSize);
 int release(int mAddr);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ALLOCATE 2
#define CMD_RELEASE 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n, addr, size;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				init(n);
				okay = true;
				break;
			case CMD_ALLOCATE:
				scanf("%d %d", &size, &ans);
				ret = allocate(size);
				if (ans != ret)
					okay = false;
				break;
			case CMD_RELEASE:
				scanf("%d %d", &addr, &ans);
				ret = release(addr);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 
int totalSize;
map<int,int> memoryUsed;


set<pair<int,int> > memoryPool;

void init(int N) {
    //cout<<"init:  n:"<<N<<endl;
    totalSize = N;
    memoryUsed.clear();
    memoryPool.clear();
    memoryPool.insert(make_pair(N,0));
	return;
}

int allocate(int mSize) {
    //cout<<"allocate!!"<<endl;
    set<pair<int,int> > ::iterator it = lower_bound(memoryPool.begin(),memoryPool.end(),make_pair(mSize,0));
    if(it == memoryPool.end()){
        //cout<<"ret: "<<-1<<endl;
        return -1; 
    }else{
        int newMemoryAddress = it->second;
        memoryUsed[newMemoryAddress] = mSize;
        if(it->first > mSize){
            memoryPool.insert(make_pair(it->first-mSize,it->second+mSize));
        }
        memoryPool.erase(it);
        //cout<<"ret: "<<newMemoryAddress<<endl;
        return newMemoryAddress;
    }
}

int release(int mAddr) {
    //cout<<"RELEASE!!  "<<mAddr<<endl;
   map<int,int> ::iterator it = memoryUsed.find(mAddr);
   if(it==memoryUsed.end()){
    //cout<<"ret: "<<-1<<endl;
    return -1;
   }

    int ans = it->second;
    int newSize = ans;
    int newStartIdx = mAddr;
    it = memoryUsed.erase(it);
    
    if(it!=memoryUsed.begin()){
        it--;
        int frontSize = mAddr-it->first-it->second;
        if(frontSize>0){
            set<pair<int,int> > ::iterator it2 = find(memoryPool.begin(),memoryPool.end(),make_pair(frontSize,mAddr-frontSize));
            if(it2!=memoryPool.end()){
                memoryPool.erase(it2);
            }
            newSize+=frontSize;
             newStartIdx -=frontSize;
        }
       // cout<<"*** 2  frontSize:"<<frontSize<<"  newSize:"<<newSize<<"  newStart:"<<newStartIdx<<endl;
         it++;
    }else if(mAddr>0 ){
        int frontSize = mAddr;
        if(frontSize>0){
            set<pair<int,int> > ::iterator it2 = find(memoryPool.begin(),memoryPool.end(),make_pair(frontSize,mAddr-frontSize));
            if(it2!=memoryPool.end()){
                memoryPool.erase(it2);
            }
            newSize+=frontSize;
            newStartIdx -=frontSize;
        }
        //cout<<"*** 1  frontSize:"<<frontSize<<"  newSize:"<<newSize<<"  newStart:"<<newStartIdx<<endl;
    }

    
    if(it!=memoryUsed.end()){
        int nextAddr = it->first;
        int behindSize = nextAddr - mAddr - ans; 
        if(behindSize>0){
            set<pair<int,int> > ::iterator it2 = find(memoryPool.begin(),memoryPool.end(),make_pair(behindSize,mAddr+ans));
            if(it2!=memoryPool.end()){
                memoryPool.erase(it2);
            }
            newSize+=behindSize;
        }
        //cout<<"*** 4  behindSize:"<<behindSize<<"  newSize:"<<newSize<<endl;
    }else if( ans+mAddr<totalSize){
        int behindSize = totalSize-ans-mAddr;
        if(behindSize>0){
            set<pair<int,int> > ::iterator it2 = find(memoryPool.begin(),memoryPool.end(),make_pair(behindSize,mAddr+ans));
            if(it2!=memoryPool.end()){
                memoryPool.erase(it2);
            }
            newSize+=behindSize;
        }
    }

    //cout<<"add size:"<<newSize<<" starT:"<<newStartIdx<<endl;
    memoryPool.insert(make_pair(newSize,newStartIdx));
    //cout<<"ans: "<<ans<<endl;
    return ans;
}