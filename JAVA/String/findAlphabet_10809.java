package JAVA.String;

import java.util.*;

public class findAlphabet_10809 {
    public static void main(String args[]) {
        int firstIndex[] = new int[26];
        Arrays.fill(firstIndex, -1);
        Scanner sc = new Scanner(System.in);
        String word = sc.next();
        for (int i = 0; i < word.length(); i++) {
            // System.out.println(word.charAt(i) - '0');
            int index = word.charAt(i) - '0' - 49;
            if (firstIndex[index] == -1) {
                firstIndex[index] = i;
            }
        }
        for (int i : firstIndex) {
            System.out.print(i + " ");
        }
    }

}
