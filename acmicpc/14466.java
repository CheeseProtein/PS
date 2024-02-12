import java.io.*;
import java.util.*;

class Main {
    
    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
        final int N = Integer.parseInt(tokenizer.nextToken());
        final int K = Integer.parseInt(tokenizer.nextToken());
        final int R = Integer.parseInt(tokenizer.nextToken());

        boolean[][][] containsRoad = new boolean[N][N][4];
        for (int r = 0; r < R; r++) {
            tokenizer = new StringTokenizer(scanner.readLine(), " ");
            int r1 = Integer.parseInt(tokenizer.nextToken()) - 1;
            int c1 = Integer.parseInt(tokenizer.nextToken()) - 1 ;
            int r2 = Integer.parseInt(tokenizer.nextToken()) - 1;
            int c2 = Integer.parseInt(tokenizer.nextToken()) - 1;
            if (r1 - 1 == r2) {  // up
                containsRoad[r1][c1][0] = true;
                containsRoad[r2][c2][1] = true;
            } else if (r1 + 1 == r2) {
                containsRoad[r1][c1][1] = true;
                containsRoad[r2][c2][0] = true;
            } else if (c1 - 1 == c2) {
                containsRoad[r1][c1][2] = true;
                containsRoad[r2][c2][3] = true;
            } else {
                containsRoad[r1][c1][3] = true;
                containsRoad[r2][c2][2] = true;
            }
        }

        // System.out.println(Arrays.deepToString(containsRoad));

        List<List<Integer>> cows = new ArrayList<>();
        Map<List<Integer>, Integer> cowMap = new HashMap<>();
        for (int k = 0; k < K; k++) {
            tokenizer = new StringTokenizer(scanner.readLine(), " ");
            int r = Integer.parseInt(tokenizer.nextToken()) - 1;
            int c = Integer.parseInt(tokenizer.nextToken()) - 1;
            cows.add(List.of(r, c));
            cowMap.put(List.of(r, c), k);
        }

        Set<Set<Integer>>[] result = new Set[2];
        result[0] = new HashSet<>();
        result[1] = new HashSet<>();

        final int[] dr = {-1, 1, 0, 0};
        final int[] dc = {0, 0, -1, 1};
        for (int k = 0; k < K; k++) {
            boolean[][] visited = new boolean[N][N];
            var startCow = cows.get(k);
            int startR = startCow.get(0);
            int startC = startCow.get(1);
            // System.out.printf("****COW %d****\n", k);

            Deque<List<Integer>> q = new ArrayDeque<>();  // [r, c, cost]
            q.add(List.of(startR, startC, 0));

            while (!q.isEmpty()) {
                var here = q.poll();
                int hereR = here.get(0);
                int hereC = here.get(1);
                int hereCost = here.get(2);

                // move set...
                if (visited[hereR][hereC]) continue;
                visited[hereR][hereC] = true;

                if (!(hereR == startR && hereC == startC) && (cowMap.containsKey(List.of(hereR, hereC)))) {
                    result[hereCost].add(Set.of(k, cowMap.get(List.of(hereR, hereC))));
                }

                // System.out.printf("search (%d, %d, %d)..", hereR, hereC, hereCost);

                for (int i = 0; i < 4; i++) {
                    int thereR = hereR + dr[i];
                    int thereC = hereC + dc[i];
                    if (thereR < 0 || thereR >= N || thereC < 0 || thereC >= N) continue;

                    if (containsRoad[hereR][hereC][i]) {
                        q.add(List.of(thereR, thereC, 1));
                    } else {
                        q.addFirst(List.of(thereR, thereC, hereCost));
                    }
                    // System.out.printf("i (%d,%d) ", thereR, thereC);
                }
                // System.out.println();
            }
        }

        // System.out.println(result[0]);
        // System.out.println(result[1]);
        System.out.print(result[1].size());

        scanner.close();
    }
}