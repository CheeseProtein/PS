import java.io.*;
import java.util.*;

class Main {

    static final int INF = 987654321;
    static int N;
    static int K;
    static List<List<Integer>> checkpoints = new ArrayList<>();
    static List<Integer> partSum = new ArrayList<>();
    static int[][] dp;

    static int getDist(int here, int there) {
        if (there >= N) return INF;

        var herePoint = checkpoints.get(here);
        var therePoint = checkpoints.get(there);
        return Math.abs(herePoint.get(0) - therePoint.get(0)) + Math.abs(herePoint.get(1) - therePoint.get(1));
    }

    // 도착까지 남은 코스트 반환
    static int dfs(int here, int skipLeft) {
        if (here >= N - 1) {
            return 0;
        }
        if (skipLeft <= 0) {
            return partSum.get(N-1) - partSum.get(here);
        }
        if (dp[here][skipLeft] != -1) {
            return dp[here][skipLeft];
        }

        int[] costToNextN = new int[skipLeft + 1];
        for (int i = 0; i <= skipLeft; i++) {
            costToNextN[i] = getDist(here, here + 1 + i);
        }

        int[] costWhenSkippedN = new int[skipLeft + 1];
        int minCost = INF;
        for (int i = 0; i <= skipLeft; i++) {
            minCost = Math.min(minCost, costToNextN[i] + dfs(here + i + 1, skipLeft - i));
            costWhenSkippedN[i] = minCost;
        }

        dp[here][skipLeft] = minCost;
        // System.out.println(Arrays.toString(costWhenSkippedN));
        // System.out.printf("(%d, %d) -- %d\n", here, skipLeft, minCost);
        return dp[here][skipLeft];
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        N = Integer.parseInt(tokenizer.nextToken());
        K = Integer.parseInt(tokenizer.nextToken());
        partSum.add(0);
        for (int n = 0; n < N; n++) {
            tokenizer = new StringTokenizer(scanner.readLine());
            final int r = Integer.parseInt(tokenizer.nextToken());
            final int c = Integer.parseInt(tokenizer.nextToken());
            checkpoints.add(List.of(r, c));
            if (n != 0) {
                var prevPoint = checkpoints.get(n - 1);
                int dist = Math.abs(r - prevPoint.get(0)) + Math.abs(c - prevPoint.get(1));
                partSum.add(partSum.get(n - 1) + dist);
            }
        }

        dp = new int[N][K+1];
        for (int n = 0; n < N; n++) {
            Arrays.fill(dp[n], -1);
        }
        int result = dfs(0, K);
        System.out.println(result);
        scanner.close();
    }
}