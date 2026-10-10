---
problemId: 7
title: Team Sizes
difficulty: Medium
topics: [Graphs, Trees, DFS]
---

A company has $N$ employees, numbered $1$ to $N$. Employee $1$ is the CEO. Every other employee has exactly one direct manager, so the company forms a tree rooted at employee $1$.

You are not told who manages whom. Instead, you are given the $N - 1$ pairs of employees $U_i$ and $V_i$ where one of them directly manages the other, in no particular order.

The team of an employee is that employee together with everyone they manage directly or indirectly (their subtree). For each employee, find the size of their team.

**NOTE:**
<br>Python users should include the following snippet in the beginning of their code if they are receiving `RecursionError: maximum recursion depth exceeded`

```python
import sys
sys.setrecursionlimit(2000000)
```

## Input

- The first line contains a single integer $N$.
- The next $N - 1$ lines each contain two space-separated integers $U_i$ and $V_i$: one of them directly manages the other.

## Output

Output one line containing $N$ space-separated integers. The $i$th integer is the size of employee $i$'s team.

## Constraints

- $1 \le N \le 2 \times 10^5$
- $1 \le U_i, V_i \le N$ and $U_i$ and $V_i$ are different for all $1 \le i \le N - 1$
- The pairs form a tree.

## Subtasks

- Subtask 1 (20 points): $N \le 1000$
- Subtask 2 (30 points): The pairs are $(1, 2), (2, 3), \ldots, (N - 1, N)$ in that order (the tree is a line)
- Subtask 3 (50 points): No further constraints

## Sample

**Input**

```text
6
2 1
3 1
4 3
3 5
6 5
```

**Output**

```text
6 1 4 1 2 1
```

## Explanation

Employee $1$ manages employees $2$ and $3$. Employee $3$ manages $4$ and $5$, and employee $5$ manages $6$. Employee $3$'s team is $\{3, 4, 5, 6\}$, so its size is $4$. Employees $2$, $4$ and $6$ are leaves, so their teams only contain themselves.
