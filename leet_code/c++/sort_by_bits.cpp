// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// time: 16ms, memory: 8.8MB
#include <bitset>
#include <string>
#include <vector>

using namespace std;

int countBits(int n) {
  bitset<16> b(n);
  return b.count();
}

bool comparator(int a, int b) {
  int an = countBits(a);
  int bn = countBits(b);
  return an == bn ? a < b : an < bn;
}

class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), comparator);

    return arr;
  }
};