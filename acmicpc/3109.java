import java.io.*;
import java.util.*;

class Main {

    static boolean[][] visited;
    static char[][] board;
    static int R;
    static int C;
    static int result;

    static boolean dfs(int r, int c) {
        // System.out.printf("visit %d, %d\n", r, c);
        visited[r][c] = true;
        if (c == C-1) {
            result++;
            return true;
        }

        boolean ret = false;
        if (r > 0 && !visited[r-1][c+1] && board[r-1][c+1] == '.') {
            ret = dfs(r-1, c+1);
        }
        if (!ret && !visited[r][c+1] && board[r][c+1] == '.') {
            ret = dfs(r, c+1);
        }
        if (!ret && r < R-1 && !visited[r+1][c+1] && board[r+1][c+1] == '.') {
            ret = dfs(r+1, c+1);
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        R = Integer.parseInt(tokenizer.nextToken());
        C = Integer.parseInt(tokenizer.nextToken());
        visited = new boolean[R][C];
        board = new char[R][C];

        for (int r = 0; r < R; r++) {
            String line = scanner.readLine();
            for (int c = 0; c < C; c++) {
                board[r][c] = line.charAt(c);
            }
        }

        for (int r = 0; r < R; r++) {
            // System.out.printf("****FROM %d, %d****", r, 0);
            dfs(r, 0);
        }

        System.out.println(result);
        scanner.close();
    }
}