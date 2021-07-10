#include <iostream>
#include <cmath>

int main() {
   int T;
   scanf("%d", &T);

   for (int i = 0; i < T; ++i) {
      int x1, y1, r1, x2, y2, r2;
      scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

      if (x1 == x2 && y1 == y2 && r1 == r2) {
         printf("-1\n");
         continue;
      }

      double dist = sqrt(static_cast<double>((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
      double longer = static_cast<double>(r1 > r2 ? r1 : r2);
      double shorter = static_cast<double>(r1 > r2 ? r2 : r1);

      if (dist > longer + shorter) printf("0\n");
      else if (dist == longer + shorter) printf("1\n");
      else if (dist == longer - shorter) printf("1\n");
      else if (dist < longer - shorter) printf("0\n");
      else printf("2\n");
   }
   return 0;
}
