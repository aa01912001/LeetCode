題號: 1976. Number of Ways to Arrive at Destination

難度: Medium

## 問題描述

You are in a city that consists of `n` intersections numbered from `0` to `n - 1` with **bi-directional** roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer `n` and a 2D integer array `roads` where `roads[i] = [ui, vi, timei]` means that there is a road between intersections `ui` and `vi` that takes `timei` minutes to travel. You want to know in how many ways you can travel from intersection `0` to intersection `n - 1` in the **shortest amount of time**.

Return the **number of ways** you can arrive at your destination in the **shortest amount of time**. Since the answer may be large, return it **modulo** `10^9 + 7`.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/07/17/graph2.png)
```
Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
```

**Constraints:**

- `1 <= n <= 200`
- `n - 1 <= roads.length <= n * (n - 1) / 2`
- `roads[i].length == 3`
- `0 <= ui, vi <= n - 1`
- `1 <= timei <= 10^9`
- `ui != vi`
- There is at most one road connecting any two intersections.
- You can reach any intersection from any other intersection.

---
## 解決思路

此題我們可以利用**dijkstra**的方式找出`src`到`dst`的路徑，在進行edge relaxation時，除了要記錄節點的對小權重之外，還要同時記錄當前節點可能的最短路徑個數，想法如下:

我們可以將edge relaxation分為三種cases：
1. `dist[u] + weight = dist[v]`：
    將`dist[v] = dist[u] + weight`，同時將`v`的最短路徑個數加上`u`的最短路徑個數(因為此case代表從`u`經過某條邊又可以得到同樣短的路徑。
    
2. `dist[u] + weight < dist[v]`：
    將`v`的最短路徑個數等於`u`的最短路徑個數(因為此case代表從`u`經過某條邊可以找到更短的路徑)
    
3. `dist[u] + weight > dist[v]`：
    不做更新
    
如此我們就可以找出最終`dst`的最短路徑個數。