---
problemId: 4
title: Shulker Stack
difficulty: Hard
topics: [Greedy, Sorting]
---

Storage space on your SkyCloud island is running out, so you have decided to store all of your loot in shulker boxes and stack them into a single tall tower.

You have $N$ shulker boxes. Box $i$ has weight $W_i$ and strength $S_i$. When the boxes are stacked into a tower (one on top of another, in any order you choose), the **risk** of a box is the (total weight of all boxes strictly above it) − (its strength)

A box with a large risk is likely to break and spill your loot everywhere. The risk of the whole tower is the **maximum** risk over all boxes in it. Note that this value may be negative if every box is comfortably within its strength.

Choose the stacking order that minimises the risk of the tower, and output that minimum risk.

## Input

- The first line contains one integer $N$.
- The next $N$ lines each contain two space-separated integers $W_i$ and $S_i$.

## Output

Output one integer: the minimum possible risk of the tower.

## Constraints

- $1 ≤ N ≤ 2 × 10^5$
- $1 ≤ W_i, S_i ≤ 10^9$ for all $1 ≤ i ≤ N$

## Subtasks

- Subtask 1 (10 points): $N ≤ 8$
- Subtask 2 (15 points): All $S_i$ are equal
- Subtask 3 (15 points): All $W_i$ are equal
- Subtask 4 (60 points): No further constraints

## Sample

**Input**

```text
3
5 2
3 6
4 1
```

**Output**

```text
3
```

## Explanation

Stack the boxes, from top to bottom, as box 3, box 1, box 2.

- Box 3 is on top: risk = 0 − 1 = −1
- Box 1 has box 3 above it: risk = 4 − 2 = 2
- Box 2 has boxes 3 and 1 above it: risk = (4 + 5) − 6 = 3

The tower's risk is max(−1, 2, 3) = 3, and no other order does better.
