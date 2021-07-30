#include <iostream>
using namespace std;

int height[50];
int weight[50];

int main() {
   int N;
   cin >> N;

   for (int i = 0; i < N; ++i) {
      cin >> weight[i] >> height[i];
   }

   for (int i = 0; i < N; ++i) {
      int count = 1;
      for (int j = 0; j < N; ++j) {
         if (weight[j] > weight[i] && height[j] > height[i])
            ++count;
      }
      printf("%d\n", count);
   }
   return 0;
}
