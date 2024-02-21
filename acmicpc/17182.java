import java.io.*;
import java.util.*;

class Main {

    static final int INF = 987654321;

    static int N;
    static int K;
    static int[][] cost;
    static int resultCost = INF;

    private static void dfs(int toVisit, int costUsed, int here) {
        if (toVisit == 0) {
            resultCost = Math.min(costUsed, resultCost);
            return;
        }
        if (costUsed > resultCost) {
            return;
        }

        for (int there = 0; there < N; there++) {
            if (((1<<there) & toVisit) == 0) continue;
            int nextCost = cost[here][there];
            dfs(toVisit ^ (1<<there), costUsed + nextCost, there);
        }
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
        N = Integer.parseInt(tokenizer.nextToken());
        K = Integer.parseInt(tokenizer.nextToken());
        cost = new int[N][N];
        for (int r = 0; r < N; r++) {
            tokenizer = new StringTokenizer(scanner.readLine());
            for (int c = 0; c < N; c++) {
                cost[r][c] = Integer.parseInt(tokenizer.nextToken());
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cost[i][j] = Math.min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }

        dfs(((int)(Math.pow(2.0, N)) - 1) ^ (1<<K), 0, K);

        System.out.println(resultCost);
        scanner.close();
    }
}