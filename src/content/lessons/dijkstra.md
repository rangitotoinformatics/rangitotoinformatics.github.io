---
title: Dijkstra's Algorithm
order: 3
---

Dijkstra's algorithm is a single source shortest path algorithm that works on any type of graph with non-negative edge weights.

It is actually widely applied in GPS systems today.

## The idea
The algorithm is remarkably similar to the BFS algorithm.

Recall that the BFS algorithm works by exploring nodes layer by layer. That is, all the nodes that are a distance of 1 away from the source, then distance of 2 away, then distance of 3 away, etc. This exploration order is maintained using a data structure called a queue, and guarantees that the shortest distance/path to a node is always found on its first visit.

However, a queue is insufficient in maintaining this layer by layer exploration when the edges of the graph are weighted.

## The claim
As long as we are able to explore the nodes that have the least distance first (just like we did with BFS), we can still find the shortest path.

However, the fact that edges have weights makes it more difficult. For example, a path that goes through 2 nodes may be longer than a path that goes through 5 nodes, if it goes through an edge that has a really large weight.

## The data structure
What if there was a data structure that could efficiently maintain being sorted as we add elements to it? If there is one, all we need it to do is to sort our nodes in increasing order of distance.

It turns out that there is such a data structure. In python it's called a `heapq` and in C++ it's called a `priority_queue`.

## Modifications
It turns out all we need to do is to replace our queue in our BFS into a `heapq` or a `priority_queue`.

Each element in this data structure is represented by two integers: {distance from source, node}

> [!NOTE]
> It is important to keep distance from source as the first value, because by default, our data structure sorts by the first value. We want the actual distances to be sorted, not the indices of the nodes!

## What does the code look like?
- Create visited array, adjacency list and empty `heapq`/`priority_queue`
- Add the source node into the `heapq`/`priority_queue`
- While there is something to visit in the `heapq`/`priority_queue`:
  - Take the first node and remove it from the `heapq`/`priority_queue`
  - If it has been visited skip everything below (ie `continue`)
  - Mark it as visited
  - Push all adjacent nodes **with their distances** into the `heapq`/`priority_queue`

The time complexity is $O((V + E) \log V)$, where $V$ is the number of nodes and $E$ is the number of edges. Compare it to [BFS](../bfs/#what-does-the-code-look-like)!

## Try some problems
Have a go at **Blast Off** (NZIC 2020). Hint: Make tile 0 the starting node.
If you are done, try **Enshadowed** (NZIC 2023)