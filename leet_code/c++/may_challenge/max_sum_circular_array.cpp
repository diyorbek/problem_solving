#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    int best_sum_1 = maxSubarraySum(A);

    vector<int> n_A(A.begin(), A.end() - 1);
    for (auto it = n_A.begin(); it != n_A.end(); it++) {
      *it *= -1;
    }

    int best_sum_2 = accumulate(A.begin(), A.end(), maxSubarraySum(n_A));

    return max(best_sum_1, best_sum_2);
  }

  int maxSubarraySum(vector<int>& A) {
    int best_sum;
    int current_sum;
    int len = A.size();

    for (int i = 0; i < len; i++) {
      if (i == 0) {
        best_sum = current_sum = A[i];
        continue;
      }

      int current_element = A[i];

      if (current_element < current_sum + current_element) {
        // Extend the existing sequence with the current element
        current_sum += current_element;
      } else {
        // Start a new sequence at the current element
        current_sum = current_element;
      }

      if (current_sum >= best_sum) {
        best_sum = current_sum;
      }
    }

    return best_sum;
  }
};