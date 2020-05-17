// https://leetcode.com/problems/valid-anagram/
#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    int n = s.size();
    int m = t.size();

    if (n != m) {
      return false;
    }

    map<char, int> freq_map;
    int non_zeros = 0;

    for (int i = 0; i < n; i++) {
      freq_map[s[i]]++;
      if (freq_map[s[i]] == 1) {
        non_zeros++;
      }
    }

    for (int i = 0; i < m; i++) {
      freq_map[t[i]]--;
      if (freq_map[t[i]] == 0) {
        non_zeros--;
      }
    }

    return non_zeros == 0;
  }
};