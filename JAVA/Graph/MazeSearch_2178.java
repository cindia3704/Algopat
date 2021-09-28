package JAVA.Graph;

import java.util.*;

class Board {
    int y, x, countNum;

    public Board(int y, int x, int countNum) {
        this.y = y;
        this.x = x;
        this.countNum = countNum;
    }

    public Board() {

    }
}

public class MazeSearch_2178 {
    static final int dx[] = new int[] { 0, 1, 0, -1 };
    static final int dy[] = new int[] { -1, 0, 1, 0 };
    static char maze[][];
    static boolean visited[][];
    static int answer = 987654321;

    static void bfs(int y, int x, int height, int width) {
        Queue<Board> q = new LinkedList<>();
        Board start = new Board();
        start.y = y;
        start.x = x;
        start.countNum = 1;
        q.add(start);
        while (q.size() > 0) {
            int nowY = q.peek().y;
            int nowX = q.peek().x;
            int nowCount = q.peek().countNum;
            if (nowY == height - 1 && nowX == width - 1) {
                if (answer > nowCount) {
                    answer = nowCount;
                }
            }
            q.remove();
            for (int i = 0; i < 4; i++) {
                int nextY = nowY + dy[i];
                int nextX = nowX + dx[i];
                int nextCount = nowCount + 1;
                if (nextY < 0 || nextX < 0 || nextY >= height || nextX >= width) {
                    continue;
                }
                if (!visited[nextY][nextX] && maze[nextY][nextX] == '1') {
                    visited[nextY][nextX] = true;
                    Board next = new Board(nextY, nextX, nextCount);
                    q.add(next);
                }
            }
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int height = sc.nextInt();
        int width = sc.nextInt();

        visited = new boolean[height][width];
        maze = new char[height][width];
        for (int i = 0; i < height; i++) {
            String input = sc.next();
            for (int j = 0; j < width; j++) {
                maze[i][j] = input.charAt(j);
            }
        }
        for (int i = 0; i < height; i++) {
            Arrays.fill(visited[i], false);
        }
        bfs(0, 0, height, width);
        System.out.println(answer);
        sc.close();
    }
}
