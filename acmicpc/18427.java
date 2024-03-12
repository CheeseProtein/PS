import java.io.*;
import java.util.*;

class Main {

    static int N;
    static int M;
    static int H;
    static List<List<Integer>> blocks = new ArrayList<>();

    static Map<Integer, Integer> getPossibleSum(int student) {
        Map<Integer, Integer> sum = new HashMap<>();
        if (student == N-1) {
            for (int i : blocks.get(N-1)) {
                sum.put(i, 1);
            }
            return sum;
        }

        Map<Integer, Integer> sumAfterMe = getPossibleSum(student + 1);
        for (var i : sumAfterMe.entrySet()) {
            int entry = i.getKey();
            int numberOfEntry = i.getValue();
            for (int myBlock : blocks.get(student)) {
                int nextEntry = myBlock + entry;
                int nextNumber = sum.getOrDefault(nextEntry, 0) + numberOfEntry;
                sum.put(nextEntry, nextNumber % 10007);
            }
        }
        // System.out.printf("student %d: ", student);
        // System.out.println(sum);
        return sum;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        N = Integer.parseInt(tokenizer.nextToken());
        M = Integer.parseInt(tokenizer.nextToken());
        H = Integer.parseInt(tokenizer.nextToken());
        for (int n = 0; n < N; n++) {
            List<Integer> myBlocks = new ArrayList<>(0);
            tokenizer = new StringTokenizer(scanner.readLine());
            while (tokenizer.hasMoreTokens()) {
                int block = Integer.parseInt(tokenizer.nextToken());
                myBlocks.add(block);
            }
            myBlocks.add(0);
            blocks.add(myBlocks);
        }

        // System.out.println(blocks);
        // System.out.println(getPossibleSum(0));
        Integer answer = getPossibleSum(0).get(H);
        System.out.println(answer != null ? answer : 0);

        scanner.close();
    }
}