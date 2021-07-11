#include <iostream>
#include <algorithm>

int **arr;

void star(int x, int y, int N) {
   if (N == 3) {
      arr[x][y] = arr[x][y+1] = arr[x][y+2] = arr[x+1][y] = arr[x+1][y+2] = arr[x+2][y] = arr[x+2][y+1] = arr[x+2][y+2] = 1;
   } else {
      star(x, y, N/3);
      star(x + N/3, y, N/3);
      star(x + 2*N/3, y, N/3);

      star(x, y + N/3, N/3);
      star(x + 2*N/3, y + N/3, N/3);

      star(x, y + 2*N/3, N/3);
      star(x + N/3, y + 2*N/3, N/3);
      star(x + 2*N/3, y + 2*N/3, N/3);
   }
}

int main() {
   int N;
   scanf("%d", &N);
   arr = new int*[N];
   for (int i = 0; i < N; ++i) {
      arr[i] = new int[N];
      std::fill(arr[i], arr[i] + N, 0);
   }
   star(0, 0, N);

   for (int i = 0; i < N; ++i) {
      // printf("%3d: ", i);
      for (int j = 0; j < N; ++j) {
         if (arr[i][j]) printf("*");
         else printf(" ");
      }
      printf("\n");
   }
   return 0;
}
