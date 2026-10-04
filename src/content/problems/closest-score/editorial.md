## Subtask 1

For each query, scan all scores and keep the smallest one $\ge x$: $O(nq)$.

## Subtask 2

Sort the scores once. The scores $\ge x$ form a suffix of the sorted array, so the answer is the first element of that suffix, found by binary search (`lower_bound`). Total $O((n + q) \log n)$.
