題號: 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

難度: `Medium`

## 問題描述

Given a `m x n` matrix `mat` and an integer `threshold`, return the maximum side-length of a square with a sum less than or equal to `threshold` or return `0` if there is no such square.

**Example 1:**
![圖片](https://hackmd.io/_uploads/H1Bis3sBWe.png)

```
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
```
**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 300`
- `0 <= mat[i][j] <= 10^4`
- `0 <= threshold <= 10^5`

**解決思路:**

直接我們需要先計算mat的prefix sum以利後續加速計算。

其中我們讓`prefix[i][j] = sum of submatrix (0,0) to (i-1,j-1)`

之後我們只需要透過binary search的方式從`1 ~ min(rows, cols)`之間找到最大可能的邊長即可。
