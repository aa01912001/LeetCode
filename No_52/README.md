題號: 52. N-Queens II
難度: Hard

## 問題描述
The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return the number of distinct solutions to the **n-queens puzzle**.

**Example 1:**
![](https://i.imgur.com/csONpin.png)
```
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
```

**Constraints:**

- `1 <= n <= 9`

---
## 解決思路
此題為典型的backtracking問題，我們可以先準備一個`nxn`的二維陣列`board`，當棋子擺上去後就將相應位置填為true，並在每一回合判斷當前位置之同一行列與斜邊是否有其他的棋子即可。