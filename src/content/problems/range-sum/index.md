---
id: P0001
title: Range Sum
difficulty: easy
topics: [prefix sums]
lessons: [prefix-sums]
source: { name: Rangitoto Informatics }
timeLimit: 1
memoryLimit: 256
---

You are given $n$ integers $a_1, \dots, a_n$ and $q$ queries. For each query $(l, r)$, print $a_l + \dots + a_r$.

## Input

The first line contains $n$ and $q$. The second line contains $a_1, \dots, a_n$. Each of the next $q$ lines contains $l$ and $r$.

## Output

For each query, print the sum on its own line.

## Constraints

- $1 \le n, q \le 2 \cdot 10^5$
- $|a_i| \le 10^9$
- $1 \le l \le r \le n$

## Subtasks

1. (40%) $n, q \le 1000$
2. (60%) No further constraints.

## Sample

Input
```
5 3
1 2 3 4 5
1 5
2 3
4 4
```

Output
```
15
5
4
```
