題號: 947. Most Stones Removed with Same Row or Column
難度: Medium

## 問題描述

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either **the same row or the same column** as another stone that has not been removed.

Given an array `stones` of length `n` where `stones[i] = [xi, yi]` represents the location of the `ith` stone, return the largest possible number of stones that can be removed.

 

**Example 1:**
```
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
```


**Constraints:**

- `1 <= stones.length <= 1000`
- `0 <= xi, yi <= 10^4`
- No two stones are at the same coordinate point.

---
## 解決思路

此題我們可以以圖論的關係去思考，當兩個節點具有相同的x值或y值，我們就可以刪掉其一，因此我們可以藉由將具有**相同x值或y值**的關係做為兩節點的邊來作圖，因此我們最終只需要考慮整個圖有多少的component，則代表去除所有的可刪節點後，還會遺留多少個節點。

再程式中，我們以union-find的方式來找出最終的component個數，只要兩個節點具有相同的x值或y值，我們就將之視為同一個集合即可。