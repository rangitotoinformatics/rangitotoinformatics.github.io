---
title: Introduction to DP
order: 6
description: Dynamic Programming
---

## What is DP?
Dynamic Programming (DP) is a technique that optimises a brute force by breaking it down into overlapping subproblems and avoiding repeated calculation.

## Why do DP?
Imagine you want to make \$6 with the least number of coins. Coins are in \$1, \$3 and \$5 denominations.

One way might be to greedily take the largest value coin you can each time. Indeed, the answer is $2$ coins.

However, if the \$5 coin gets changed to a \$4 coin, the same solution returns $3$, though you can achieve $2$ coins by taking two \$3 coins.

In some problems, the correct answer cannot be solved with greedy approaches, hence DP is needed to exhaust all possibilities efficiently.

## Fibonacci example

Let's say you want to find the 6th fibonacci number. Denote it as `fib(6)`.

You must find `fib(5)` and `fib(4)`.

To find `fib(5)`, you must find `fib(4)` and `fib(3)`.

This process continues until you reach `fib(1)` or `fib(2)` since they are equal to $1$ by definition of fibonacci numbers.

Below is a recursion tree which helps you visualise how the computer might go about calculating it. Notice that many calculations are repeated. E.g. `fib(3)` is calculated $3$ times. Since the answer of `fib(3)` is meant to be the same each time, there is no need to recalculate it.

![Recursion tree for fib(6), with the three fib(3) calls circled](/images/lessons/introduction-to-dp/fib-recursion-tree.svg)

## Brute force code

Let $\text{TARGET}$ be the fibonacci number you want to calculate. This means you need to calculate all fibonacci numbers from $3$ to $\text{TARGET}$.

```cpp
int fib(int i) {
    if (i == 1 || i == 2) return 1;
    return fib(i - 1) + fib(i - 2);
}
fib(TARGET);
```

`fib(1)` and `fib(2)` are $1$ by definition of fibonacci numbers. **In DP this is known as the base case.**
The base case is the simplest, smallest subproblem that can be solved directly without further calculation.

If we look at the recursion tree, each node that isn't `fib(1)` or `fib(2)` splits into $2$ child nodes.
Therefore the code runs in roughly $2^N$.

## Memoization code

If we store the answer to each `fib()` call in an array, we don't have to recalculate it each time. This is called memoization.

```cpp
int answer[TARGET+1];
int fib(int i) {
    if (i == 1 || i == 2) return 1;
    if (answer[i] != -1) return answer[i];
    answer[i] = fib(i - 1) + fib(i - 2);
    return answer[i];
}
fib(TARGET);
```

Initialise each item in `answer` to $-1$. Use the $-1$ to indicate that the value has not been calculated. If `answer[i] != -1`, you have calculated it before, so return it!

This code runs in $O(\text{TARGET})$ because each fibonacci number from $3$ to $\text{TARGET}$ is calculated exactly once.

## Tabulation code

You might also realise you can calculate the fibonacci numbers in increasing order using a for loop. This is called tabulation. It is DP because you still need to store the answers.

```cpp
int answer[TARGET+1];
answer[1] = answer[2] = 1;
for(int i = 3; i <= TARGET; i++) {
    answer[i] = answer[i - 1] + answer[i - 2];
}
```

This code also runs in $O(\text{TARGET})$ because each fibonacci number from $3$ to $\text{TARGET}$ is calculated exactly once.

## Summary

- DP is a technique to optimise a brute force approach by eliminating repeated calculations.
- The two main sub techniques are memoization ('top down', recursive) and tabulation ('bottom up', non recursive).
- Both techniques should run in the same time complexity although in practice, memoization is slightly slower because of the recursion overhead.
- Memoization is usually more intuitive.

## Try some problems
<div class="problem-list">
 
- [Marking Papers](../../problems/marking-papers)
- [Broken Stairs](../../problems/broken-stairs)
 
</div>

> [!TIP]
> - Consider the base case
> - Consider how each term in the sequence might be affected by previous terms (use the Fibonacci number example to help you!)
> - If stuck, work from brute force -> memoization -> tabulation
