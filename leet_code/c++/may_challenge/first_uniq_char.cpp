#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    if (!s.length())
      return -1;

    map<char, int> table;
    for (auto i = s.begin(); i != s.end(); i++) {
      if (!table[*i])
        table[*i] = 0;
      else
        table[*i]++;
    }

    for (auto i = table.begin(); i != table.end(); i++) {
      if (i->second == 0) {
        size_t f = s.find(i->second);
        if (f != string::npos) {
          return f;
        }
      }
    }
  }
};
