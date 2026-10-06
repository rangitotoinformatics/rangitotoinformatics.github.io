---
problemId: 1
title: Marking Papers
difficulty: Easy
topics: [Implementation]
---

Mr Gardiner needs to mark $N$ papers. Last year, he threw the papers down a staircase and gave the ones that landed further higher marks. However, there are too many papers this year, so he's asked you for your help.

The first and second students should get grades $6$ and $7$ respectively. Each student after that should get the product of the previous two students' grades. For example, the third student should get a grade of $6 \times 7 = 42$.

Additionally, Mr Gardiner doesn't want students to have grades that are too high (to minimise suspicion), so the grades must be calculated modulo $1,000,001,677$. Mr Gardiner recommends you apply the modulo after each addition or multiplication operation.

After applying modulo $1,000,001,677$ to each grade, Mr Gardiner would like to know the first index of a student with the highest grade.

**Note:** <br>
If you are using a type sensitive language like C++, Java, or C then make sure to use a 64 bit integer type to avoid integer overflow. 64-bit integer types include long long for C or C++, and long for C# or Java. <br>
Python users should include the following snippet in the beginning of their code if they are receiving `RecursionError: maximum recursion depth exceeded`<br>
`import sys` <br>
`sys.setrecursionlimit(2000000)`

### INPUT
The first and only line contains a single integer, $N$.

### OUTPUT
Output the first index of a student with the highest grade after applying modulo $1,000,001,677$ to each grade.

### CONSTRAINTS
- $3 \leq N \leq 1,000,000$

### SUBTASKS
- **Subtask 1 (30%)**: $3 \leq N \leq 20$
- **Subtask 2 (30%)**: $3 \leq N \leq 100,000$
- **Subtask 3 (40%)**: $3 \leq N \leq 1,000,000$
