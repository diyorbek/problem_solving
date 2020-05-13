#include <algorithm>
#include <string>

using namespace std;

class Solution {
 public:
  string removeKdigits(string num, int k) {
    if (num.size() == k)
      return "0";

    int rlen = num.size() - k;
    string r;

    int i = 0;
    string::iterator min;

    while (i < rlen) {
      auto till = num.end() - rlen + i + 1;
      min = min_element(i ? min + 1 : num.begin(), till);

      if (r.size() || *min != '0') {
        r += *min;
      }

      i++;
    }

    return r.size() ? r : "0";
  }
};