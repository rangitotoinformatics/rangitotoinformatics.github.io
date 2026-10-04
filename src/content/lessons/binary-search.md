---
title: Binary search
order: 3
topics: [binary search, sorting]
---

Find a boundary in a sorted (monotonic) sequence in $O(\log n)$.

## Idea

Keep a range $[lo, hi)$ that contains the answer and halve it each step.

```cpp
// first index i with a[i] >= x, or n if none
int lo = 0, hi = n;
while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (a[mid] >= x) hi = mid;
    else lo = mid + 1;
}
```

The standard library does the same: `lower_bound(a.begin(), a.end(), x)`.

## Binary search on the answer

If "can we achieve $k$?" is monotonic in $k$, binary search on $k$ and check each candidate.
