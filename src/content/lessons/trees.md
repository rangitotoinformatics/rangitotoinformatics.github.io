---
title: Trees
order: 5
description: Very cool type of graph
---

A tree is a connected, undirected, acylic graph that also functions as a hierarchical data structure. A tree has:
- $N$ nodes and exactly $N-1$ edges.
- Exactly one path between any pair of nodes.

## Parts of a tree
- Trees are **rooted** at the topmost node.
- Every node except the root has exactly one **parent**.
- Nodes can have zero, one or multiple **children** below them.
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

## Lines
A line is a special type of tree where:
- The two endpoint nodes are connected to exactly one node.
- All other nodes are connected to exactly two other nodes. 

The resulting graph looks like a line!

Can you see how there are $N-1$ edges if there are $N$ nodes?
![A line of 4 nodes: 1 - 2 - 3 - 4](/images/lessons/trees/line.svg)
