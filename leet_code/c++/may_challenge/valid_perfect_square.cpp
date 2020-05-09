class Solution {
 public:
  bool isPerfectSquare(unsigned long int num) {
    if (num == 0 || num == 1)
      return true;

    if (num % 2) {
      if ((num - 1) % 4 != 0)
        return false;

      return binary_search((num - 1) / 4, 1);
    }

    if (num % 4 != 0)
      return false;

    return binary_search(num / 4 - 1, 2);
  }

  bool binary_search(unsigned long int a, int delta) {
    unsigned long int L = 0;
    unsigned long int R = a / 2;

    while (L <= R) {
      unsigned long int m = (L + R) / 2;

      if (m * (m + delta) < a) {
        L = m + 1;
      } else if (m * (m + delta) > a) {
        R = m - 1;
      } else {
        return true;
      }
    };

    return false;
  }
};