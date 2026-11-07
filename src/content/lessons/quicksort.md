---
title: Quicksort
order: 11
---

Quicksort is also divide and conquer, but it does the hard work **before** recursing instead of after (like merge sort):
1. Pick a **pivot** value.
2. **Partition:** rearrange the list so everything smaller than the pivot comes before it, and everything else comes after. The pivot is now in its final position.
3. Recursively sort the part before the pivot and the part after it.


## Partitioning
A simple method uses the **last** value as the pivot:
- Keep an index $i$. Everything before $i$ is smaller than the pivot.
- Scan $j$ from left to right. When $a[j]$ is smaller than the pivot, swap it to position $i$ and increment $i$.
- At the end, swap the pivot into position $i$.

Partitioning $[3, 6, 1, 5, 2, 4]$ with pivot $4$:
![Partitioning](/images/lessons/quicksort/partition.svg)

Now $[3, 1, 2]$ and $[6, 5]$ are sorted separately. Partitioning makes $N - 1$ comparisons, so it is $O(N)$.

<details>
<summary>Python implementation</summary>

```python
import random

def quicksort(a, lo, hi):  # sorts a[lo..hi] inclusive
    if lo >= hi:
        return
    r = random.randint(lo, hi)
    a[r], a[hi] = a[hi], a[r]         # random pivot, moved to the end
    pivot = a[hi]
    i = lo
    for j in range(lo, hi):
        if a[j] < pivot:
            a[i], a[j] = a[j], a[i]
            i += 1
    a[i], a[hi] = a[hi], a[i]         # pivot is now in its final place
    quicksort(a, lo, i - 1)
    quicksort(a, i + 1, hi)

# call it with: quicksort(a, 0, len(a) - 1)
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
mt19937 rng(random_device{}()); // for generating random pivot

void quicksort(vector<int>& a, int lo, int hi) {  // sorts a[lo..hi] inclusive
    if (lo >= hi) return;
    int r = uniform_int_distribution<int>(lo, hi)(rng); 
    swap(a[r], a[hi]); // moves random pivot to the end
    int pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (a[j] < pivot) swap(a[i++], a[j]);
    }
    swap(a[i], a[hi]); // pivot is now in its final place
    quicksort(a, lo, i - 1);
    quicksort(a, i + 1, hi);
}

// call it with: quicksort(a, 0, a.size() - 1);
```
</details>

## Cost
How fast quicksort is depends on how evenly the pivot splits the list.
- **Good pivots:** if the pivot lands near the middle, the list halves each time. That gives about $\log_2 N$ levels with $O(N)$ partitioning work on each, so $O(N \log N)$. This is also the **average** case.
- **Bad pivots:** if the pivot is always the smallest or largest value, one side is empty and the other has $N - 1$ values. That gives $(N-1) + (N-2) + \ldots + 1 = \frac{N(N-1)}{2}$ comparisons, so $O(N^2)$.

> [!WARNING]
> Always picking the last value as the pivot hits the worst case on a list that's **already sorted**, which is very common in real data. Picking a random pivot makes the $O(N^2)$ case extremely unlikely for any input.

- **Space:** it is in-place, but the recursion uses $O(\log N)$ stack space on average, and $O(N)$ in the worst case. Python's recursion limit (about $1000$) can be hit in the worst case.
- **Not stable:** the long-distance swaps can reorder equal values.
- **Many equal values:** with this partition, a list where every value is the same is also $O(N^2)$, since nothing is smaller than the pivot. A **three-way partition** (smaller / equal / larger) fixes this.

## Quicksort vs merge sort
![Quicksort vs merge sort](/images/lessons/quicksort/quicksort-vs-merge-sort.svg)

Quicksort is often faster in practice, even though its worst case is worse. It works in place and scans memory in order, which suits how computers cache data. Merge sort is the safer choice when you need stability or a guaranteed worst case.

Many languages offer sorting algorithm that are hybrids of these algorithms.\
C++ uses **introsort**: quicksort that switches to heapsort if the recursion gets too deep (i.e., the array is mostly sorted).\
Python and Java use **timsort**: a stable algorithm combining merge sort and insertion sort.

## Exam-style questions
1. Show the partition steps for $[7, 2, 9, 4, 3, 8, 5]$ using the last value as the pivot.
2. How many comparisons does quicksort with a last-value pivot make on a sorted list of $1000$ values? Explain why.
3. Explain why a random pivot doesn't change the worst-case complexity, but still makes quicksort safe to use in practice.
4. You need to sort $10^7$ bank transactions by amount, keeping transactions with the same amount in time order. Would you choose quicksort or merge sort? Justify your choice.
