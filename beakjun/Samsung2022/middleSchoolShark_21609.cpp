#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

#define BLACK -1
#define RAINBOW 0
#define EMPTY -2
using namespace std;
const int MAX = 21;
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

struct GROUP {
	vector<pair<int, int>> blocks;
	int sizeOfGroup;
	int groupY, groupX;
	int rainbowNum;
};

int board[MAX][MAX];
bool visited[MAX][MAX];
int colorNum, boardSize;
int answer = 0;
vector<GROUP> groups;

bool cmp(GROUP& a, GROUP& b) {
	if (a.sizeOfGroup == b.sizeOfGroup) {
		if (a.rainbowNum == b.rainbowNum) {
			if (a.groupY == b.groupY) {
				return a.groupX > b.groupX;
			}
			return a.groupY > b.groupY;
		}
		return a.rainbowNum > b.rainbowNum;
	}
	return a.sizeOfGroup > b.sizeOfGroup;
}

void rotate() {
	int temp[MAX][MAX];
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			temp[i][j] = board[j][boardSize - i - 1];
		}
	}
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			board[i][j] = temp[i][j];
		}
	}
}

void gravity() {
	for (int j = 0; j < boardSize; j++) {
		int idx = boardSize - 1;
		while (true) {
			if (idx <= 0) {
				break;
			}
			if (board[idx][j] != EMPTY) {
				idx--;
			}
			if (board[idx][j] == EMPTY) {
				int add = 1;
				while (true) {
					if (idx - add < 0 || board[idx - add][j] == BLACK) {
						break;
					}
					if (board[idx - add][j] == EMPTY) {
						add++;
					}
					else {
						board[idx][j] = board[idx - add][j];
						board[idx - add][j] = EMPTY;
						break;
					}
				}
				idx--;
			}
		}
	}

}

void bfs(int y, int x, int color) {
	GROUP now;
	now.groupX = x;
	now.groupY = y;
	now.rainbowNum = 0;

	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		pair<int, int> n = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = n.first + dy[i];
			int nextX = n.second + dx[i];
			if (nextY < 0 || nextX < 0 || nextY >= boardSize || nextX >= boardSize) {
				continue;
			}
			if ((board[nextY][nextX] == color || board[nextY][nextX] == RAINBOW) && !visited[nextY][nextX]) {
				if(board[nextY][nextX] == RAINBOW){
					now.rainbowNum += 1;
				}
				visited[nextY][nextX] = true; 
				q.push(make_pair(nextY, nextX));
				now.blocks.push_back(make_pair(nextY, nextX));
			}
		}
	}
	now.sizeOfGroup = now.blocks.size();
	if (now.sizeOfGroup >= 2&& (now.sizeOfGroup - now.rainbowNum >=1)) {
		groups.push_back(now);
		//cout << "Push size:" << now.sizeOfGroup << " rainbow:" << now.rainbowNum << " y,x:" << now.groupY << "," << now.groupX << endl;
		
	}
}

void clearMaxGroup() {
	for (int i = 0; i < groups[0].blocks.size(); i++) {
		int nowY = groups[0].blocks[i].first;
		int nowX = groups[0].blocks[i].second;
		board[nowY][nowX] = EMPTY;
	}
	answer += (groups[0].sizeOfGroup * groups[0].sizeOfGroup);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> boardSize >> colorNum;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cin >> board[i][j];
		}
	}

	while (true) {
		// 블록 색별로 그룹 구하기 
		for (int color = 1; color <= colorNum; color++) {
			// 무지개 블록 때문에 색별로 돌리면서 방문 false로 
			memset(visited, false, sizeof(visited));
			for (int i = 0; i <boardSize ; i++) {
				for (int j = 0; j <boardSize; j++) {
					if (board[i][j] == color && !visited[i][j]) {
						bfs(i, j, color);
					}
				}
			}
		}
		if (groups.size() == 0) {
			break;
		}
		//어떤 그룹을 제거할지 정함 
		sort(groups.begin(), groups.end(), cmp);
		clearMaxGroup();
		gravity();
		rotate();
		gravity();
		groups.clear();
	}

	cout << answer << endl;
}