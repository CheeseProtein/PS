/**
 * ALGOSPOT.COM
 * CH 6. Brute Force
 * Picnic
 * Submitted on June 30, 2021.
 * The execution time is 8ms.
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

int made = 0;
int n_students = 0;
int *students = nullptr;

void Check(std::vector<int *> &all_pairs, int pairs_left, int starting_pos) {
    if (pairs_left == 1) {
        for (size_t i = starting_pos; i < all_pairs.size(); ++i) {
                if (!students[all_pairs[i][0]] && !students[all_pairs[i][1]]) {
                    ++made;
            }
        }
    } else {
        int *clone = new int[n_students];

        for (size_t i = starting_pos; i < all_pairs.size(); ++i) {
            if (!students[all_pairs[i][0]] && !students[all_pairs[i][1]]) {
                std::copy(students, students + n_students, clone);

                ++students[all_pairs[i][0]];
                ++students[all_pairs[i][1]];

                Check(all_pairs, pairs_left - 1, i + 1);

                // restore
                std::copy(clone, clone + n_students, students);
            }
        }
        delete[] clone;
    }
}

int main() {
  int cases;
  std::cin >> cases;
  
  for (int i = 0; i < cases; ++i) {
    made = 0;
	int n_pairs;
	std::cin >> n_students >> n_pairs;

    std::vector<int *> all_pairs;
    int *newpair = nullptr;
	for (int j = 0; j < n_pairs; ++j) {
        /**
         * Making all_pair vector
         */
        newpair = (int *)malloc(2 * sizeof(int));
        std::cin >> newpair[0] >> newpair[1];
        all_pairs.push_back(newpair);
	}

    students = new int[n_students];
    memset(students, 0, n_students * sizeof(int));
    Check(all_pairs, n_students / 2, 0);
    delete[] students;

	std::cout << made << std::endl;
  }

  return 0;
}
