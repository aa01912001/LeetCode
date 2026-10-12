題號: 3239. Minimum Number of Flips to Make Binary Grid Palindromic I

難度: `Medium`

## 問題描述


You are given an $m \times n$ binary matrix `grid`.

A row or column is considered **palindromic** if its values read the same forward and backward.

You can **flip** any number of cells in `grid` from `0` to `1`, or from `1` to `0`.

Return the **minimum** number of cells that need to be flipped to make **either** all rows **palindromic** or all columns **palindromic**.


**Example 1:**
![圖片](https://hackmd.io/_uploads/By_yXH9oMl.png)
```
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]

Output: 2

Flipping the highlighted cells makes all the rows palindromic.
```
**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m * n <= 2 * 10^5`
- `0 <= grid[i][j] <= 1`

**解決思路:**

此題我們可分別計算行回文與列回文的所需步數並取最小值即可。

對於計算行回文:
- 遍歷矩陣的每一行
- 比較每一行中對應的左右元素，透過 XOR 運算若為，1則代表我們需要花1步將其變成相同

計算列回文亦同理。