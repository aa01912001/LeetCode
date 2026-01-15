題號: 2943. Maximize Area of Square Hole in Grid

難度: `Medium`

## 問題描述

You are given the two integers, `n` and `m`, and two integer arrays, `hBars` and `vBars`.

The grid has `n + 2` horizontal bars and `m + 2` vertical bars, creating `1 x 1` unit cells.  
The bars are indexed starting from `1`.

You can **remove** some of the bars in `hBars` from the horizontal bars and some of the bars in `vBars` from the vertical bars.  
Note that other bars are fixed and cannot be removed.

Return an integer denoting the **maximum area** of a square-shaped hole in the grid, after removing some bars (possibly none).



**Example 1:**
![圖片](https://hackmd.io/_uploads/SJ2mLrLSWl.png)
```
Input: n = 2, m = 1, hBars = [2,3], vBars = [2]

Output: 4

Explanation:

The left image shows the initial grid formed by the bars. The horizontal bars are [1,2,3,4], and the vertical bars are [1,2,3].

One way to get the maximum square-shaped hole is by removing horizontal bar 2 and vertical bar 2.

```
**Constraints:**

- `1 <= n <= 10^9`
- `1 <= m <= 10^9`
- `1 <= hBars.length <= 100`
- `2 <= hBars[i] <= n + 1`
- `1 <= vBars.length <= 100`
- `2 <= vBars[i] <= m + 1`
- All values in `hBars` are distinct.
- All values in `vBars` are distinct.

**解決思路:**

透過觀察，我們不難發現能形成的最大正方形邊長 =
（可連續移除的橫 bar 數量 + 1）和（可連續移除的直 bar 數量 + 1）的最小值。