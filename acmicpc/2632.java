import java.io.*;
import java.util.*;

class Main {

    public static void main(String[] args) throws IOException {
        final BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
        final int target = Integer.parseInt(scanner.readLine());
        StringTokenizer tokenizer = new StringTokenizer(scanner.readLine(), " ");
        final int M = Integer.parseInt(tokenizer.nextToken());
        final int N = Integer.parseInt(tokenizer.nextToken());

        // A

        final int[] pizzaA = new int[M+1];
        Map<Integer, Integer> mapA = new HashMap<>();
        for (int m = 1; m <= M; m++) {
            pizzaA[m] = Integer.parseInt(scanner.readLine());
            if (pizzaA[m] <= target) {
                mapA.put(pizzaA[m], mapA.getOrDefault(pizzaA[m], 0) + 1);
            }
        }

        final int[] sumA = new int[2*M+1];
        sumA[0] = 0;
        for (int m = 1; m <= M; m++) {
            sumA[m] = sumA[m-1] + pizzaA[m];
        }
        for (int m = M+1; m <= 2*M; m++) {
            sumA[m] = sumA[m-1] + pizzaA[m - M];
        }

        for (int size = 2; size < M; size++) {
            for (int start = 1; start <= M; start++) {
                int chunk = sumA[start + size - 1] - sumA[start - 1];
                if (chunk <= target) {
                    mapA.put(chunk, mapA.getOrDefault(chunk, 0) + 1);
                }
            }
        }
        if (sumA[M] <= target) {
            mapA.put(sumA[M], 1);
        }

        // B

        final int[] pizzaB = new int[N+1];
        Map<Integer, Integer> mapB = new HashMap<>();
        for (int n = 1; n <= N; n++) {
            pizzaB[n] = Integer.parseInt(scanner.readLine());
            if (pizzaB[n] <= target) {
                mapB.put(pizzaB[n], mapB.getOrDefault(pizzaB[n], 0) + 1);
            }
        }

        final int[] sumB = new int[2*N+1];
        sumB[0] = 0;
        for (int n = 1; n <= N; n++) {
            sumB[n] = sumB[n-1] + pizzaB[n];
        }
        for (int n = N+1; n <= 2*N; n++) {
            sumB[n] = sumB[n-1] + pizzaB[n - N];
        }

        for (int size = 2; size < N; size++) {
            for (int start = 1; start <= N; start++) {
                int chunk = sumB[start + size - 1] - sumB[start - 1];
                if (chunk <= target) {
                    mapB.put(chunk, mapB.getOrDefault(chunk, 0) + 1);
                }
            }
        }
        if (sumB[N] <= target) {
            mapB.put(sumB[N], 1);
        }

        // System.out.printf("pizzaA: %s\n", Arrays.toString(pizzaA));
        // System.out.printf("sumA: %s\n", Arrays.toString(sumA));
        // System.out.println(mapA);
        // System.out.println(mapB);

        int res = mapA.getOrDefault(target, 0) + mapB.getOrDefault(target, 0);
        for (var i : mapA.entrySet()) {
            int pieceA = i.getKey();
            if (!mapB.containsKey(target - pieceA)) continue;
            res += i.getValue() * mapB.get(target-pieceA);
            // System.out.printf("add (%d)%d * (%d)%d\n", pieceA, i.getValue(), target-pieceA, mapB.get(target-pieceA));
        }

        System.out.println(res);
        scanner.close();
    }
}