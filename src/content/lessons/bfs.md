---
title: Breadth First Search
order: 2
description: BFS
---

The Breadth First Search (BFS) algorithm is a way to traverse a graph.
<br>
It starts from a source node and explores the graph level by level:
- It first visits all nodes that are distance 0 from the source (ie the source itself).
- Then it visits all nodes that are distance 1 from the source, and so on, until all nodes have been visited
- Every time it visits a new node, it pushes all its adjacent nodes to a specific data structure so they can be visited later.

Here, node $a$ is the source.
![BFS animation: nodes change colour as they are added to the queue and visited](/images/lessons/bfs/bfs.svg)

## Things we need
- We need a data structure that prioritizes visiting nodes with the shortest distance first. Since BFS visits nodes in increasing order of distance, the node with the shortest distance should be the node added to the data structure the earliest. The best choice is a **first in first out data structure**, such as a **queue**.
- Every time we visit a new node, we need to add all its adjacent nodes. The best choice is an **adjacency list**.
- We need to store a list to track the nodes that we've visited, so that if we revisit it, we don't consider its adjacent nodes again. The best choice is a **boolean array**.

## What does the code look like?
- Create visited array, adjacency list and empty queue
- Add the source node into the queue
- While there is something to visit in the queue:
  - Take the first node and remove it from the queue
  - If it has been visited skip everything below (ie `continue`)
  - Mark current node as visited
  - Push all adjacent nodes into the queue

The time complexity is $\Theta(V + E)$, where $V$ is the number of nodes and $E$ is the number of edges.

## Finding the shortest path/distance
An important property of BFS is how it explores the graph. Because it processes layer by layer (nodes with the least distance first), we can use it to find the shortest path between the source node and any other node on an **undirected graph**. Here, the shortest distance between two nodes is defined as the least number of edges between them.

There are two changes we must make:
- Instead of storing a boolean value in our visited array, we can store the distance from the source node. When we want the shortest distance, the answer is the value stored in the visited array. 
- Instead of storing the just node in our queue, we also need to store the distance. When we push adjacent nodes into the queue, we now need to push (adjacent_node, **current_distance + 1**)

## Try some problems
Have a go at **You, Robot** (NZIC 2019)

If you are done, try **Holiday Shopping** (NZIC 2022) Hint: Multi-source BFS

**Counting islands** can be solved with BFS. However, it does not require you to find the shortest path, but rather the number of connected components. The solution is an exercise for readers.