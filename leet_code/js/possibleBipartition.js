/**
 * @param {number} N
 * @param {number[][]} dislikes
 * @return {boolean}
 */

function dfs(ver, visited, A, B) {
  if (!visited[ver]) {
    visited[ver] = true;

    A[ver] = true;

    for (const child in graph[ver]) {
      B[child];
      dfs(child, visited, B, A);
    }
  }
}

var possibleBipartition = function (N, dislikes) {
  const graph = {};

  for (const d of dislikes) {
    if (graph[d[0]] != undefined) {
      graph[d[0]].push(d[1]);
    } else {
      graph[d[0]] = [d[1]];
    }
    if (graph[d[1]] != undefined) {
      graph[d[1]].push(d[0]);
    } else {
      graph[d[1]] = [d[0]];
    }
  }

  const visited = {};
  for (const v in graph) {
    if (visited[v]) continue;

    const A = {},
      B = {};
    dfs(v, visited, A, B);

    for (const a in A) {
      if (B[a]) return false;
    }
  }

  return true;
};
