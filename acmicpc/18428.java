import java.io.*;
import java.util.*;

class Main {

    static int N;
    static char[][] board;
    static Set<List<Integer>> dangerZone;
    static List<List<Integer>> dangerZoneLists = new ArrayList<>();
    static List<List<Integer>> students;

    static boolean isInDangerZone(List<List<Integer>> visited, int r, int c, int dr, int dc) {
        if (r < 0 || r >= N || c < 0 || c >= N || board[r][c] == 'O' || board[r][c] == 'S') {
            return false;
        }
        if (board[r][c] == 'T') {
            return true;
        }

        visited.add(List.of(r, c));
        return isInDangerZone(visited, r + dr, c + dc, dr, dc);
    }

    static boolean selectCombination(Set<Integer> combination, int remainingCount, int startFrom) {
        if (remainingCount <= 0) {
            for (int i : combination) {
                List<Integer> obstacle = dangerZoneLists.get(i);
                int r = obstacle.get(0);
                int c = obstacle.get(1);
                board[r][c] = 'O';
            }
            boolean isAnyoneInDanger = false;
            for (var student : students) {
                int r = student.get(0);
                int c = student.get(1);
                isAnyoneInDanger |= isInDangerZone(new ArrayList<>(), r+1, c, 1, 0);
                isAnyoneInDanger |= isInDangerZone(new ArrayList<>(), r-1, c, -1, 0);
                isAnyoneInDanger |= isInDangerZone(new ArrayList<>(), r, c+1, 0, 1);
                isAnyoneInDanger |= isInDangerZone(new ArrayList<>(), r, c-1, 0, -1);
            }
            if (!isAnyoneInDanger) {
                // System.out.printf("OK when... ");
                // System.out.println(combination);
                // System.out.println(dangerZoneLists);
                // for (int r = 0; r < N; r++) {
                //     System.out.println(Arrays.toString(board[r]));
                // }
                // System.out.println(isInDangerZone(new ArrayList<>(), 1, 1, 0, -1));
                return true;
            } else {
                for (int i : combination) {
                    List<Integer> obstacle = dangerZoneLists.get(i);
                    int r = obstacle.get(0);
                    int c = obstacle.get(1);
                    board[r][c] = 'X';
                }
                return false;
            }
        }

        for (int next = startFrom; next < dangerZoneLists.size() - (remainingCount-1); next++) {
            combination.add(next);

            boolean res = selectCombination(combination, remainingCount-1, next+1);
            if (res) {
                return true;
            }

            combination.remove(Integer.valueOf(next));
        }

        return false;
    }

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(scanner.readLine());
        board = new char[N][N];
        students = new ArrayList<>();
        for (int r = 0; r < N; r++) {
            StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
            for (int c = 0; c < N; c++) {
                board[r][c] = tokenizer.nextToken().charAt(0);
                if (board[r][c] == 'S') {
                    students.add(List.of(r, c));
                }
            }
        }

        dangerZone = new HashSet<>();
        final int[] dr = {-1, 1, 0, 0};
        final int[] dc = {0, 0, -1, 1};
        for (var student : students) {
            int r = student.get(0);
            int c = student.get(1);
            for (int k = 0; k < 4; k++) {
                int rr = r + dr[k];
                int cc = c + dc[k];
                if (rr < 0 || rr >= N || cc < 0 || cc >= N) continue;
                if (board[rr][cc] == 'T') {
                    System.out.println("NO");
                    scanner.close();
                    return;
                }
            }
        }
        for (var student : students) {
            int r = student.get(0);
            int c = student.get(1);
            List<List<Integer>> newDangerZone = new ArrayList<>();
            if (isInDangerZone(newDangerZone, r + 1, c, 1, 0)) {
                dangerZone.addAll(newDangerZone);
            }
            newDangerZone = new ArrayList<>();
            if (isInDangerZone(newDangerZone, r - 1, c, -1, 0)) {
                dangerZone.addAll(newDangerZone);
            }
            newDangerZone = new ArrayList<>();
            if (isInDangerZone(newDangerZone, r, c+1, 0, 1)) {
                dangerZone.addAll(newDangerZone);
            }
            newDangerZone = new ArrayList<>();
            if (isInDangerZone(newDangerZone, r, c-1, 0, -1)) {
                dangerZone.addAll(newDangerZone);
            }
        }

        dangerZoneLists.addAll(dangerZone);
        final int edge = dangerZoneLists.size() <= 3 ? 0 : dangerZoneLists.size() - 3;
        for (int first = 0; first <= edge; first++) {
            Set<Integer> combination = new HashSet<>();
            combination.add(first);
            boolean res = selectCombination(combination, Math.min(2, dangerZoneLists.size() - 1), first + 1);
            if (res) {
                System.out.println("YES");
                scanner.close();
                return;
            }
        }

        // System.out.println(dangerZone);
        // System.out.println(Arrays.deepToString(board));
        // System.out.println(students);

        System.out.println("NO");
        scanner.close();
    }
}