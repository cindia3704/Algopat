/*
    작성자: 김지수
    작성일: 2022/08/31
    SWEA -- 은기의 아주 큰 그림 (7091 번)
*/
#include <iostream>
using namespace std;

#define MAX 2005
#define ll unsigned long long 
#define MOD ((1<<30) - 1)

int H, W, N, M;

int dreamPic[MAX][MAX];
int teacherPic[MAX][MAX];
int teacherHash[MAX][MAX];
int temp[MAX][MAX];

ll calc(int num, int shift) {
    ll hash = 1;
    for(int i = 1; i < num; i++) {
        hash = (hash << shift) + hash;
    }
    return hash;
}

ll calculateHash(int* row, int num, int shift) {
    ll hash = 0;
    for(int i = 0; i < num; i++) {
        hash = (hash << shift) + hash + *row++;
    }
    return hash;
}

ll calcN(int prev, ll next, int add, int shift) {
    ll hash = prev - next;
    hash = (hash << shift) + hash + add;
    return hash;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
    int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> H >> W >> N >> M;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                char a;
                cin >> a;
                if(a == 'o') dreamPic[i][j] = 1;
                else dreamPic[i][j] = 0;
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                char a;
                cin >> a;
                if(a == 'o') teacherPic[i][j] = 1;
                else teacherPic[i][j] = 0;
            }
        }

        for(int i = 0; i < H; i++) {
            temp[0][i] = (int) (calculateHash(dreamPic[i], W, 4)&MOD);
        }
        int dreamHash = (int) (calculateHash(temp[0], H, 5)&MOD);

        int col = calc(W, 4);
        int row = calc(H, 5);
        int rowDiff = M-W+1;
        int colDiff = N-H+1;
        for(int i = 0; i < N; i++) {
            temp[0][i] = (int) (calculateHash(teacherPic[i], W, 4)&MOD);
            for(int j = 1; j < rowDiff; j++) {
                temp[j][i] = (int) (calcN(temp[j-1][i], teacherPic[i][j-1]* col, teacherPic[i][j+W-1], 4)&MOD);
            }
        }
        for(int i = 0; i < rowDiff; i++) {
            teacherHash[0][i] = (int) (calculateHash(temp[i], H, 5)&MOD);
            for(int j = 1; j < colDiff; j++) {
                teacherHash[j][i] = (int) (calcN(teacherHash[j-1][i], temp[i][j-1]* row, temp[i][j+H-1], 5)&MOD);
            }
        }

        int appearCnt = 0;
        for(int i = 0; i < colDiff; i++) {
            for(int j = 0; j < rowDiff; j++){
                if(teacherHash[i][j] == dreamHash) {
                    appearCnt++;
                }
            }
        }
        cout << '#' << test_case << ' ' << appearCnt << '\n';
    }
    return 0;
}