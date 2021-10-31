#include <iostream>
#include <vector>

using namespace std;

void minimumBribes(vector<int> q) {
  int len = q.size();

  if (len == 1)
    cout << q[0] << endl;

  int total = 0;
  vector<int> mins;

  for (int i = len - 1; i >= 0; i--) {
    int minCount = 0;

    for (int j = 0; j < mins.size(); j++) {
      if (q[i] > mins[j]) {
        minCount++;
      }

      if (minCount > 2) {
        cout << "Too chaotic" << endl;
        return;
      }
    }

    total += minCount;

    mins.push_back(q[i]);
    sort(mins.begin(), mins.end());

    if (q.size() > 3)
      mins.pop_back();
  }

  cout << total << endl;
}
