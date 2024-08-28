題號: 2328. Number of Increasing Paths in a Grid
難度: Hard

## 問題描述
You are given an `m x n` integer matrix `grid`, where you can move from a cell to any adjacent cell in all 4 directions.

Return the number of **strictly increasing** paths in the grid such that you can start from **any** cell and end at **any** cell. Since the answer may be very large, return it **modulo** `10^9 + 7`.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

**Example 1:**
![image](https://hackmd.io/_uploads/BJ23-WniC.png)
```
Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 1000`
- `1 <= m * n <= 10^5`
- `1 <= grid[i][j] <= 10^5`

**解決思路:**
此題利用DFS與DP的技巧來解決。

此題我們換個想法將題目轉化成求所有可能的遞減路徑。

假設當前cell為5，其右邊cell 4存在兩條遞減路徑為4->3->2->1，4->2->1; 因此對於cell 4來說，包含他本身可能的遞減路徑為6條：
4
4->3
4->3->2
4->3->2->1
4->2
4->1

那麼我們就知道對於當前cell 5向其右邊方向延伸所有可能的遞減路徑等於其右邊cell的解。

當我們進入一個cell時，我們必須針對四個方向其值小於當前值的cell透過DFS來遍歷所有可能路徑個數，並將四個方向的所有可能路徑加總起來為pathCount，最後我們需要紀錄當前cell的可能路徑數為pathCount + 1（1為只包含當前cell的路徑數），以便之後若從其他cell經過時可以直接取得遍歷結果進行加速。

