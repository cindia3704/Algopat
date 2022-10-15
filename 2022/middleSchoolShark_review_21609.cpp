/*
    작성자: 김지수
    작성일: 2022/10/15
    백준 -- 상어중학교 (21609번)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
#define MAX 20
#define BLACK -1
#define RAINBOW 0
#define EMPTY -2
using namespace std;

const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { 1,0,-1,0 };

struct GROUP {
	int repY, repX;
	int groupSize;
	int rainbowCnt;
};

int boardSize, colorCnt;
int board[MAX][MAX];
bool visited[MAX][MAX];
int score = 0;
vector<GROUP> groupList;

void print() {
	cout << "\n=====BOARD" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool cmp(GROUP& a, GROUP& b) {
	if (a.groupSize == b.groupSize) {
		if (a.rainbowCnt == b.rainbowCnt) {
			if (a.repY == b.repY) {
				return a.repX > b.repX;
			}
			return a.repY > b.repY;
		}
		return a.rainbowCnt > b.rainbowCnt;
	}
	return a.groupSize > b.groupSize;
}

bool OOB(int y, int x) {
	return (y < 0 || y >= boardSize || x < 0 || x >= boardSize);
}

void findG(int y, int x) {
	int tempVis[MAX][MAX];
	memset(tempVis, false, sizeof(tempVis));
	int groupCol = board[y][x];
	queue<pair<int, int> > q;
	GROUP g;
	g.repY = y;
	g.repX = x;
	g.groupSize = 0;
	g.rainbowCnt = 0;
	visited[y][x] = true;
	tempVis[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		g.groupSize++;
		if (board[now.first][now.second] == RAINBOW) {
			g.rainbowCnt++;
		}

		for (int i = 0; i < 4; i++) {
			int nextY = now.first + dy[i];
			int nextX = now.second + dx[i];
			if (OOB(nextY, nextX)|| board[nextY][nextX] == BLACK || board[nextY][nextX] == EMPTY) {
				continue;
			}
			if (!tempVis[nextY][nextX]){
				tempVis[nextY][nextX] = true;
				if (board[nextY][nextX] == RAINBOW) {
					q.push(make_pair(nextY, nextX));
				}
				if (board[nextY][nextX] == groupCol) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}
	if (g.groupSize >= 2) {
		groupList.push_back(g);
	}

}

bool calcGroup() {
	groupList.clear();
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (!visited[i][j] && board[i][j] > 0) {
				findG(i, j);
			}
		}
	}
	
	if (groupList.size() > 0) {
		sort(groupList.begin(), groupList.end(), cmp);
		return false;
	}
	return true;
}

void bfs(int y, int x) {
	int tempVis[MAX][MAX];
	memset(tempVis, false, sizeof(tempVis));
	int groupCol = board[y][x];
	queue<pair<int, int> > q;
	tempVis[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		board[now.first][now.second] = EMPTY;

		for (int i = 0; i < 4; i++) {
			int nextY = now.first + dy[i];
			int nextX = now.second + dx[i];
			if (OOB(nextY, nextX) || board[nextY][nextX] == BLACK || board[nextY][nextX] == EMPTY) {
				continue;
			}
			if (!tempVis[nextY][nextX]) {
				tempVis[nextY][nextX] = true;
				if (board[nextY][nextX] == RAINBOW) {
					q.push(make_pair(nextY, nextX));
				}
				if (board[nextY][nextX] == groupCol) {
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}

void removeMaxGroup() {
	GROUP target = groupList[0];
	bfs(target.repY, target.repX);
	int addSc = pow(target.groupSize,2);
	score += addSc;
}

void gravity() {
	for (int i = boardSize - 1; i >= 0; i--) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] >=0) {
				int ny = i;
				int nx = j;
				bool foundWay = false;
				while (true) {
					int nextY = ny + 1;
					int nextX = nx;
					if (OOB(nextY, nextX)) {
						break;
					}
					if (board[nextY][nextX] != EMPTY)  {
						break;
					}
					else {
						foundWay = true;
						ny = nextY;
						nx = nextX;
					}
				}
				if (foundWay) {
					board[ny][nx] = board[i][j];
					board[i][j] = EMPTY;
				}
			}
		}
	}
}

void turn() {
	int tempArr[MAX][MAX];
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			tempArr[i][j] = board[j][boardSize - 1 - i];
		}
	}
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			board[i][j] = tempArr[i][j];
		}
	}
}

void startGame() {
	bool found = false;
	while (!found) {
		found = calcGroup();
		if (found) {
			break;
		}
		removeMaxGroup();
		gravity();
		turn();
		gravity();
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> boardSize >> colorCnt;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cin >> board[i][j];
		}
	}

	startGame();
	cout << score;
}