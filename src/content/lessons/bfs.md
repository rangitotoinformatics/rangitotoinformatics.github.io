---
title: Breadth First Search
order: 2
description: BFS
---

The Breadth First Search (BFS) algorithm is a way to traverse a graph.

It starts from a source node and explores the graph level by level:
- It first visits all nodes that are distance 0 from the source (i.e., the source itself).
- Then it visits all nodes that are distance 1 from the source, and so on, until all reachable nodes have been visited.
- Whenever BFS visits a node, it adds each unvisited adjacent node to the queue and marks it as visited.

Here, node $a$ is the source.
![BFS animation on a graph](/images/lessons/bfs/bfs.svg)

## Things we need
- We need a data structure that prioritizes visiting nodes with the shortest distance first. Since BFS visits nodes in increasing order of distance, the node with the shortest distance should be the node added to the data structure the earliest. The best choice is a **first in first out data structure**, such as a **queue**.
- Whenever we visit a node, we need to add its unvisited adjacent nodes. The best choice is an **adjacency list**.
- We need to store a list to track the nodes that we've visited, so that if we revisit it, we don't consider its adjacent nodes again. The best choice is a **boolean array**.

## What does the code look like?
- Create visited array, adjacency list and empty queue
- Add the source node into the queue and mark as visited
- While there is something to visit:
  - Take the first node and remove it from the queue
  - Push all unvisited adjacent nodes into the queue and mark them as visited

The time complexity is $\Theta(V + E)$, where $V$ is the number of nodes and $E$ is the number of edges.

## Finding the shortest path/distance
An important property of BFS is how it explores the graph. Because it processes layer by layer (nodes with the least distance first), we can use it to find the shortest path between the source node and any other node on an **unweighted graph**. Here, the shortest distance between two nodes is defined as the least number of edges between them.

There are two changes we must make:
- Instead of storing a boolean in our visited array, we can store each node's distance from the source.
- Instead of storing just the node in our queue, we also need to store the distance. When we push adjacent nodes into the queue, we now need to push (adjacent_node, **current_distance + 1**)

## Try some problems
<div class="problem-list">

- [You, Robot (NZIC 2019)](https://train.nzoi.org.nz/problems/1034)
- [Holiday Shopping (NZIC 2022)](https://train.nzoi.org.nz/problems/1238)
- [Counting Islands (NZIC 2017)](https://train.nzoi.org.nz/problems/786)

</div>

> [!TIP]
> Don't construct adjacency lists for grid problems because the neighbours of each cell are always consistent (up, down, left or right). Just push all four neighbours, but make sure you don't go outside of the grid.