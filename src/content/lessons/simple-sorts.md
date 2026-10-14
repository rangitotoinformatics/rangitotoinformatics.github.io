---
title: Simple Sorts
order: 9
description: Bubble, selection and insertion sort
---

Sorting means putting a list in order, usually smallest to largest. Many problems become much easier once the input is sorted.

First, here is some key vocabulary:
- **In-place:** the algorithm only needs $O(1)$ extra memory to sort the original list.
- **Stable:** equal values stay in the same order they started in. This matters when you sort records by one field, e.g. sorting students by score, where students with the same score should keep their original order.

## Bubble sort
Go through the list and swap every pair of neighbours that is in the wrong order. After one pass, the largest value has "bubbled" to the end. Repeat for the rest of the list.

If a whole pass makes no swaps, the list is already sorted, so we can stop early.

![Bubble sort animation](/images/lessons/simple-sorts/bubble-sort.svg)

<details>
<summary>Python implementation</summary>

```python
def bubble_sort(a):
    n = len(a)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i):  # the last i values are already in place
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                swapped = True
        if not swapped:  # no swaps means the list is sorted
            break
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
void bubble_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
```
</details>

**Cost:**
- **Worst case** (reverse order): the passes make $(n-1) + (n-2) + \ldots + 1 = \frac{n(n-1)}{2} = O(n^2)$ comparisons.
- **Best case** (already sorted): there is one pass of $n - 1$ comparisons with no swaps and then an early return, so $O(n)$.
- In-place and stable, because it only swaps neighbours that are strictly out of order.

> [!NOTE]
> Without the `swapped` check, bubble sort will not return early on a sorted list, therefore costing a fixed $O(n^2)$ each time. 

## Selection sort
Find the smallest value and swap it to the front. Then find the smallest of the rest and swap it to position $1$, and so on.

![Selection sort animation](/images/lessons/simple-sorts/selection-sort.svg)


<details>
<summary>Python implementation</summary>

```python
def selection_sort(a):
    n = len(a)
    for i in range(n - 1):
        smallest = i
        for j in range(i + 1, n):
            if a[j] < a[smallest]:
                smallest = j
        a[i], a[smallest] = a[smallest], a[i]
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
void selection_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[smallest]) smallest = j;
        }
        swap(a[i], a[smallest]);
    }
}
```
</details>

**Cost:**
- Always $\frac{n(n-1)}{2} = O(n^2)$ comparisons, even on a sorted list.
- At most $n - 1$ swaps. That's useful when moving data is much more expensive than comparing it.
- In-place, but not stable. E.g., $[2_a, 2_b, 1]$: $2_a$ is swapped with $1$ in the first step, giving $[1, 2_b, 2_a]$.

## Insertion sort
Build a sorted section at the front, one value at a time. Take the next value and slide it left until the value before it is smaller or equal. This is how most people sort a hand of cards.

![Insertion sort animation](/images/lessons/simple-sorts/insertion-sort.svg)


<details>
<summary>Python implementation</summary>

```python
def insertion_sort(a):
    for i in range(1, len(a)):
        value = a[i]
        j = i - 1
        while j >= 0 and a[j] > value:  # shift bigger values right
            a[j + 1] = a[j]
            j -= 1
        a[j + 1] = value
```
</details>

<details>
<summary>C++ implementation</summary>

```cpp
void insertion_sort(vector<int>& a) {
    for (int i = 1; i < (int)a.size(); i++) {
        int value = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > value) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = value;
    }
}
```
</details>

**Cost:**
- **Worst case** (sorted descending): every value slides all the way to the front, so $\frac{n(n-1)}{2}$ comparisons or $O(n^2)$.
- **Best case** (sorted ascending): one comparison per value, so $n - 1$ comparisons or $O(n)$.
- On a nearly sorted list, each value only slides a short distance, so it is close to $O(n)$. This is why real-world sorts, like Python's, use insertion sort for small or nearly sorted sections.
- In-place and stable, because `a[j] > value` stops at equal values instead of jumping over them.

## Comparison
![Comparison diagram](/images/lessons/simple-sorts/comparison.svg)

## Thinking questions
1. A list of $1000$ items is already sorted. How many exact comparisons does each sort above make? 
2. Give a list of $4$ numbers where insertion sort makes the maximum number of comparisons. What does the list look like, and how many comparisons will be made?
3. A school stores $10\,000$ student records, already sorted by name. Each week about $5$ new students are added to the end. Which sort would you use to re-sort the list, and why? Compare it with one alternative.

<details>
<summary>Answers</summary>

1. Bubble sort: $999$, Selection sort: $499500$, Insertion sort: $999$.
2. Any list that is *strictly decreasing*, e.g, $[7, 6, 2, 0]$. $6$ comparisons will be made.
3. Insertion sort. This is because all items up to the last $5$ have already been sorted. Thus, the algorithm will only have to move those $5$ items into place, costing at most $5N$ operations. Alternatively, bubble sort can achieve a similar result if you start the passes from the end of the list and bubble them to the front. Compared to selection sort, though, both algorithms are significantly more efficient. This is because cannot tell if a list is already sorted. It must always recalculate the item that goes in each position, costing $N^2$ operations each week.
</details>
