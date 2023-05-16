題號: 54. Spiral Matrix
難度: Medium

## 問題描述
Given an `m x n` `matrix`, return all elements of the `matrix` in spiral order.

**Example 1:**
![](https://hackmd.io/_uploads/SJ2NdLgS3.png)
```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```
**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 10`
- `-100 <= matrix[i][j] <= 100`

## 解決思路
此題中我們可以遍歷的規律就是`first row、last column、last row、first column`，因此我們可以分別利用四個變數儲存上述四項當前各自的索引值，並分別以`右、下、左、上`的方式前進即可;另外再遍歷每一列(或行)後，也要記得將變數值縮進，以便之後不再重複遍歷到同列(或行)。