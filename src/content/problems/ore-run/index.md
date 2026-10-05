---
problemId: 3
title: Ore Run
difficulty: medium
topics: [dp, grids]
---

You have discovered a huge underground cave beneath your SkyCloud island. From above, the cave looks like a grid with $N$ rows and $M$ columns. Rows are numbered $1$ to $N$ from top to bottom and columns $1$ to $M$ from left to right.

Each cell of the grid is one of the following:

- a digit from $0$ to $9$: a safe cell containing that many ores;
- '`#`' (without the quotes): a lava pool, which you cannot enter.

You start in the top-left cell (row $1$, column $1$) and want to reach the bottom-right cell (row $N$, column $M$). Because your pickaxe is enchanted with a very strange curse, from any cell you can only move **one cell to the right** or **one cell down**. You collect every ore in every cell you visit, including the starting and ending cells.

What is the maximum total number of ores you can collect on a trip from the top-left cell to the bottom-right cell? If it is impossible to reach the bottom-right cell, output $−1$.

## Input

- The first line contains two space-separated integers $N$ and $M$.
- The next $N$ lines each contain a string of exactly $M$ characters, each of which is a digit from $0$ to $9$ or '`#`', describing the cave.

## Output

Output one integer: the maximum number of ores that can be collected, or $−1$ if the bottom-right cell cannot be reached.

## Constraints

- $1 ≤ N, M ≤ 1000$
- The top-left and bottom-right cells are never lava.

## Subtasks

- Subtask 1 (15 points): $N, M ≤ 10$ and there is no lava
- Subtask 2 (25 points): There is no lava
- Subtask 3 (20 points): $N = 2$
- Subtask 4 (40 points): No further constraints

## Sample 1 explanation

An optimal path is (1,1) → (2,1) → (2,2) → (2,3) → (2,4) → (3,4), collecting 3 + 1 + 5 + 2 + 1 + 9 = 21 ores. Going along the top row is impossible because (1,2) is lava. Note that there may be more than one optimal path.
