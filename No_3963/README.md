Problem Number: 3963. Create Grid With Exactly One Path

Difficulty: `Easy`

## Problem Description

You are given two integers `m` and `n`, representing the number of rows and columns of a grid.

Construct **any** `m x n` grid consisting only of the characters `'.'` and `'#'`, where:

* `'.'` represents a free cell.
* `'#'` represents an obstacle cell.

A **valid path** is a sequence of free cells that:

* Starts at the top-left cell `(0, 0)`.
* Ends at the bottom-right cell `(m - 1, n - 1)`.
* Moves only:
  * Right, from `(i, j)` to `(i, j + 1)`, or
  * Down, from `(i, j)` to `(i + 1, j)`.

Return any grid such that there is **exactly one valid path** from the top-left cell to the bottom-right cell.


**Example 1:**
![圖片](https://hackmd.io/_uploads/HJUkSWR3Gg.png)
```
Input: m = 2, n = 3

Output: ["..#","#.."]

Explanation:
The only valid path is: (0,0) → (0,1) → (1,1) → (1,2)
```
**Constraints:**

- `1 <= m, n <= 25`

**Intuition:**

We can simply set the first row and the last column to `'.'` and fill the rest with `'#'`.