package JAVA.Implementation;

import java.util.*;

import java.io.*;

public class StringSet_14425 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        HashSet<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            set.add(st.nextToken());
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            if (set.contains(st.nextToken())) {
                count++;
            }
        }
        System.out.println(count);
    }
}
