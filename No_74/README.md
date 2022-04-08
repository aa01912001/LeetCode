題號: 74. Search a 2D Matrix
難度: Medium

## 問題描述

Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:

- Integers in each row are sorted from left to right.
- The first integer of each row is greater than the last integer of the previous row.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

---
## 解決思路

此題中，第`i+1`列中的數必定大於第`i`列中之數，因此，我們可以用binary search先找出target所位於之row後，再同樣以binary search找出target所位於之column(因為每一列皆為遞增形式)。
