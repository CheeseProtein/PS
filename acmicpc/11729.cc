#include <iostream>
#include <math.h>

void Hanoi(int start, int via, int end, int n) {
   if (n == 1) {
      printf("%d %d\n", start, end);
   } else {
      Hanoi(start, end, via, n - 1);
      printf("%d %d\n", start, end);
      Hanoi(via, start, end, n - 1);
   }
}

int main() {
   int N;
   scanf("%d", &N);
   printf("%d\n", static_cast<int>((pow(2, N) - 1)));
   Hanoi(1, 2, 3, N);
   return 0;
}
