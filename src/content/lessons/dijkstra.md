---
title: Dijkstra's Algorithm
order: 3
---

Dijkstra's algorithm is a single-source shortest-path algorithm that works on any type of graph with non-negative edge weights.

## The idea
The algorithm is built upon the BFS algorithm.

Recall that the BFS algorithm works by exploring nodes layer by layer. That is, all the nodes that are a distance of 1 away from the source, then distance of 2 away, then distance of 3 away, etc. This exploration order is maintained using a data structure called a queue, and guarantees that the shortest distance/path to a node is always found on its first visit.

However, a queue is insufficient in maintaining this layer by layer exploration when the edges of the graph are weighted.

## The claim
As long as we are able to explore the nodes that have the least distance first (just like we did with BFS), we can still find the shortest path.

However, the fact that edges have weights makes it more difficult. For example, a path that goes through 2 nodes may be longer than a path that goes through 5 nodes, if it goes through an edge that has a really large weight.

## The data structure
What if there were a data structure that could remain sorted as we added elements to it? If there is one, all we need it to do is to sort our nodes in increasing order of distance.

It turns out that there is such a data structure. In Python it's called a `heapq` and in C++ it's called a `priority_queue`.


## What does the code look like?
- Create boolean visited array, distance array initialised to infinity, adjacency list and empty `heapq`/`priority_queue`
- Set the source's distance to `0` and add `(0, source)` to the `heapq`/`priority_queue`
- While there is something to visit:
  - Take the pair with the smallest distance and remove it
  - If the node has already been visited, skip everything below
  - Mark the node as visited
  - For each adjacent node:
    - Calculate `current_distance + edge_weight`
    - If this is smaller than adjacent node's best distance:
      - Update its best distance
      - Push the updated pair

The time complexity is $O((V + E) \log V)$, where $V$ is the number of nodes and $E$ is the number of edges. 

Compare it to [BFS](../bfs/#what-does-the-code-look-like)! It may seem like a lot more code, but most of it comes from handling a weighted graph. Some Dijkstra implementations are only 1-2 lines longer than BFS implementations! 

> [!NOTE]
> Each element in this data structure is a pair: `(distance from source, node)`.
> It is important to keep distance from source as the first value, because by default, our data structure sorts by the first value. We want the actual distances to be sorted, not the indices of the nodes!

> [!IMPORTANT]
> C++ `priority_queue` sorts by largest element first. This means we must use `priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>` instead of `priority_queue<pair<int,int>>`.

![Dijkstra animation on a weighted graph](/images/lessons/dijkstra/dijkstra.svg)

## Try some problems
<div class="problem-list">
 
- [Blast Off (NZIC 2020)](https://train.nzoi.org.nz/problems/1133)
- [Enshadowed (NZIC 2023)](https://train.nzoi.org.nz/problems/1306)
 
</div>
