---
title: Trees
order: 5
description: Very cool type of graph
---

A tree is a connected, undirected, acyclic graph that also functions as a hierarchical data structure. A tree has:
- $N$ nodes and exactly $N-1$ edges.
- Exactly one path between any pair of nodes.

## Parts of a rooted tree
- We can choose any node as the **root**. In diagrams, the root is usually drawn at the top.
- Every node except the root has exactly one **parent**.
- Nodes can have zero, one, or multiple **children** below them.
- Nodes without children are **leaf** nodes.
![A tree rooted at A, with leaf nodes C, E, F, G, H and I](/images/lessons/trees/tree-terms.svg)

An **ancestor** of a node is any node from the root to that node.
![The ancestors of H are A and D](/images/lessons/trees/tree-ancestors.svg)

A **descendant** of a node is any node below it.
![The descendants of A are every other node, and the descendants of D are G, H and I](/images/lessons/trees/tree-descendants.svg)

A node + all its descendants form its **subtree**.
![The subtree of A is the whole tree, and the subtree of D is D, G, H and I](/images/lessons/trees/tree-subtrees.svg)

The **depth** of a node is how far down it is relative to the root.
![C has depth 1 and G has depth 2](/images/lessons/trees/tree-depth.svg)

## Traversals
The most common way to traverse a tree is using a [recursive DFS](../dfs/#an-easier-way). Nearly all tree algorithms and techniques (e.g., Heavy Light Decomposition, Binary Lifting, Euler Tour, Tree DP) utilise recursive DFS traversals. We can omit the visited array and instead store the parent as a parameter of the function. The root has no parent, so we usually denote it as `-1` or itself.

![DFS traversal of a tree](/images/lessons/trees/tree-traversal.svg)

<details>
<summary>Python implementation</summary>

```python
V, E, source = list(map(int, input().split()))

adj = [[] for i in range(V)]
# add all the edges into the adjacency list here

def dfs(current, parent):
    for nxt in adj[current]:
        if nxt != parent:
            dfs(nxt, current)
dfs(source, source)
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

void dfs(int current, int parent) {
    for(int nxt: adj[current]) {
        if (nxt != parent) {
            dfs(nxt, current);
        }
    }
}

int main() {
    cin >> V >> E >> source;
    adj.resize(V);
    // add all edges into adjacency list here

    dfs(source, source);
}
```
</details>

## Lines
A line is a special type of tree where:
- The two endpoint nodes each have exactly one neighbour.
- All other nodes each have exactly two neighbours.

The resulting graph looks like a line!

Can you see how a line satisfies all properties of a tree?
![A line of 4 nodes: 2 - 4 - 3 - 1](/images/lessons/trees/line.svg)
