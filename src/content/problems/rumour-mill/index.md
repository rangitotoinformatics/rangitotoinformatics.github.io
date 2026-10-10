---
problemId: 6
title: Rumour Mill
difficulty: Easy
topics: [Graphs, Adjacency List]
---

A school has $N$ students, numbered $1$ to $N$, and $M$ friendships. Friendship $i$ is between students $U_i$ and $V_i$, and works both ways.

On day $0$, student $S$ starts a rumour. Each day after that, every student who knows the rumour tells all of their friends.

How many students know the rumour at the end of day $2$? Student $S$ counts.

## Input

- The first line contains three space-separated integers $N$, $M$ and $S$.
- The next $M$ lines each contain two space-separated integers $U_i$ and $V_i$, describing a friendship.

## Output

Output a single integer: the number of students who know the rumour at the end of day $2$.

## Constraints

- $1 \le N \le 2 \times 10^5$
- $0 \le M \le 2 \times 10^5$
- $1 \le S \le N$
- $1 \le U_i, V_i \le N$ and $U_i$ and $V_i$ are different for all $1 \le i \le M$
- No friendship is listed twice.

## Subtasks

- Subtask 1 (30 points): $N \le 1000$
- Subtask 2 (30 points): Every student has at most $10$ friends
- Subtask 3 (40 points): No further constraints

## Sample

**Input**

```text
7 7 1
1 2
1 3
2 4
3 4
4 5
5 6
6 7
```

**Output**

```text
4
```

## Explanation

On day $1$, student $1$ tells students $2$ and $3$. On day $2$, students $2$ and $3$ both tell student $4$, and student $1$ hears it again from them. So students $1$, $2$, $3$ and $4$ know the rumour. Student $4$ is only counted once.
