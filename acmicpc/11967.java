import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        final int N = Integer.parseInt(tokenizer.nextToken());
        final int M = Integer.parseInt(tokenizer.nextToken());
        List<List<Integer>>[][] switches = new ArrayList[N][N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                switches[r][c] = new ArrayList<>();
            }
        }
        for (int m = 0; m < M; m++) {
            tokenizer = new StringTokenizer(scanner.readLine());
            int x = Integer.parseInt(tokenizer.nextToken()) - 1;
            int y = Integer.parseInt(tokenizer.nextToken()) - 1;
            int a = Integer.parseInt(tokenizer.nextToken()) - 1;
            int b = Integer.parseInt(tokenizer.nextToken()) - 1;
            if (x < 0 || x >= N || y < 0 || y >= N ||
                    a < 0 || a >= N || b < 0 || b >= N) {
                continue;
            }
            switches[x][y].add(List.of(a, b));
        }

        int brightRoomsCount = 0;
        boolean[][] visited = new boolean[N][N];
        visited[0][0] = true;
        Set<List<Integer>> brightButNotVisited = new HashSet<>();
        Deque<List<Integer>> q = new ArrayDeque<>();
        q.add(List.of(0, 0));

        final int[] dr = {-1, 1, 0, 0};
        final int[] dc = {0, 0, -1, 1};

        while (!q.isEmpty()) {
        //for (int ii = 0; ii < 1; ii++) {
            var here = q.poll();
            int hereR = here.get(0);
            int hereC = here.get(1);
            brightRoomsCount++;
            // System.out.printf("visit %d %d\n", hereR, hereC);

            for (var i : switches[hereR][hereC]) {
                int rr = i.get(0);
                int cc = i.get(1);
                if (visited[rr][cc]) continue;
                brightButNotVisited.add(i);
            }

            // System.out.println(brightButNotVisited);

            var iter = brightButNotVisited.iterator();
            while (iter.hasNext()) {
                var there = iter.next();
                int thereR = there.get(0);
                int thereC = there.get(1);
                for (int k = 0; k < 4; k++) {
                    int rr = thereR + dr[k];
                    int cc = thereC + dc[k];
                    if (rr < 0 || rr >= N || cc < 0 || cc >= N || !visited[rr][cc]) continue;
                    q.add(List.of(thereR, thereC));
                    visited[thereR][thereC] = true;
                    iter.remove();
                    break;
                }
            }

            // System.out.println(q);
            // System.out.println(brightButNotVisited);
        }



        // System.out.println(Arrays.deepToString(switches));
        // System.out.println(visited);
        System.out.println(brightRoomsCount + brightButNotVisited.size());

        scanner.close();
    }
}