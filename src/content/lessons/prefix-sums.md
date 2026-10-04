---
title: Prefix sums
order: 2
topics: [prefix sums, arrays]
---

Answer "sum of $a_l, \dots, a_r$" in $O(1)$ after $O(n)$ precomputation.

## Idea

Define $p_0 = 0$ and $p_i = a_1 + \dots + a_i$. Then

$$
a_l + \dots + a_r = p_r - p_{l-1}.
$$

```cpp
vector<long long> p(n + 1, 0);
for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
// sum of a[l..r]
long long s = p[r] - p[l - 1];
```

## Pitfalls

- Use 1-indexing so $p_{l-1}$ is valid when $l = 1$.
- Sums overflow `int` quickly; use `long long`.
