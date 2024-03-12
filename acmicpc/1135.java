import java.io.*;
import java.util.*;

class Main {

    static int N;
    static List<Integer> parent = new ArrayList<>();
    static List<Integer>[] directChildren;

    private static int call(int node) {
        int maxTime = 0;
        List<Integer> timeOfEachChild = new ArrayList<>();
        for (int child : directChildren[node]) {
            timeOfEachChild.add(call(child));
        }
        timeOfEachChild.sort(Comparator.reverseOrder());
        for (int t = 1; t <= timeOfEachChild.size(); t++) {
            maxTime = Math.max(maxTime, timeOfEachChild.get(t-1) + t);
        }
        return maxTime;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(scanner.readLine());

        final StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        for (int n = 0; n < N; n++) {
            parent.add(Integer.parseInt(tokenizer.nextToken()));
        }

        directChildren = new List[N];
        for (int n = 0; n < N; n++) {
            directChildren[n] = new ArrayList<>();
        }
        for (int n = 1; n < N; n++) {
            int par = parent.get(n);
            directChildren[par].add(n);
        }

        // System.out.println(parent);
        // System.out.println(Arrays.deepToString(directChildren));
        System.out.println(call(0));
        scanner.close();
    }
}