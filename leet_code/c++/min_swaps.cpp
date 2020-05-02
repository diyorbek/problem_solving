// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
// time: , memory:
#include <string>

using namespace std;

class Solution {
 public:
  int minimumSwap(string s1, string s2) {
    if ((s1.length() + s2.length()) % 2) {
      return -1;
    }
  }
};