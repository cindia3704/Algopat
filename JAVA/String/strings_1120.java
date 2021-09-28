package JAVA.String;

import java.util.*;

public class strings_1120 {
    static int getLeastDiff(String s1, String s2, int diffNum) {
        int index = 0;
        int ans = 987654321;
        while (index <= diffNum) {
            int temp = 0;
            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) != s2.charAt(i + index)) {
                    temp++;
                }
            }
            ans = (temp < ans) ? temp : ans;
            index++;
        }
        return ans;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String input1 = sc.next();
        String input2 = sc.next();
        int diff = input2.length() - input1.length();
        int answer = getLeastDiff(input1, input2, diff);
        System.out.println(answer);
        sc.close();
    }
}
