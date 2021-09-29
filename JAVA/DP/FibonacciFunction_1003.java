package JAVA.DP;

import java.util.*;

import java.io.*;

public class FibonacciFunction_1003 {
    static Integer cache[][] = new Integer[41][2];

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int tc = Integer.parseInt(st.nextToken());
        cache[0][0] = 1;
        cache[0][1] = 0;
        cache[1][0] = 0;
        cache[1][1] = 1;

        for (int i = 2; i <= 40; i++) {
            cache[i][0] = cache[i - 1][0] + cache[i - 2][0];
            cache[i][1] = cache[i - 1][1] + cache[i - 2][1];
        }
        while (tc-- > 0) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            System.out.println(cache[num][0] + " " + cache[num][1]);
        }
    }
}
