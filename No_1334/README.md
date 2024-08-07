題號: 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
難度: Medium

## 問題描述
There are `n` cities numbered from `0` to `n-1`. Given the array `edges` where `edges[i] = [from_i, to_i, weight_i]` represents a bidirectional and weighted edge between cities `from_i` and `to_i`, and given the integer `distanceThreshold`.

Return the city with the smallest number of cities that are reachable through some path and whose distance is **at most** `distanceThreshold`, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities `i` and `j` is equal to the sum of the edges' weights along that path.

**Example 1:**
![find_the_city_01](https://hackmd.io/_uploads/SyC8XcxF0.png)
```
Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
```

**Constraints:**

- `2 <= n <= 100`
- `1 <= edges.length <= n * (n - 1) / 2`
- `edges[i].length == 3`
- `0 <= from_i < to_i < n`
- `1 <= weight_i, distanceThreshold <= 10^4`
- All pairs (from_i, to_i) are distinct.

## 解決思路
此題我們需要求得各點對各點之間的最短離，因此我們可以直接使用**Floyd Warshall Algorithm**來解決此問題。

最後只需要針對各點計算出小於等於`distanceThreshold`的城市數量總和即可。

