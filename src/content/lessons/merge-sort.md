---
title: Merge Sort
order: 10
---

Merge sort uses **divide and conquer**:
1. **Divide:** split the list into two halves.
2. **Conquer:** recursively call merge sort on each half.
3. **Combine:** merge the sorted lists in the two halves into one sorted list.

The base case is a list with $0$ or $1$ items. In this case, it is already sorted.

## Merging
Assume we already have two sorted lists $X$ and $Y$ of sizes $x$ and $y$, and our task now is to merge them into one sorted list of size $x + y$ efficiently. We can utilise a two-pointers approach, using one pointer for each list. Let $X$ be the list that came from the left half, $Y$ be the list from the right half, and call the pointers $i$ and $j$. If $X_i < Y_j$, then we should take $X_i$ and increment $i$, and vice versa. Once all elements in one list have been added, we can add the remaining elements in the other list to the end.

> [!NOTE]
> If $X_i = Y_j$, then it doesn't matter which element we take. However, if we want our sort to be stable, we should take the element from the left list. This keeps equal values in their original order.

For each merge we must iterate through both lists, so the time complexity is $O(x + y)$.

![Merging two lists](/images/lessons/merge-sort/merge.svg)


## The whole algorithm
![Merge sort tree](/images/lessons/merge-sort/merge-sort-tree.svg)

<details>
<summary>Python implementation</summary>

```python
def merge_sort(a):
    if len(a) <= 1:
        return a
    mid = len(a) // 2
    left = merge_sort(a[:mid])
    right = merge_sort(a[mid:])

    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:  # <= keeps it stable
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])  # one of these is empty
    result.extend(right[j:])
    return result
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
// sorts a[lo..hi), using tmp as extra space
void merge_sort(vector<int>& a, vector<int>& tmp, int lo, int hi) {
    if (hi - lo <= 1) return;
    int mid = (lo + hi) / 2;
    merge_sort(a, tmp, lo, mid);
    merge_sort(a, tmp, mid, hi);

    int i = lo, j = mid, k = lo;
    while (i < mid && j < hi) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j < hi) tmp[k++] = a[j++];
    for (int x = lo; x < hi; x++) a[x] = tmp[x];
}

/* call it with:
vector<int> tmp(a.size());
merge_sort(a, tmp, 0, a.size());
*/
```
</details>

## Cost
**Time complexity:**
To analyse the time complexity of this algorithm, we must take a look at it from a precise perspective. Let's say we are sorting a list of size $N$, where $N$ is a power of $2$. Our algorithm repeatedly halves our list into smaller lists and rebuilds them by merging. Each time we merge two lists, the size of the resulting list is doubled. For example, merging two lists of size $1$ results in a list of size $2$; merging two lists of size $2$ results in a list of size $4$. This continues until the size of the list reaches $N$. We can group all merges that result in the same list size into a 'layer'. The layer that merges lists into size $x$ will have $\frac{N}{x}$ resulting lists. Recall that the time complexity of merging two lists is bounded by the size of the resulting list. This means that each merge will cost $x$ operations, for a total of $x \cdot \frac{N}{x} = N$ operations at that layer. Thus, the total number of operations at each layer is exactly $N$. Since the size of the lists double in size for each layer, there can only be $\log N$ layers before we reach a list of size $N$. Thus the overall complexity is $O(N \log N)$.

For $N$ (list sizes) that are not perfect powers of two, the number of layers is $\lceil \log N \rceil$. However, the number of operations at each layer remains exactly at $N$. In the worst, average and best case, the complexity stays the same regardless of how the elements are initially ordered.

> [!IMPORTANT]
> Here, all $\log $s should be evaluated in base $2$, that is, as $\log_{2}$.

![Merge sort layers](/images/lessons/merge-sort/merge-sort-layers.svg)

**Space Complexity:** When two lists are merged, the resulting list must be stored before it can be rewritten in the original list. In the worst case, this costs $O(N)$ *auxiliary space*. Thus, merge sort is **not in-place**. Additionally, recursion adds $O(\log N)$ memory for the *call stack*.

*Auxiliary space* is the extra or temporary space used by an algorithm, not including the memory taken up by the original input itself.<br>
A *call stack* is a specialised data structure that tracks active subroutines. During recursion, calls that have not yet been finished wait on the *call stack* until the calls it made have returned. 

## Thinking questions
1. A device has very little spare memory. Would merge sort be a good choice? Suggest an alternative and justify it.
2. **Challenge:** an *inversion* is a pair $i < j$ with $a[i] > a[j]$. Change merge sort to count the inversions in a list in $O(N \log N)$. (Hint: when you take from the right list, how many left values does it jump over?)
