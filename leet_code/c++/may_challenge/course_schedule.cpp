#include <vector>

using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>{});

    for (auto crs : prerequisites) {
      graph[crs[1]].push_back(crs[0]);
    }

    bool visited[numCourses];
    fill_n(visited, numCourses, false);

    bool stack[numCourses];
    fill_n(stack, numCourses, false);

    for (int ver = 0; ver < numCourses; ver++) {
      if (!visited[ver]) {
        if (isCyclic(ver, graph, visited, stack)) {
          return false;
        }
      }
    }

    return true;
  }

  bool isCyclic(int ver,
                vector<vector<int>>& graph,
                bool* visited,
                bool* stack) {
    if (!visited[ver]) {
      visited[ver] = true;
      stack[ver] = true;

      for (int adj : graph[ver]) {
        if (!visited[adj] && isCyclic(adj, graph, visited, stack)) {
          return true;
        } else if (stack[adj]) {
          return true;
        }
      }
    }

    stack[ver] = false;

    return false;
  }
};
