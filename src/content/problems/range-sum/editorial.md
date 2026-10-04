## Subtask 1

Loop from $l$ to $r$ for each query: $O(nq) \le 10^6$ operations.

## Subtask 2

$O(nq)$ is now $4 \cdot 10^{10}$, too slow. Precompute prefix sums $p_i = a_1 + \dots + a_i$; each query is $p_r - p_{l-1}$, giving $O(n + q)$.

Sums reach $2 \cdot 10^{14}$, so use `long long`.
