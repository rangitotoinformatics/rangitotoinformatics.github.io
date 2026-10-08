---
title: Introduction to Graph Theory
order: 1
description: Graph representation
---

## What is a graph?
- A graph is a set of objects that have connections between them.
- These objects are called **vertices** (or **nodes**) and the connections are called **edges**.
- An edge directly connects two nodes. Those two nodes are considered **adjacent**.
- A **path** is a sequence of adjacent nodes where there is no repeated node. E.g., $1 → 2 → 4 → 3 → 5$
- A **cycle** is a type of path that begins and ends at the same node. E.g., $1 → 2 → 4 → 3 → 1$
![A graph with nodes 1 to 6 joined by edges](/images/lessons/introduction-to-graph-theory/graph.svg)

## Properties of graphs
- **Directed:** All edges have a fixed direction.
- **Undirected:** All edges have no fixed direction.
- **Acyclic:** There is no cycle in the graph.
- **Connected:** There is a path between every pair of nodes.
- **Weighted:** Edges have a set "cost" to traverse.
- **Unweighted:** Edges have no "cost" to traverse.

## Common graphs
The features of a graph can often stack. The most common graphs are:
1. **Undirected graphs** (very generic looking)
2. **Trees** (often for subtasks they are **Lines**)
3. **Directed acyclic graphs**

Weighted and unweighted graphs are both common.

## Representing the graph in code
Computers cannot picture or see entire graphs like we do. We must store our graph in a way that allows computers to use our graph efficiently.

One way to do so is to simply store a list of all the edges, where each edge is in the form $\{A, B\}$ (optional: include $W$ for weight). However, there are more efficient alternatives.

### Adjacency matrix
Store an $N \times N$ grid. The value at row $A$ column $B$ is $1$ if there is an edge from node $A$ to node $B$. The value can be modified to the weight of the edge if the graph is weighted.

![A directed graph and its adjacency matrix](/images/lessons/introduction-to-graph-theory/adjacency-matrix.svg)

The space complexity is $\Theta(N^2)$, where $N$ is the number of nodes.

### Adjacency list
Store $N$ lists, all of which are empty. For every edge that connects a node $A$ to a node $B$, go to the $A$th list and add $B$ to it. If the graph is weighted, you must also append the weight of the edge along with $B$; this is most commonly done with tuples or pairs. An adjacency list tells the computer: Which nodes are adjacent to a certain node $A$?

![An undirected graph and its adjacency list](/images/lessons/introduction-to-graph-theory/adjacency-list.svg)

The space complexity is $\Theta(N + M)$, where $N$ is the number of nodes and $M$ is the number of edges.

### Tips
In undirected graphs, ensure that you can travel from $B → A$, or it will become a directed graph.

Adjacency lists are the most common and preferred way of storing a graph. They are mostly more efficient than other alternatives.
This is because when a computer visits a node and needs to find adjacent nodes, it does not need to iterate through all $M$ edges, or all $N$ possible adjacent nodes (adjacency matrix).

<details>
<summary>Adjacency matrix: Python</summary>

```python
N = int(input())
M = int(input())
adj_matrix = [[0 for _ in range(N)] for _ in range(N)] # resize to N × N grid
for i in range(M):
    a, b = list(map(int, input().split()))
    adj_matrix[a][b] = 1 # for weighted graphs, set it equal to w instead of 1
    adj_matrix[b][a] = 1 # omit this line for directed graphs
```
</details>

<details>
<summary>Adjacency matrix: C++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj_matrix(N, vector<int>(N)); // resize to N × N grid
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj_matrix[a][b] = 1; // for weighted graphs, set it equal to w instead of 1
        adj_matrix[b][a] = 1; // omit this line for directed graphs
    }
}
```
</details>

<details>
<summary>Adjacency list: Python</summary>

```python
N = int(input())
M = int(input())
adj_list = [list() for _ in range(N)] # resize the list to N
for i in range(M):
    a, b = list(map(int, input().split()))
    adj_list[a].append(b)
    adj_list[b].append(a) # omit this line for directed graphs
```

> [!NOTE]
> For weighted graphs, use tuples or dictionaries.
</details>

<details>
<summary>Adjacency list: C++</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj_list(N); // resize the list to N
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a); // omit this line for directed graphs
    }
}
```

> [!NOTE] 
> For weighted graphs, use `vector<vector<pair<int,int>>>` and do `adj_list[a].push_back({b, w})`
</details>
