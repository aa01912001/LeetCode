題號: 1584. Min Cost to Connect All Points
難度: Medium

## 問題描述

You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [xi, yi]`.

The cost of connecting two points `[xi, yi]` and `[xj, yj]` is the **manhattan distance** between them: `|xi - xj| + |yi - yj|`, where `|val|` denotes the absolute value of `val`.

Return the minimum cost to make all points connected. All points are connected if there is **exactly one** simple path between any two points.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/08/26/d.png)

<pre>
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
<img src="https://assets.leetcode.com/uploads/2020/08/26/c.png">
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
</pre>

**Constraints:**

- `1 <= points.length <= 1000`
- `-10^6 <= xi, yi <= 10^6`
- All pairs `(xi, yi)` are distinct.

---
## 解決思路

因為每個點皆可任意互相連結，而我們只需要最少數量且成本最少的邊將所有點連通，因此此題相當於解MST問題，程式中我們採用Kruscal演算法配合min heap來找出MST的所有邊，而在執行該演算法的過程中，我們也透過union-find來判斷當前成本最小邊的加入會不會造成cycle。

最後只要找出節點各數-1條邊，並將這些邊的成本進行加總即為最終答案。


