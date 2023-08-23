題號: 2271. Maximum White Tiles Covered by a Carpet
難度: Medium

## 問題描述
You are given a 2D integer array `tiles` where `tiles[i] = [li, ri]` represents that every tile `j` in the range `li <= j <= ri` is colored white.

You are also given an integer `carpetLen`, the length of a single carpet that can be placed **anywhere**.

Return the **maximum** number of white tiles that can be covered by the carpet.

**Example 1:**
![](https://hackmd.io/_uploads/ryBDsCz63.png)
```
Input: tiles = [[1,5],[10,11],[12,18],[20,25],[30,32]], carpetLen = 10
Output: 9
Explanation: Place the carpet starting on tile 10. 
It covers 9 white tiles, so we return 9.
Note that there may be other places where the carpet covers 9 white tiles.
It can be shown that the carpet cannot cover more than 9 white tiles.
```
**Constraints:**

- `1 <= tiles.length <= 5 * 10^4`
- `tiles[i].length == 2`
- `1 <= li <= ri <= 10^9`
- `1 <= carpetLen <= 10^9`
- The `tiles` are **non-overlapping**.

## 解決思路
此題我們利用two pointers與prefix sum的方式來解決。

程式中我們利用`coveredTiles`來記錄當前的覆蓋數量，用`left`紀錄當前開頭的tile索引位置。

在每回合中我們比較`tiles[left][0] + carpetLen > tiles[i][1]`，來判斷是否還可以容納當前的第`i`堆的所有tiles。

1. 若可以: 我們將`coveredTiles`將上當前`tiles[i]`的數量，更新解答後再將`i`加1

2. 若無法: 我們判斷`coveredTiles`加上覆蓋部分的數量是否比當前解答大，之後再將`coveredTiles`扣掉最左邊的堆(`tiles[left]`)數量，再將左窗口`left`加1進行下一回合判斷。

