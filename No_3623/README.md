題號: 3623. Count Number of Trapezoids I

難度: `Medium`

## 問題描述

You are given a 2D integer array `points`, where `points[i] = [xi, yi]` represents the coordinates of the `ith` point on the Cartesian plane.

A **horizontal trapezoid** is a convex quadrilateral with **at least one pair** of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique **horizontal trapezoids** that can be formed by choosing any four distinct points from `points`.

Since the answer may be very large, return it modulo `10^9 + 7`.


**Example 1:**
```
Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]

Output: 3

There are three distinct ways to pick four points that form a horizontal trapezoid:

- Using points [1,0], [2,0], [3,2], and [2,2].
- Using points [2,0], [3,0], [3,2], and [2,2].
- Using points [1,0], [3,0], [3,2], and [2,2].
```
**Constraints:**

- `4 <= points.length <= 10^5`
- `–10^8 <= xi, yi <= 10^8`
- `All points are pairwise distinct.`


**解決思路:**

要形成水平梯形必須要有兩條水平邊，也就是選兩個不同的 y 值，每個 y 值上各取兩個點。

因此我們只需要:
1. 統計每個 y 值有多少點
2. 每個 y 群組可以組出多少水平線上的點對
3. 計算出可能的兩條不同 y 水平線的 pair 可以互相搭配成梯形數量