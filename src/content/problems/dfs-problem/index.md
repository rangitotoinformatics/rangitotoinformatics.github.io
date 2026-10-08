---
problemId: 5
title: DFS problem
difficulty: Easy
topics: [Graphs, DFS]
---

Read in a connected, **undirected** graph and use a depth first traversal. Print the vertices in the order that you first visit them. Start your traversal from **node $0$**.

## Input
The first line will contain two space separated numbers, $N$ $(1 \leq N \leq 10^5)$, the number of vertices in the graph and $M$ $(1 \leq M \leq 10^6)$, the number of edges in the graph.

The remaining $M$ lines in the file will be of the form $x$ $y$ which means that there's an edge between $x$ and $y$. Vertices are numbered from $0$ to $N-1$.

## Output
Output each vertex on its own line.

## Scoring
- For $50$ points, implement an iterative DFS solution
- For the other $50$ points, implement a recursive DFS solution