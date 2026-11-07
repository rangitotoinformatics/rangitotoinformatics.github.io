---
title: Sorting in Contests
order: 12
description: Built-in sorts, custom orders and counting sort
---

In contests you almost never write your own sort. The built-in ones are $O(N \log N)$, well tested and fast. What matters is knowing how to sort by what you need, and what sorting makes easy.

## Built-in sorts
<details open>
<summary>Python</summary>

```python
a = [5, 2, 9, 1]
a.sort()                       # sorts a in place: [1, 2, 5, 9]
b = sorted(a, reverse=True)    # returns a new list: [9, 5, 2, 1]
```

Python's `sort` is **stable**.
</details>

<details open>
<summary>C++</summary>

```cpp
vector<int> a = {5, 2, 9, 1};
sort(a.begin(), a.end());                  // 1 2 5 9
sort(a.begin(), a.end(), greater<int>());  // 9 5 2 1
```

C++ `sort` is **not stable**. Use `stable_sort` if you need equal values to keep their order.
</details>

## Sorting by your own order
Say we want students sorted by score from high to low, and by name from A to Z when scores are equal.

<details open>
<summary>Python</summary>

Give `key` a function that turns each item into the value to sort by. Tuples are compared element by element, and a minus sign reverses a number's order.

```python
students = [("Mia", 85), ("Ari", 92), ("Leo", 85)]
students.sort(key=lambda s: (-s[1], s[0]))
# [('Ari', 92), ('Leo', 85), ('Mia', 85)]
```
</details>

<details open>
<summary>C++</summary>

Give `sort` a comparator that returns `true` if `x` should come **before** `y`.

```cpp
vector<pair<string, int>> students = {{"Mia", 85}, {"Ari", 92}, {"Leo", 85}};
sort(students.begin(), students.end(), [](const pair<string, int>& x, const pair<string, int>& y) {
    if (x.second != y.second) return x.second > y.second;  // higher score first
    return x.first < y.first;                              // then name A to Z
});
```

Pairs and tuples already sort element by element, so normally `sort` on a `vector<pair<int, int>>` sorts by `first`, then by `second`.
</details>

> [!CAUTION]
> In C++, a comparator must return `false` when two items are equal. Never use `<=` or `>=` in one. Breaking this rule is undefined behaviour: the sort can give wrong results or even crash.

## Counting sort
If every value is an integer from $0$ to $K$, and $K$ isn't too large, you can sort without comparing at all. Count how many times each value appears, then write the values out in order. This takes $O(N + K)$ time and $O(K)$ extra space. It beats $O(N \log N)$ when $K$ is small, e.g. sorting $10^6$ exam marks out of $100$.

<details>
<summary>Python implementation</summary>

```python
def counting_sort(a, K):  # every value is in 0..K
    count = [0] * (K + 1)
    for x in a:
        count[x] += 1
    result = []
    for v in range(K + 1):
        result.extend([v] * count[v])
    return result
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
vector<int> counting_sort(const vector<int>& a, int K) {  // every value is in 0..K
    vector<int> count(K + 1, 0);
    for (int x : a) count[x]++;
    vector<int> result;
    for (int v = 0; v <= K; v++) {
        for (int c = 0; c < count[v]; c++) result.push_back(v);
    }
    return result;
}
```
</details>

## What sorting makes easy
- **Equal values end up next to each other:** counting distinct values or finding duplicates is one pass.
- **Greedy choices:** many greedy algorithms start with "take the smallest first" or "take whatever finishes earliest".
- **Two pointers:** in a sorted list, one pointer at each end can find pairs with a given sum in $O(N)$.
- **Binary search:** finding a value or the first value $\ge x$ in $O(\log N)$, with `bisect` in Python or `lower_bound` in C++.

## Example: Distinct Numbers
Given $1 \le N \le 2 \times 10^5$ integers, how many different values are there?

After sorting, equal values are next to each other, so the answer is $1$ plus the number of positions where a value differs from the one before it. Sorting is $O(N \log N)$, and the scan is $O(N)$.

<details>
<summary>Python implementation</summary>

```python
N = int(input())
a = sorted(map(int, input().split()))
answer = 1
for i in range(1, N):
    if a[i] != a[i - 1]:
        answer += 1
print(answer)
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    int answer = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] != a[i - 1]) answer++;
    }
    cout << answer << "\n";
}
```
</details>

## Try some problems
<div class="problem-list">

- [Distinct Numbers (CSES)](https://cses.fi/problemset/task/1621)
- [Apartments (CSES)](https://cses.fi/problemset/task/1084)
- [Ferris Wheel (CSES)](https://cses.fi/problemset/task/1090)
- [Restaurant Customers (CSES)](https://cses.fi/problemset/task/1619)
- [Movie Festival (CSES)](https://cses.fi/problemset/task/1629)

</div>

> [!TIP]
> Each of these is "sort first, then something simple". If you're stuck, ask yourself what sorting the input makes easy.
