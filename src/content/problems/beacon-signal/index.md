---
problemId: 4
title: Beacon Signal
difficulty: medium
topics: [graphs, bfs]
---

The SkyCloud server has $N$ villages, numbered $1$ to $N$, connected by $M$ bidirectional bridges. Bridge $i$ joins villages $U_i$ and $V_i$. Crossing any bridge takes exactly one day. It may not be possible to travel between every pair of villages.

The admins have placed beacons in $P$ distinct villages, $B_1, B_2, …, B_P$. Beacons grant powerful status effects, so every villager wants to know how far away the nearest beacon is.

For each village, output the minimum number of days needed to travel from that village to some village containing a beacon. If no beacon can be reached from a village, output $−1$ for it instead. A village that contains a beacon has distance $0$.

## Input

- The first line contains three space-separated integers $N$, $M$ and $P$.
- The next $M$ lines each contain two space-separated integers $U_i$ and $V_i$, describing a bridge.
- The last line contains $P$ space-separated integers $B_1, B_2, …, B_P$, the villages containing beacons.

## Output

Output one line containing $N$ space-separated integers. The $i$th integer is the distance from village $i$ to its nearest beacon, or $−1$ if no beacon is reachable.

## Constraints

- $1 ≤ N ≤ 2 × 10^5$
- $0 ≤ M ≤ 2 × 10^5$
- $1 ≤ P ≤ N$
- $1 ≤ U_i, V_i ≤ N$ and $U_i ≠ V_i$ for all $1 ≤ i ≤ M$
- No two bridges join the same pair of villages.
- All $B_j$ are distinct.

## Subtasks

- Subtask 1 (20 points): $N, M ≤ 1000$ and $P = 1$
- Subtask 2 (25 points): $P = 1$
- Subtask 3 (25 points): $M = N − 1$ and every village can reach every other village
- Subtask 4 (30 points): No further constraints

## Sample

**Input**

```text
7 6 2
1 2
2 3
3 4
2 5
5 6
6 3
1 4
```

**Output**

```text
0 1 1 0 2 2 -1
```

## Explanation

Villages 1 and 4 contain beacons. Village 2 is one bridge from village 1. Village 3 is one bridge from village 4. Village 5 is two bridges from village 1 (5 → 2 → 1) and village 6 is two bridges from village 4 (6 → 3 → 4). Village 7 has no bridges at all, so it cannot reach any beacon.
