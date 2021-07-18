題號: 706. Design HashMap

難度: Easy

## 問題描述

Given an `m x n` matrix `board` where each cell is a battleship `'X'` or empty `'.'`, return the number of the **battleships** on `board`.

**Battleships** can only be placed horizontally or vertically on `board`. In other words, they can only be made of the shape `1 x k` (`1` row, `k` columns) or `k x 1` (`k` rows, `1` column), where `k` can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/04/10/battelship-grid.jpg)

```
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2
```


**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is either `'.'` or `'X'`.

**Follow up: **Could you do it in one-pass, using only `O(1)` extra memory and without modifying the values `board`?

---
## 解決思路

此題我們只需要遍歷一次`board`，其中每當遇到'X'時，我們就檢查其左方與上方是否為'X'，若是的話則代表此位置是先前考量過的船的剩餘部分，所以不納入總數，否則代表此位置是所遇之新的船，故將總數加一。



