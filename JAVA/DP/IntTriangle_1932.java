package JAVA.DP;

import java.util.*;

public class IntTriangle_1932 {
    static ArrayList<Integer>[] tree;
    static int cache[][];
    static int ans = -1;

    static int dp(int y, int x, int height) {
        if (y == height - 1) {
            return tree[y].get(x);
        }
        if (cache[y][x] != -1) {
            return cache[y][x];
        } else {
            int temp1 = dp(y + 1, x, height) + tree[y].get(x);
            int temp2 = dp(y + 1, x + 1, height) + tree[y].get(x);
            if (temp1 > temp2) {
                cache[y][x] = temp1;
            } else {
                cache[y][x] = temp2;
            }
        }
        return cache[y][x];
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int height = sc.nextInt();
        cache = new int[height][height];
        for (int i = 0; i < height; i++) {
            Arrays.fill(cache[i], -1);
        }
        tree = new ArrayList[height];
        for (int i = 0; i < height; i++) {
            tree[i] = new ArrayList<Integer>();
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < i + 1; j++) {
                int num = sc.nextInt();
                tree[i].add(num);
            }
        }

        System.out.println(dp(0, 0, height));
        sc.close();
    }

}
