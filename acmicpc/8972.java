import java.io.*;
import java.util.*;

class Main {

    static int R;
    static int C;
    static int[][] board;  // 0 for blank, -1 for mine, positive for enemies
    static List<Integer> myPiece;
    static int numberOfEnemies;
    static boolean[] isEnemyDead;
    static Map<Integer, List<Integer>> enemyPiece;
    static String myMove;

    static final int[] dr = {999, 1, 1, 1, 0, 0, 0, -1, -1, -1};
    static final int[] dc = {999, -1, 0, 1, -1, 0, 1, -1, 0, 1};

    private static boolean isDoneAfterMoveMine(int moves) {
        int dir = myMove.charAt(moves) - '0';
        int rr = myPiece.get(0) + dr[dir];
        int cc = myPiece.get(1) + dc[dir];

        if (board[rr][cc] > 0) return true;

        board[myPiece.get(0)][myPiece.get(1)] = 0;
        board[rr][cc] = -1;
        myPiece = List.of(rr, cc);
        return false;
    }

    private static List<Integer> moveEnemy(int id) {
        var here = enemyPiece.get(id);
        int hereR = here.get(0);
        int hereC = here.get(1);
        // System.out.printf("MOVE ENEMY %d: (%d, %d) -> ", id, hereR, hereC);

        Queue<List<Integer>> pq = new PriorityQueue<>((a, b) -> {
            return a.get(1) - b.get(1);
        });  // [dir, dist]
        for (int dir = 1; dir <= 9; dir++) {
            int rr = hereR + dr[dir];
            int cc = hereC + dc[dir];
            if (rr < 0 || rr >= R || cc < 0 || cc >= C) continue;
            int dist = Math.abs(myPiece.get(0) - rr) + Math.abs(myPiece.get(1) - cc);
            pq.add(List.of(dir, dist));
        }
        // System.out.print(pq);
        
        var there = pq.poll();
        int thereDir = there.get(0);
        int thereR = hereR + dr[thereDir];
        int thereC = hereC + dc[thereDir];
        // System.out.printf(" (%d, %d)\n", thereR, thereC);

        board[hereR][hereC] = board[hereR][hereC] == id ? 0 : board[hereR][hereC];
        board[thereR][thereC] = id;
        enemyPiece.put(id, List.of(thereR, thereC));
        return List.of(thereR, thereC);
    }
     
    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        final StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        R = Integer.parseInt(tokenizer.nextToken());
        C = Integer.parseInt(tokenizer.nextToken());
        board = new int[R][C];
        enemyPiece = new HashMap<>();
        for (int r = 0; r < R; r++) {
            final String line = scanner.readLine();
            for (int c = 0; c < C; c++) {
                final char ch = line.charAt(c);
                if (ch == 'I') {
                    myPiece = List.of(r, c);
                    board[r][c] = -1;
                } else if (ch == 'R') {
                    numberOfEnemies++;
                    enemyPiece.put(numberOfEnemies, List.of(r, c));
                    board[r][c] = numberOfEnemies;
                } else {
                    board[r][c] = 0;
                }
            }
        }
        isEnemyDead = new boolean[enemyPiece.size() + 1];

        myMove = scanner.readLine();
        int move = 0;
        LOOP: for (move = 0; move < myMove.length(); move++) {
            if (isDoneAfterMoveMine(move)) {
                break;
            }

            Map<List<Integer>, List<Integer>> moveResult = new HashMap<>();  // [r, c] = {id}
            for (int enemy = 1; enemy <= numberOfEnemies; enemy++) {
                if (isEnemyDead[enemy]) continue;

                List<Integer> result = moveEnemy(enemy);
                if (result.equals(myPiece)) {
                    break LOOP;
                }
                List<Integer> prevResult = moveResult.getOrDefault(result, new ArrayList<>());
                prevResult.add(enemy);
                moveResult.put(result, prevResult);
            }

            for (var i : moveResult.entrySet()) {
                if (i.getValue().size() == 1) continue;
                var here = i.getKey();
                int hereR = here.get(0);
                int hereC = here.get(1);
                board[hereR][hereC] = 0;

                for (int enemy : i.getValue()) {
                    isEnemyDead[enemy] = true;
                }
            }
            
            // System.out.print("******");
            // System.out.println(move + 1);
            // for (int r = 0; r < R; r++) {
            //     System.out.println(Arrays.toString(board[r]));
            // }
            //System.out.println(enemyPiece);
        }

        final StringBuilder printer = new StringBuilder();
        if (move == myMove.length()) {
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    switch (board[r][c]) {
                        case -1: printer.append('I'); break;
                        case 0: printer.append('.'); break;
                        default: printer.append('R');
                    }
                }
                printer.append('\n');
            }
        } else {
            printer.append("kraj ").append(move + 1).append('\n');
        }

        // System.out.println(move + 1);
        // for (int r = 0; r < R; r++) {
        //     System.out.println(Arrays.toString(board[r]));
        // }
        // System.out.println(enemyPiece);

        System.out.print(printer);
        scanner.close();
    }

}