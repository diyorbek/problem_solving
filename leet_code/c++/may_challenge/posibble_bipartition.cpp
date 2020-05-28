#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  unordered_map<int, vector<int> > graph;

  bool possibleBipartition(int N, vector<vector<int> >& dislikes) {
    for (auto d : dislikes) {
      graph[d[0]].push_back(d[1]);
      graph[d[1]].push_back(d[0]);
    }

    unordered_set<int> visited;
    for (auto v : graph) {
      if (visited.find(v.first) != visited.end())
        continue;

      unordered_set<int> A, B;
      dfs(v.first, &visited, &A, &B);

      for (auto a : A) {
        if (B.find(a) != B.end())
          return false;
      }
    }

    return true;
  }

  void dfs(int ver,
           unordered_set<int>* visited,
           unordered_set<int>* A,
           unordered_set<int>* B) {
    if ((*visited).find(ver) == (*visited).end()) {
      (*visited).insert(ver);

      (*A).insert(ver);

      for (auto child : graph[ver]) {
        (*B).insert(child);
        dfs(child, visited, B, A);
      }
    }
  }
};
