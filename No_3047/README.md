題號: 3047. Find the Largest Area of Square Inside Two Rectangles

難度: `Medium`

## 問題描述

There exist `n` rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays `bottomLeft` and `topRight` where `bottomLeft[i] = [a_i, b_i]` and `topRight[i] = [c_i, d_i]` represent the **bottom-left** and **top-right** coordinates of the `ith` rectangle, respectively.

You need to find the **maximum** area of a **square** that can fit inside the intersecting region of at least two rectangles. Return `0` if such a square does not exist.

**Example 1:**
![圖片](https://hackmd.io/_uploads/H1MwR3_H-x.png)
```
Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]

Output: 1

Explanation:

A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.
```
**Constraints:**

    n == bottomLeft.length == topRight.length
- `2 <= n <= 10^3`
- `bottomLeft[i].length == topRight[i].length == 2`
- `1 <= bottomLeft[i][0], bottomLeft[i][1] <= 10^7`
- `1 <= topRight[i][0], topRight[i][1] <= 10^7`
- `bottomLeft[i][0] < topRight[i][0]`
- `bottomLeft[i][1] < topRight[i][1]`

**解決思路:**

直接暴力兩兩比較兩個矩形交集的最大正方形面積即可。