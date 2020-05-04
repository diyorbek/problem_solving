#include <map>
#include <string>

using namespace std;

class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    map<char, int> rMap;
    for (auto it = ransomNote.begin(); it != ransomNote.end(); it++) {
      if (!rMap[*it]) {
        rMap[*it] = 1;
      } else {
        rMap[*it]++;
      }
    }

    map<char, int> mMap;
    for (auto it = magazine.begin(); it != magazine.end(); it++) {
      if (!mMap[*it]) {
        mMap[*it] = 1;
      } else {
        mMap[*it]++;
      }
    }

    for (auto it = rMap.begin(); it != rMap.end(); it++) {
      if (it->second > mMap[it->first]) {
        return false;
      }
    }

    return true;
  }
};