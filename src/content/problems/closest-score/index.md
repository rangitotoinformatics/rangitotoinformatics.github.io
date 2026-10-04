---
id: P0003
title: Closest Score
difficulty: medium
topics: [binary search, sorting]
lessons: [binary-search]
source: { name: Rangitoto Informatics }
timeLimit: 1
memoryLimit: 256
---

There are $n$ scores $s_1, \dots, s_n$ (not necessarily sorted). For each of $q$ queries $x$, print the smallest score that is at least $x$, or `-1` if there is none.

## Input

The first line contains $n$ and $q$. The second line contains $s_1, \dots, s_n$. The next line contains the $q$ queries.

## Output

Print $q$ lines, one answer per query.

## Constraints

- $1 \le n, q \le 2 \cdot 10^5$
- $0 \le s_i, x \le 10^9$

## Subtasks

1. (30%) $n, q \le 1000$
2. (70%) No further constraints.

## Sample

Input
```
4 3
7 2 9 4
3 9 10
```

Output
```
4
9
-1
```
