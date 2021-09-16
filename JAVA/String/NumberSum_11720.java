package JAVA.String;

import java.util.Scanner;

class NumberSum_11720 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        String number = scanner.next();
        int sum = 0;
        scanner.close();

        for (int i = 0; i < length; i++) {
            sum += number.charAt(i) - '0';
        }

        System.out.println(sum);

    }

}