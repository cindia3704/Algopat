package JAVA.DP;

import java.io.*;
import java.util.*;

public class IntTriangle_1932_BR {
    static int c[][];
    static int arr[][];

    static int dp(int y, int x, int height) {
        if (y == height - 1) {
            return arr[y][x];
        }
        if (c[y][x] != -1) {
            return c[y][x];
        } else {
            int temp1 = dp(y + 1, x, height) + arr[y][x];
            int temp2 = dp(y + 1, x + 1, height) + arr[y][x];
            if (temp1 > temp2) {
                c[y][x] = temp1;
            } else {
                c[y][x] = temp2;
            }
        }
        return c[y][x];
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        c = new int[n][n];
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(c[i], -1);
        }
        StringTokenizer s;
        for (int i = 0; i < n; i++) {
            s = new StringTokenizer(br.readLine());
            for (int j = 0; j < i + 1; j++) {
                arr[i][j] = Integer.parseInt(s.nextToken());
            }
        }

        System.out.println(dp(0, 0, n));
    }
}
