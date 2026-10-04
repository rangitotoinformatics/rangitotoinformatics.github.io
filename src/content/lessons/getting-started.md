---
title: Getting started
order: 1
topics: [basics]
---

## How judging works

You submit source code. The judge compiles it, runs it on hidden tests, and compares your output with the expected output.

| Verdict | Meaning |
|---|---|
| AC | Accepted |
| WA | Wrong answer |
| TLE | Time limit exceeded |
| RE | Runtime error (crash, out-of-bounds access) |
| CE | Compile error |

## Template

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << n << '\n';
}
```

Use `'\n'` instead of `endl`: `endl` flushes the output each time and is slow.

## Complexity

A judge runs roughly $10^8$ simple operations per second. Use the constraints to pick an algorithm:

| $n$ | Target |
|---|---|
| $\le 10$ | $O(n!)$ |
| $\le 20$ | $O(2^n)$ |
| $\le 500$ | $O(n^3)$ |
| $\le 5000$ | $O(n^2)$ |
| $\le 10^6$ | $O(n \log n)$ |
| $\le 10^{8}$ | $O(n)$ |

## Overflow

`int` holds up to about $2 \cdot 10^9$. Use `long long` (up to about $9 \cdot 10^{18}$) for sums and products.
