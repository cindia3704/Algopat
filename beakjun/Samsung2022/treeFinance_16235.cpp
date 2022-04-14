/*
	작성자: 김지수
	작성일: 2022/04/14
	백준 -- 나무 재테크
	문제:
*/

#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 11;
const int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

struct TREE {
	int y, x, age;
};

bool cmp(TREE& a, TREE& b) { return a.age < b.age; }

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int board[MAX][MAX];
	int add[MAX][MAX];
	int boardSize, treeNum, targetYear;
	queue<TREE> yearTree[2];
	queue<TREE> newChild;
	TREE initTree[122];
	cin >> boardSize >> treeNum >> targetYear;

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cin >> add[i][j];
			board[i][j] = 5;
		}
	}

	for (int i = 0; i < treeNum; i++) {
		TREE now;
		cin >> now.y >> now.x >> now.age;
		now.y--;
		now.x--;
		initTree[i] = now;
	}

	int idx = 0;
	int nextIdx = (idx + 1) % 2;

	sort(initTree, initTree + treeNum, cmp);
	for (int i = 0; i < treeNum; i++) {
		yearTree[0].push(initTree[i]);
	}

	while (targetYear--) {
		queue<TREE> reproducton;
		queue<TREE> dead;
		nextIdx = (idx + 1) % 2;
		// spring
		while (!newChild.empty()) {
			TREE now = newChild.front();
			newChild.pop();
			if (board[now.y][now.x] >= now.age) {
				board[now.y][now.x] -= now.age;
				now.age++;
				yearTree[nextIdx].push(now);
			}

			else {
				dead.push(now);
			}
		}
		while (!yearTree[idx].empty()) {
			TREE now = yearTree[idx].front();
			yearTree[idx].pop();

			if (board[now.y][now.x] >= now.age) {
				board[now.y][now.x] -= now.age;
				now.age++;
				yearTree[nextIdx].push(now);

				if (now.age % 5 == 0) {
					reproducton.push(now);
				}
			}
			else {
				dead.push(now);
			}
		}

		// summer
		while (!dead.empty()) {
			TREE now = dead.front();
			dead.pop();
			board[now.y][now.x] += (now.age / 2);
		}

		// fall
		while (!reproducton.empty()) {
			TREE now = reproducton.front();
			reproducton.pop();

			for (int i = 0; i < 8; i++) {
				TREE next;
				next.y = now.y + dy[i];
				next.x = now.x + dx[i];
				if (next.y < 0 || next.y >= boardSize || next.x < 0 ||
					next.x >= boardSize) {
					continue;
				}
				else {
					next.age = 1;
					newChild.push(next);
				}
			}
		}

		// winter
		for (int i = 0; i < boardSize; i++) {
			for (int j = 0; j < boardSize; j++) {
				board[i][j] += add[i][j];
			}
		}

		idx = (idx + 1) % 2;
	}
	cout << yearTree[idx].size() + newChild.size();
}