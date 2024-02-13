import java.io.*;
import java.util.*;

class Main {

    static int N;
    static int K;
    static int[][] color;
    static List<int[]> pieces;
    static List<Integer>[][] boardStatus;

    static final int[] dr = {999, 0, 0, -1, 1};
    static final int[] dc = {999, 1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
        N = Integer.parseInt(tokenizer.nextToken());
        K = Integer.parseInt(tokenizer.nextToken());
        color = new int[N][N];
        for (int r = 0; r < N; r++) {
            tokenizer = new StringTokenizer(scanner.readLine(), " ");
            for (int c = 0; c < N; c++) {
                color[r][c] = Integer.parseInt(tokenizer.nextToken());
            }
        }
        pieces = new ArrayList<>();
        boardStatus = new List[N][N];
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                boardStatus[r][c] = new ArrayList<>();
            }
        }
        for (int k = 0; k < K; k++) {
            tokenizer = new StringTokenizer(scanner.readLine(), " ");
            final int r = Integer.parseInt(tokenizer.nextToken()) - 1;
            final int c = Integer.parseInt(tokenizer.nextToken()) - 1;
            final int d = Integer.parseInt(tokenizer.nextToken());
            pieces.add(new int[] {r, c, d});
            boardStatus[r][c].add(k);
        }

        int t;
        GAME: for (t = 1; t <= 1000; t++) {
            for (int k = 0; k < pieces.size(); k++) {
                var piece = pieces.get(k);
                int hereR = piece[0];
                int hereC = piece[1];
                int hereDir = piece[2];
                int nextR = hereR + dr[hereDir];
                int nextC = hereC + dc[hereDir];

                boolean reverseFlag = false;
                if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || color[nextR][nextC] == 2) {
                    piece[2] = (hereDir % 2 == 0) ? (hereDir - 1) : (hereDir + 1);
                    hereDir = piece[2];
                    nextR = hereR + dr[hereDir];
                    nextC = hereC + dc[hereDir];
                    if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= N || color[nextR][nextC] == 2) {
                        continue;
                    } else if (color[nextR][nextC] == 1) {
                        reverseFlag = true;
                    }
                } else if (color[nextR][nextC] == 1) {
                    reverseFlag = true;
                }

                Deque<Integer> q = new ArrayDeque<>();
                boolean underK = true;
                for (int i : boardStatus[hereR][hereC]) {
                    if (underK && i != k) continue;
                    underK = false;
                    if (reverseFlag) {
                        q.addFirst(i);
                    } else {
                        q.add(i);
                    }
                }

                while (!q.isEmpty()) {
                    int toMove = q.poll();
                    boardStatus[hereR][hereC].remove(Integer.valueOf(toMove));
                    boardStatus[nextR][nextC].add(Integer.valueOf(toMove));
                    int[] pieceStatus = pieces.get(toMove);
                    pieceStatus[0] = nextR;
                    pieceStatus[1] = nextC;
                }

//                 if (t == 2) {
//                 System.out.printf("****TURN %d, move %d****\n", t, k);
//                 System.out.println(Arrays.deepToString(boardStatus));
//                 pieces.stream()
//                         .forEach(i -> System.out.println(Arrays.toString(i)));
//                 }
                if (boardStatus[nextR][nextC].size() >= 4) break GAME;
            }
        }

        if (t == 1001) {
            System.out.println(-1);
        } else {
            System.out.println(t);
        }
        scanner.close();
    }
}