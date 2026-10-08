## Subtask 1

We can use a recursive function with a parameter $k$, where $k$ is the student whose grade we are currently calculating. The function should return a single integer.

It should terminate at $k = 1$ or $k = 2$, returning $6$ and $7$ respectively, since these grades are already known. For all other values of $k$, we recursively call the function for $k-1$ and $k-2$, multiply the results, and apply the modulo.

We can store the calculated grades in an array and loop through it at the end to find the first index of the student with the highest grade. The overall time complexity is $O(2^N)$.

## Subtask 2
Extending our solution from **Subtask 1**, we can return student $k$'s grade immediately if it has already been calculated. This avoids repeating the same calculations.

The overall time complexity of this solution is $O(N)$.

## Full solution
We can use a `for` loop to calculate the grades from student $3$ to student $N$. While calculating them, we keep track of the largest grade and its index. We only update the answer when a **strictly larger** grade is found, so that ties keep the earliest index.

The overall time complexity is $O(N)$ and the auxiliary space complexity is $O(1)$.

Note that an auxiliary space complexity of $O(N)$ can be achieved by caching students' grades (as seen in **Subtask 2**), which may be sufficient to solve this problem.