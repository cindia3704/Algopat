/*
    작성자: 김지수
    작성일: 2021/09/16
    백준 -- OX 퀴즈 (8958번)
    문제:
    - 문제의 점수는 그 문제까지 연속된 O의 개수가 된다
*/
package JAVA.String;

import java.util.Scanner;

public class OXQuiz_8958 {
    public static int getResult(String s) {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'X') {
                count = 0;
            } else {
                count++;
                sum += count;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numQuiz = sc.nextInt();
        for (int i = 0; i < numQuiz; i++) {
            String quizResult = sc.next();
            System.out.println(getResult(quizResult));
        }
    }
}
