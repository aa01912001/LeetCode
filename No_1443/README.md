題號: 1443. Minimum Time to Collect All Apples in a Tree
難度: Medium

## 問題描述
Given an undirected tree consisting of `n` vertices numbered from `0` to `n-1`, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at **vertex 0** and coming back to this vertex.

The edges of the undirected tree are given in the array `edges`, where `edges[i] = [ai, bi]` means that exists an edge connecting the vertices `ai` and `bi`. Additionally, there is a boolean array `hasApple`, where `hasApple[i] = true` means that vertex `i` has an apple; otherwise, it does not have any apple.

**Example 1:**
![](https://i.imgur.com/jDZ4Jst.png)
```
Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
Output: 8 
Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows.  
```

**Constraints:**

- `1 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i].length == 2`
- `0 <= ai < bi <= n - 1`
- `hasApple.length == n`

---
## 解決思路

此題我們只需要利用DFS的策略遍歷所有節點即可。

對於每個當前節點來說，我們需要同樣地利用DFS來遍歷與取得其左右子樹之解，若發現左右子樹之解之和(存為`subTreeTime`)不為0，代表當前點必定要拜訪(因為子樹有蘋果)，因此返回給上層`subTreeTime + 2`;若`subTreeTime`為0，需要另外判斷當前節點是否有蘋果，若有，則該節點仍然必須拜訪，因此，返回2，否則不需拜訪含此節點以下的樹，故返回0。

因此，藉由上述DFS操作，我們可以得到最終解答值。