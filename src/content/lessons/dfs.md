---
title: Depth First Search
order: 4
description: DFS
---

The depth first search (DFS) algorithm is a way to traverse a graph.
- It starts from a source node and explores the graph by going as deep as possible, until it reaches a dead end.
- Then, it backtracks once, and then goes as deep as possible, and so on.

The time complexity is $\Theta(V + E)$, where $V$ is the number of nodes and $E$ is the number of edges.

> [!NOTE]
> It doesn't guarantee the shortest path. It will become really slow if you use it to find the shortest path.

## Things we need
- We need a data structure that prioritizes the node that we added most recently. The best choice is a **last in first out** data structure, such as a **stack**.
- We also need a visited array and an adjacency list.


## An easier way
Instead of using a stack, we most commonly write DFS recursively because it is simpler to write up.
- Create visited array and adjacency list.
- DFS function, has one parameter: current node
  - Mark current node as visited
  - Recursively call all adjacent nodes if not visited
- Call the DFS function with the source node

The time complexity remains the same.

<details>
<summary>Python implementation</summary>

```python
V, E, source = list(map(int, input().split()))

adj = [[] for i in range(V)]
# add all the edges into the adjacency list here

visited = [False for i in range(V)]

def dfs(current):
    visited[current] = True
    for next in adj[current]:
        if not visited[next]:
            dfs(next)
dfs(source)
```
</details>


<details>
<summary>C++ implementation</summary>

```cpp
#include <iostream>
#include <vector>
using namespace std;

int V, E, source;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int current) {
    visited[current] = true;
    for(int next: adj[current]) {
        if (not visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    cin >> V >> E >> source;
    visited.resize(V, false);
    adj.resize(V);
    // add all edges into adjacency list here

    dfs(source);
}
```
</details>

### Try some problems
Have a go at <mark> **DFS problem** (in the rangi informatics group) </mark>.
