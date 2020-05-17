#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<int> results;

    if (n < m) {
      return results;
    }

    int freq_list[26] = {0};
    int non_zeros = 0;

    for (int i = 0; i < m; i++) {
      if (++freq_list[p[i] - 'a'] == 1)
        non_zeros++;
    }

    for (int win_start = 0, win_end = 0; win_end < n; ++win_end) {
      --freq_list[s[win_end] - 'a'];

      if (freq_list[s[win_end] - 'a'] == 0) {
        --non_zeros;
      } else if (freq_list[s[win_end] - 'a'] == -1) {
        ++non_zeros;
      }

      if (win_end - win_start + 1 > m) {
        ++freq_list[s[win_start] - 'a'];

        if (freq_list[s[win_start] - 'a'] == 1) {
          ++non_zeros;
        } else if (freq_list[s[win_start] - 'a'] == 0) {
          --non_zeros;
        }

        ++win_start;
      }

      if (non_zeros == 0) {
        results.push_back(win_start);
      }
    }

    return results;
  }
};
