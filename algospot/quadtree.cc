/**
 * ALGOSPOT.COM
 * CH 7. Divide & Conquer
 * Quadtree
 * Submitted on Aug 2, 2021.
 * The execution time is 8ms.
 */
#include <iostream>
using namespace std;

string arrange(string::iterator &cur) {
  string part[4];

  for (int i = 0; i < 4; ++i) {
    if (*cur == 'x') {
      part[i] = arrange(++cur);
    } else {
      part[i] = (*cur);
      ++cur;
    }
  }

  string result = "x" + part[2] + part[3] + part[0] + part[1];
  return result;
}

int main() {
  int C;
  cin >> C;

  for (int i = 0; i < C; ++i) {
    string input;
    cin >> input;

    auto init = input.begin();
    if (input[0] != 'x') {
      cout << (*init) << endl;
    } else {
      cout << arrange(++init) << endl;
    }
  }
  return 0;
}
