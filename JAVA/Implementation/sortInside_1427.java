package JAVA.Implementation;

import java.util.*;

public class sortInside_1427 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        String num = sc.next();
        for (int i = 0; i < num.length(); i++) {
            pq.add(num.charAt(i) - '0');
        }
        while (pq.size() > 0) {
            System.out.print((char) (pq.poll() + '0'));
        }
        sc.close();
    }

}
