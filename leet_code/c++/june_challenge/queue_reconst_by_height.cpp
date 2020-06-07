#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(),
         [](vector<int> person1, vector<int> person2) {
           if (person1[0] == person2[0]) {
             return person1[1] < person2[1];
           }

           return person1[0] > person2[0];
         });

    vector<vector<int>> reqq;
    for (auto person : people) {
      reqq.insert(reqq.begin() + person[1], person);
    }

    return reqq;
  }
};