package JAVA.Implementation;

import java.util.*;

public class PostFixNotation_1935 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int operandNum = sc.nextInt();
        String postfixNotation = sc.next();

        Double operandValue[] = new Double[26];
        Stack<Double> s = new Stack<>();
        for (int i = 0; i < operandNum; i++) {
            operandValue[i] = sc.nextDouble();
        }
        for (int i = 0; i < postfixNotation.length(); i++) {
            char now = postfixNotation.charAt(i);
            if ((now - '0') >= ('A' - '0') && (now - '0') <= ('Z' - '0')) {
                Integer operandIndex = (now - '0') - ('A' - '0');
                s.push(operandValue[operandIndex]);
                operandIndex++;
            } else {
                Double a = s.peek();
                s.pop();
                Double b = s.peek();
                s.pop();
                Double result = 0.0D;
                switch (now) {
                    case '+':
                        result = b + a;
                        break;
                    case '-':
                        result = b - a;
                        break;
                    case '*':
                        result = b * a;
                        break;
                    case '/':
                        result = b / a;
                        break;
                }
                s.push(result);
            }
        }
        System.out.println(String.format("%.2f", s.peek()));
        sc.close();
    }
}
