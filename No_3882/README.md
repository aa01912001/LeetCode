Problem Number: 3882. Minimum XOR Path in a Grid

Difficulty: `Medium`

## Problem Description

You are given a 2D integer array `grid` of size `m * n`.[cite: 5]

You start at the **top-left** cell `(0, 0)` and want to reach the **bottom-right** cell `(m - 1, n - 1)`.[cite: 5]

At each step, you **may** move either **right or down**.[cite: 5]

The **cost** of a path is defined as the **bitwise XOR** of all the values in the cells along that path, **including** the start and end cells.[cite: 5]

Return the **minimum** possible XOR value among all valid paths from `(0, 0)` to `(m - 1, n - 1)`.[cite: 5]


**Example 1:**
```
Input: grid = [[1,2],[3,4]]

Output: 6

Explanation:

There are two valid paths:

    (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
    (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6

The minimum XOR value among all valid paths is 6.
```
**Constraints:**

- `1 <= m == grid.length <= 1000`
- `1 <= n == grid[i].length <= 1000`
- `m * n <= 1000`
- `0 <= grid[i][j] <= 1023`

**Intuition:**

We can use dynamic programming to compute all possible accumulated XOR values for each cell. Given that m * n <= 1000, the number of unique XOR values per cell remains small, ensuring high efficiency.