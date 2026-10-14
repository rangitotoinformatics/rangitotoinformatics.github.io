---
problemId: 8
title: Broken Stairs
difficulty: Medium
topics: [DP]
---

You are standing at the bottom of a staircase, on step $0$, and want to reach the top, step $N$. In one move you can climb up exactly $A_1$, $A_2, \ldots, or A_K$ steps.

Unfortunately, $B$ of the steps, $C_1, C_2, \ldots, C_B$, are broken, and you must never land on one.

How many different sequences of moves take you from step $0$ to exactly step $N$? Since the answer can be very large, output it modulo $1\,000\,000\,007$.

**NOTE:**
<br>C++ users should use 64-bit integer types such as `long long` to prevent integer overflow.

## Input

- The first line contains three space-separated integers $N$, $K$ and $B$.
- The second line contains $K$ space-separated integers $A_1, A_2, \ldots, A_K$.
- The third line contains $B$ space-separated integers $C_1, C_2, \ldots, C_B$. If $B = 0$, this line is empty.

## Output

Output a single integer: the number of ways to reach step $N$, modulo $1\,000\,000\,007$.

## Constraints

- $1 \le N \le 10^5$
- $1 \le K \le 100$
- $1 \le A_i \le N$, and all $A_i$ are distinct
- $0 \le B \le N$
- $1 \le C_j \le N$, and all $C_j$ are distinct

## Subtasks

- Subtask 1 (20 points): $N \le 20$
- Subtask 2 (20 points): $K = 2$, $A = \{1, 2\}$ and $B = 0$
- Subtask 3 (30 points): $B = 0$
- Subtask 4 (30 points): No further constraints

## Sample

**Input**

```text
5 2 1
1 2
3
```

**Output**

```text
2
```

## Explanation

Step $3$ is broken. The two ways are $0 → 1 → 2 → 4 → 5$ and $0 → 2 → 4 → 5$.

