package JAVA.Implementation;

import java.util.*;
import java.io.*;

public class CuteRyan_15565 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        ArrayList<Integer> ryanIndex = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int now = Integer.parseInt(st.nextToken());
            if (now == 1) {
                ryanIndex.add(i);
            } else {
                continue;
            }
        }
        if (ryanIndex.size() < k) {
            System.out.println(-1);
            return;
        }
        int answer = Integer.MAX_VALUE;
        for (int i = 0; i <= ryanIndex.size() - k; i++) {
            int end = i;
            int count = 0;
            while (count < k && end < ryanIndex.size()) {
                count++;
                end++;
            }
            if (count == k) {
                int s = ryanIndex.get(i);
                int e = ryanIndex.get(end - 1);
                answer = Math.min(answer, ((e - s) + 1));
            }
        }
        System.out.println(answer);

    }
}
