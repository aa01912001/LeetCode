題號: 149. Max Points on a Line
難度: Hard

## 問題描述
Given an array of `points` where `points[i] = [xi, yi]` represents a point on the **X-Y** plane, return the maximum number of points that lie on the same straight line.

**Example 1:**
![](https://i.imgur.com/1p5CwhR.png)
```
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
```

**Constraints:**

- `1 <= points.length <= 300`
- `points[i].length == 2`
- `-10^4 <= xi, yi <= 10^4`
- All the `points` are **unique**.

---
## 解決思路
我們知道一條直線上任兩點的斜率皆相同，因此對於此題，我們可以針對每個點去計算其與其他點的斜率，並將斜率個數存在hash map中，如此就能夠找出每條直線中點個數。