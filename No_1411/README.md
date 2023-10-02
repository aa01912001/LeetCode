題號: 1411. Number of Ways to Paint N × 3 Grid
難度: Hard

## 問題描述
You have a `grid` of size `n x 3` and you want to paint each cell of the grid with exactly one of the three colors: **Red**, **Yellow**, or **Green** while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

Given n the number of rows of the `grid`, return the number of ways you can paint this grid. As the answer may grow large, the answer **must be** computed modulo `10^9 + 7`.

**Example 1:**
![](https://hackmd.io/_uploads/rkGXc2wx6.png)
```
Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown.
```

**Constraints:**

- `n == grid.length`
- `1 <= n <= 5000`

## 解決思路
此題可以透過DP的思路來解決。

我們令:

`pattern1`為 c1 c2 c3 型態的數量
`pattern2`為 c1 c2 c1 型態的數量

我們可以初始化`pattern1`及`pattern2`為6

透過觀察我們可以知道對於下一階pattern的狀態轉移式為:

c1 c2 c3 => c2 c3 c1, c3 c1 c2 + c2 c1 c3, c3 c1 c2 (後面兩個為上一階`pattern2`在此階所能夠衍生出的`pattern1`型態)
因此我們更新`pattern1 = pattern1 * 2 + pattern2 * 2`

c1 c2 c1 => c2 c1 c2, c2 c3 c2, c3 c1 c3 + c2 c1 c2, c2 c3 c2 (後面兩個為上一階`pattern1`在此階所能夠衍生出的`pattern2`型態)
因此我們更新`pattern2 = pattern2 * 3 + pattern1 * 2`

我們只需要將最後`pattern1`與`pattern2`相加即為解答