題號: 867. Transpose Matrix

難度: Easy

## 問題描述

Given a 2D integer array `matrix`, return the **transpose** of `matrix`.

The **transpose** of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

Example 1:

![image alt](https://assets.leetcode.com/uploads/2021/02/10/hint_transpose.png)

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
```

Constraints:

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 1000`
- `1 <= m * n <= 10^5`
- ``-10^9 <= matrix[i][j] <= 10^9`



---
## 解決思路

此題只需要將matrix的row跟column互換即可。
