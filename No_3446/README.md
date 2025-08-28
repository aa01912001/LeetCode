題號: 3446. Sort Matrix by Diagonals

難度: Medium

## 問題描述
You are given an `n x n` square matrix of integers `grid`. Return the matrix such that:

- The diagonals in the **bottom-left triangle** (including the middle diagonal) are sorted in **non-increasing order**.
- The diagonals in the **top-right triangle** are sorted in **non-decreasing order**.

**Example 1:**
![4052example1drawio](https://hackmd.io/_uploads/r1OhokCKxl.png)
```
Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

Output: [[8,2,3],[9,6,7],[4,5,1]]
```

**Constraints:**

- `grid.length == grid[i].length == n`
- `1 <= n <= 10`
- `-10^5 <= grid[i][j] <= 10^5`

**解決思路:**

此題我們只需要針對上下三角分別處理，並且每次都把一個對角線的元素取出排序後再塞回即可。