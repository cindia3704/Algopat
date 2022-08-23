#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_NUMBER_OF_CANDIDATE 2
#define CMD_MAX_AREA 3

void init(int N, int mMap[20][20]);
int numberOfCandidate(int M, int mStructure[5]);
int maxArea(int M, int mStructure[5], int mSeaLevel);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static int mMap[20][20];
static int mStructure[5];

static bool run()
{
	int numQuery;
	int N, M, mSeaLevel;
	int userAns, ans;

	bool isCorrect = false;

	scanf("%d", &numQuery);

	for (int i = 0; i < numQuery; ++i)
	{
		int cmd;
		scanf("%d", &cmd);

		switch (cmd)
		{
		case CMD_INIT:
			scanf("%d", &N);
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					scanf("%d", &mMap[j][k]);
			init(N, mMap);
			isCorrect = true;
			break;
		case CMD_NUMBER_OF_CANDIDATE:
			scanf("%d", &M);
			for (int j = 0; j < M; j++)
				scanf("%d", &mStructure[j]);
			userAns = numberOfCandidate(M, mStructure);
			scanf("%d", &ans);
			if (userAns != ans)
			{
				printf("NUM CANDI WRONG!!! \n");
				for (int j = 0; j < M; j++)
					printf("%d", mStructure[j]);
				printf("\n");
				isCorrect = false;
			}
			break;
		case CMD_MAX_AREA:
			scanf("%d", &M);
			for (int j = 0; j < M; j++)
				scanf("%d", &mStructure[j]);
			scanf("%d", &mSeaLevel);
			userAns = maxArea(M, mStructure, mSeaLevel);
			scanf("%d", &ans);
			if (userAns != ans)
			{
				printf("MAX AREA WRONG!!! \n");
				for (int j = 0; j < M; j++)
					printf("%d", mStructure[j]);
				printf("\n");
				isCorrect = false;
			}
			break;
		default:
			isCorrect = false;
			break;
		}
	}
	return isCorrect;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		
		printf("#%d %d\n", tc, score);
	}

	return 0;
}

#include <cstring>
#include <iostream>
#define MAX_N 22
using namespace std; 

const int dx[4] = {0,1,0,-1};
const int dy[4] = {-1,0,1,0};

int boardSize;
int board[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int cache[50000];
int usedCache[50000];
int usedCacheCnt=0;

class Queue{
	int front,rear;
	pair<int,int> arr[MAX_N*MAX_N];
public: 
	pair<int,int> pop(){
		pair<int,int> ret = arr[front++];
		return ret; 
	}

	void push(int y,int x){
		arr[rear++] = make_pair(y,x);
	}

	void init(){
		front = 0;
		rear = 0;
	}

	bool isEmpty(){
		if(front == rear){
			return true;
		}
		return false;
	}
};
Queue q;

void init(int N, int mMap[20][20])
{
	//cout<<"\nINIT"<<endl;
	// for(int i=0;i<usedCacheCnt;i++){
	// 	cache[usedCache[i]] = 0;
	// }
	// usedCacheCnt = 0;
	memset(cache,0,sizeof(cache));
	memset(temp,0,sizeof(temp));

	boardSize = N;
	//cout<<"\nBOARD!!"<<endl;
	for(int i=1;i<=boardSize;i++){
		for(int j=1;j<=boardSize;j++){
			board[i][j] = mMap[i-1][j-1];
			temp[i][j] = board[i][j];
			//cout<<board[i][j]<<" ";
		}
		//cout<<endl;
	}

	for(int i=1;i<=boardSize;i++){
		for(int j=1;j<=boardSize;j++){
			int start = board[i][j];
			for(int dir = 0;dir<4;dir++){
				int nextY = i+dy[dir];
				int nextX = j+dx[dir];
				int num = 4; 
				//cout<<"i:"<<i<<" j:"<<j<<"  dir:"<<dir<<"  nextY:"<<nextY<<"  nextX:"<<nextX<<endl;
				for(int k=1;k<5;k++){
					if(nextY<1 || nextY>boardSize || nextX<1 || nextX>boardSize){
						break;
					}
					//cout<<"board NEXT:"<<board[nextY][nextX]<<endl;
					num=(num*10)+(board[nextY][nextX]-start+4);
					//cout<<"i:"<<i<<" j:"<<j<<"  k:"<<k<<"  num:"<<num<<endl;
					cache[num]++;
					//usedCache[usedCacheCnt++] = num;

					nextY+=dy[dir];
					nextX+=dx[dir];
				}
			}
		}
	}
}


int bfs(int y,int x,int sealevel){
	q.init();
	visited[y][x] = true; 
	q.push(y,x);
	int ans = 0;
	while(!q.isEmpty()){
		pair<int,int> now = q.pop();
		ans++;
		for(int i=0;i<4;i++){
			int nextY = now.first + dy[i];
			int nextX = now.second + dx[i];
			if(nextY>=0 && nextY<=boardSize+1 && nextX>=0 && nextX<=boardSize+1){
				if(!visited[nextY][nextX] && temp[nextY][nextX]<sealevel){
					q.push(nextY,nextX);
					visited[nextY][nextX] = true;
				}
			}
		}
	}
	return ans;
}

int findMaxArea(int sealevel){
	int covered = (boardSize+2) * (boardSize+2);
	for(int i=0;i<=boardSize+1;i++){
		for(int j=0;j<=boardSize+1;j++){
			if(!visited[i][j] && temp[i][j]<sealevel && (i==0 || j==0 || i==boardSize+1 || j==boardSize+1)){
				covered-=bfs(i,j,sealevel);
			}
		}
	}

	// for(int i=0;i<=boardSize+1;i++){
	// 	for(int j=0;j<=boardSize+1;j++){
	// 		if(!visited[i][j]){
	// 			covered++;
	// 		}
	// 	}
	// }
	return covered;
}

int numberOfCandidate(int M, int mStructure[5])
{
	//cout<<"\nNUM CANDI"<<endl;
	if(M==1){
	//	cout<<"ret :"<<boardSize*boardSize<<endl;
		return boardSize*boardSize;
	}
	int num=4;
	for(int i=1;i<M;i++){
		num=num*10 +(mStructure[0]-mStructure[i]+4);
	}
	int numReverse = 0;
	int tempNum = num;
	while(tempNum>0){
		numReverse*=10;
		numReverse+=tempNum%10;
		tempNum/=10;
	}
	//cout<<"numReverse: "<<numReverse<<" num:"<<num<<endl;
	if(numReverse == num){
		//cout<<"ret: "<<cache[num]/2<<endl;
		return cache[num]/2;
	}else{
		//cout<<"ret: "<<cache[num]<<endl;
		return cache[num];
	}
}

// void print(){
// 	for(int i=1;i<=boardSize;i++){
// 		for(int j=1;j<=boardSize;j++){
// 			cout<<board[i][j]<< " ";
// 		}
// 		cout<<endl;
// 	}
// }

int maxArea(int M, int mStructure[5], int mSeaLevel)
{	
	int ans = -1; 
	for(int i=1;i<=boardSize;i++){
		for(int j=1;j<=boardSize;j++){
			int start = board[i][j];
			int sumHeight = start+mStructure[0];
			for(int dir = 0; dir<4; dir++){
				int nextY = i+dy[dir];
				int nextX = j+dx[dir];

				bool found = true; 
				for(int m=1;m<M;m++){
					if(nextY<1 || nextY>boardSize || nextX <1 || nextX>boardSize){
						found = false;
						break;
					}
					if(board[nextY][nextX]+mStructure[m] != sumHeight){
						found = false;
						break;
					}
					nextY+=dy[dir];
					nextX+=dx[dir];
				}

				if(found){
					//cout<<"FOUND: "<<i<<"  "<<j<<"  dir:"<<dir<<endl;
					memset(visited,false,sizeof(visited));
					temp[i][j] = sumHeight;
					int ny = i+dy[dir];
					int nx = j+dx[dir];

					for(int m=1;m<M;m++){
						temp[ny][nx]=sumHeight;
						ny+=dy[dir];
						nx+=dx[dir];
					}
					// cout<<"\nprint bf"<<endl;
					// print();
					int tempAns = findMaxArea(mSeaLevel);
					ans = max(ans,tempAns);
					
					temp[i][j]= board[i][j];
					ny = i+dy[dir];
					nx = j+dx[dir];
					for(int m=1;m<M;m++){
						temp[ny][nx]=board[ny][nx];
						ny+=dy[dir];
						nx+=dx[dir];
					}
					// cout<<"\nprint af"<<endl;
					// print();
				}
			}
		}
	}
	//cout<<"ans: "<<ans<<endl;
	return ans;
}