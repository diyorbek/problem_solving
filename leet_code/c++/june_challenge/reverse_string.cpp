#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  void reverseString_1(vector<char>& s) { reverse(s.begin(), s.end()); }
  void reverseString_2(vector<char>& s) {
    for (int i = 0; i < s.size() / 2; i++) {
      swap(s[i], s[s.size() - 1 - i]);
    }
  }
};