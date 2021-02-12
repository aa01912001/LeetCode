題號: 1351. Count Negative Numbers in a Sorted Matrix

難度: Easy

## 問題描述
Given a `m x n` matrix `grid` which is sorted in non-increasing order both row-wise and column-wise, return the number of **negative** numbers in `grid`.


Example 1:

```
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
```
Constraints:

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 100`
- `100 <= grid[i][j] <= 100`

---
## 解決思路
此題只要針對每一row執行binary search找出第一個出現負數的位置即可。