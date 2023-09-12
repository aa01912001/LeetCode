題號: 73. Set Matrix Zeroes
難度: Medium

## 問題描述
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it `in place`.

**Example 1:**
![](https://hackmd.io/_uploads/SymryjpR2.jpg)
```
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Constraints:**

- `m == matrix.length`
- `n == matrix[0].length`
- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

**Follow up:**

- A straightforward solution using `O(mn)` space is probably a bad idea.
- A simple improvement uses `O(m + n)` space, but still not the best solution.
- Could you devise a constant space solution?

## 解決思路
此題我們首先掃描一次`matrix`，若`matrix[i][j] == 0`，我們就將`matrix[i][0]`及`matrix[0][j]`標記為0。

之後我們之需要針對將每個值為0的`matrix[i][0]`及`matrix[0][i]`，其對應的row與column全部變為0即可。