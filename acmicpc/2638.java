import java.io.*;
import java.util.*;

class Main {

    private static final int[] dr = {-1, 1, 0, 0};
    private static final int[] dc = {0, 0, -1, 1};

    private static boolean[][] visited;
    private static int[][] board;
    private static int R;
    private static int C;
    private static Set<List<Integer>> exposedCheese;

    private static int countExposedSurface(List<Integer> here) {
        int count = 0;
        int r = here.get(0);
        int c = here.get(1);
        for (int i = 0; i < 4; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (rr < 0 || rr >= R || cc < 0 || cc >= C || !visited[rr][cc]) continue;
            count++;
        }
        return count;
    }

    private static void dfsAir(int r, int c) {
        visited[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (rr < 0 || rr >= R || cc < 0 || cc >= C || visited[rr][cc]) continue;
            
            if (board[rr][cc] == 1) exposedCheese.add(List.of(rr, cc));
            else dfsAir(rr, cc);
        }
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
        R = Integer.parseInt(tokenizer.nextToken());
        C = Integer.parseInt(tokenizer.nextToken());
        board = new int[R][C];
        int cheeseLeft = 0;
        for (int r = 0; r < R; r++) {
            tokenizer = new StringTokenizer(scanner.readLine(), " ");
            for (int c = 0; c < C; c++) {
                board[r][c] = Integer.parseInt(tokenizer.nextToken());
                cheeseLeft += board[r][c];
            }
        }

        visited = new boolean[R][C];
        final Deque<List<Integer>> outerAir = new ArrayDeque<>();
        visited[0][0] = true; outerAir.add(List.of(0, 0));
        visited[0][C-1] = true; outerAir.add(List.of(0, C-1));
        visited[R-1][0] = true; outerAir.add(List.of(R-1, 0));
        visited[R-1][C-1] = true; outerAir.add(List.of(R-1, C-1));
        exposedCheese = new HashSet<>();
        while (!outerAir.isEmpty()) {
            var here = outerAir.poll();
            int hereR = here.get(0);
            int hereC = here.get(1);
            
            for (int i = 0; i < 4; i++) {
                int rr = hereR + dr[i];
                int cc = hereC + dc[i];
                if (rr < 0 || rr >= R || cc < 0 || cc >= C || visited[rr][cc]) continue;
                if (board[rr][cc] == 0) {  // air
                    visited[rr][cc] = true;
                    outerAir.add(List.of(rr, cc));
                } else {  // cheese
                    exposedCheese.add(List.of(rr, cc));
                }
            }
        }

        int t = 0;
        while (cheeseLeft > 0) {
            Set<List<Integer>> meltingCheese = new HashSet<>();
            exposedCheese.stream()
                    .filter(i -> countExposedSurface(i) >= 2)
                    .forEach(i -> meltingCheese.add(i));
            
            for (var i : meltingCheese) {
                int r = i.get(0);
                int c = i.get(1);
                visited[r][c] = true;
                cheeseLeft--;
                exposedCheese.remove(i);
                board[r][c] = 0;  // FOR DEBUG
            }
            
            for (var i : meltingCheese) {
                int r = i.get(0);
                int c = i.get(1);
                for (int k = 0; k < 4; k++) {
                    int rr = r + dr[k];
                    int cc = c + dc[k];
                    if (rr < 0 || rr >= R || cc < 0 || cc >= C || visited[rr][cc]) continue;

                    if (board[rr][cc] == 0) {  // new air
                        dfsAir(rr, cc);
                    } else {  // new exposedCheese
                        exposedCheese.add(List.of(rr, cc));
                    }
                }
            }

            t++;

            // System.out.printf("***AT %d***\n", t);
            // for (int r = 0; r < R; r++) {
            //     for (int c = 0; c < C; c++) {
            //         System.out.print(board[r][c]);
            //     }
            //     System.out.println();
            // }
            // System.out.println(exposedCheese);
        }

        System.out.println(t);

        // System.out.println("***VISITED***");
        // for (int r = 0; r < R; r++) {
        //     for (int c = 0; c < C; c++) {
        //         System.out.print(visited[r][c] ? 'x' : '.');
        //     }
        //     System.out.println();
        // }
        // System.out.println(exposedCheese);
        // System.out.println(cheeseLeft);

        scanner.close();
    }
}