import java.io.*;
import java.util.*;

class Main {

    static List<Integer> num;
    static List<Character> op;
    static Map<List<Integer>, Integer> memoMax = new HashMap<>();
    static Map<List<Integer>, Integer> memoMin = new HashMap<>();

    static int getMin(int start, int end) {
        if (start == end) return num.get(start);
        if (memoMin.containsKey(List.of(start, end))) {
            return memoMin.get(List.of(start, end));
        }

        int res = Integer.MAX_VALUE;
        for (int i = start; i < end; i++) {
            char operator = op.get(i);
            switch (operator) {
                case '+': {
                    res = Math.min(res, getMin(start, i) + getMin(i+1, end));
                    break;
                }
                case '-': {
                    res = Math.min(res, getMin(start, i) - getMax(i+1, end));
                    break;
                }
                case '*': {
                    res = Math.min(res, getMax(start, i) * getMax(i+1, end));
                    res = Math.min(res, getMax(start, i) * getMin(i+1, end));
                    res = Math.min(res, getMin(start, i) * getMax(i+1, end));
                    res = Math.min(res, getMin(start, i) * getMin(i+1, end));
                    break;
                }
                default: {
                    res = Math.min(res, getMax(start, i) / getMax(i+1, end));
                    res = Math.min(res, getMax(start, i) / getMin(i+1, end));
                    res = Math.min(res, getMin(start, i) / getMax(i+1, end));
                    res = Math.min(res, getMin(start, i) / getMin(i+1, end));
                }
            }
        }

        memoMin.put(List.of(start, end), res);
        return res;
    }
    static int getMax(int start, int end) {
        if (start == end) return num.get(start);
        if (memoMax.containsKey(List.of(start, end))) {
            return memoMax.get(List.of(start, end));
        }

        int res = Integer.MIN_VALUE;
        for (int i = start; i < end; i++) {
            char operator = op.get(i);
            // System.out.printf("> %d in [%d, %d], op ", i, start, end);
            // System.out.println(operator);
            switch (operator) {
                case '+': {
                    res = Math.max(res, getMax(start, i) + getMax(i+1, end));
                    break;
                }
                case '-': {
                    res = Math.max(res, getMax(start, i) - getMin(i+1, end));
                    break;
                }
                case '*': {
                    res = Math.max(res, getMax(start, i) * getMax(i+1, end));
                    res = Math.max(res, getMax(start, i) * getMin(i+1, end));
                    res = Math.max(res, getMin(start, i) * getMax(i+1, end));
                    res = Math.max(res, getMin(start, i) * getMin(i+1, end));
                    break;
                }
                default: {
                    res = Math.max(res, getMax(start, i) / getMax(i+1, end));
                    res = Math.max(res, getMax(start, i) / getMin(i+1, end));
                    res = Math.max(res, getMin(start, i) / getMax(i+1, end));
                    res = Math.max(res, getMin(start, i) / getMin(i+1, end));
                }
            }
        }

        memoMax.put(List.of(start, end), res);
        // System.out.printf("[%d - %d] max: %d\n", start, end, res);
        return res;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(scanner.readLine());

        String line = scanner.readLine();
        num = new ArrayList<>();
        op = new ArrayList<>();
        for (int n = 0; n < N; n++) {
            if (n % 2 == 0) {
                num.add(line.charAt(n) - '0');
            } else {
                op.add(line.charAt(n));
            }
        }

        int res = getMax(0, num.size() - 1);
        System.out.println(res);

        scanner.close();
    }
}