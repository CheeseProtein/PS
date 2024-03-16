import java.io.*;
import java.util.*;

class Main {

    static class Sticker {
        private List<boolean[][]> entry;

        public Sticker(List<boolean[][]> entry) {
            this.entry = entry;
        }
        public boolean[][] getSticker(int index) {
            return entry.get(index);
        }
    }

    static boolean[][] rotate(boolean[][] before) {
        int r = before.length;
        int c = before[0].length;
        boolean[][] result = new boolean[c][r];

        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                result[y][r-1 - x] = before[x][y];
            }
        }

        return result;
    }
    static Sticker makeSticker(boolean[][] first) {
        List<boolean[][]> entry = new ArrayList<>();
        entry.add(first);

        boolean[][] second = rotate(first);
        entry.add(second);

        boolean[][] third = rotate(second);
        entry.add(third);

        boolean[][] fourth = rotate(third);
        entry.add(fourth);

        return new Sticker(entry);
    }

    static boolean isAttachable(int r, int c, int stickerNo, int dir) {
        boolean[][] entry = stickers.get(stickerNo).getSticker(dir);
        int entryR = entry.length;
        int entryC = entry[0].length;
        if (r + entryR > R || c + entryC > C) {
            return false;
        }

        for (int x = 0; x < entryR; x++) {
            for (int y = 0; y < entryC; y++) {
                int boardR = r + x;
                int boardC = c + y;
                if (entry[x][y] && visited[boardR][boardC]) {
                    return false;
                }
            }
        }
        return true;
    }

    static void attach(int r, int c, int stickerNo, int dir) {
        boolean[][] entry = stickers.get(stickerNo).getSticker(dir);
        int entryR = entry.length;
        int entryC = entry[0].length;

        for (int x = 0; x < entryR; x++) {
            for (int y = 0; y < entryC; y++) {
                int boardR = r + x;
                int boardC = c + y;
                visited[boardR][boardC] = entry[x][y] || visited[boardR][boardC];
            }
        }
    }

    static int R;
    static int C;
    static int K;
    static List<Sticker> stickers = new ArrayList<>();
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine());
        R = Integer.parseInt(tokenizer.nextToken());
        C = Integer.parseInt(tokenizer.nextToken());
        K = Integer.parseInt(tokenizer.nextToken());
        visited = new boolean[R][C];

        for (int k = 0; k < K; k++) {
            tokenizer = new StringTokenizer(scanner.readLine());
            int r = Integer.parseInt(tokenizer.nextToken());
            int c = Integer.parseInt(tokenizer.nextToken());
            boolean[][] input = new boolean[r][c];
            for (int x = 0; x < r; x++) {
                tokenizer = new StringTokenizer(scanner.readLine());
                for (int y = 0; y < c; y++) {
                    input[x][y] = Integer.parseInt(tokenizer.nextToken()) == 1 ? true : false;
                }
            }
            stickers.add(makeSticker(input));
        }

        // System.out.println("******");
        // System.out.println(Arrays.deepToString(stickers.get(0).getSticker(0)));
        // System.out.println("******");

        nextSticker: for (int i = 0; i < stickers.size(); i++) {
            for (int d = 0; d < 4; d++) {
                for (int r = 0; r < R; r++) {
                    for (int c = 0; c < C; c++) {
                        if (!isAttachable(r, c, i, d)) continue;
                        attach(r, c, i, d);

                        // System.out.printf("attach #%d at %d, %d, dir %d\n", i, r, c, d);
                        // for (int rr = 0; rr < R; rr++) {
                        //     for (int cc = 0; cc < C; cc++) {
                        //         System.out.print(visited[rr][cc] ? "1" : "0");
                        //     }
                        //     System.out.println();
                        // }
                        continue nextSticker;
                    }
                }
            }
        }

        int count = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (visited[r][c]) count++;
            }
        }

        System.out.println(count);
        scanner.close();
    }
}