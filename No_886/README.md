題號: 886. Possible Bipartition

難度: Medium

## 問題描述

We want to split a group of `n` people (labeled from `1` to `n`) into two groups of **any size**. Each person may dislike some other people, and they should not go into the same group.

Given the integer `n` and the array `dislikes` where `dislikes[i] = [ai, bi]` indicates that the person labeled `ai` does not like the person labeled `bi`, return `true` if it is possible to split everyone into two groups in this way.

**Example 1:**

```
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
```

**Constraints:**

- `1 <= n <= 2000`
- `0 <= dislikes.length <= 10^4`
- `dislikes[i].length == 2`
- `1 <= dislikes[i][j] <= n`
- `ai < bi`
- All the pairs of `dislikes` are **unique**.

---
## 解決思路

此題我們可以轉換為圖論的問題，對於每個dislike的關係相當於一條edge。首先我們根據`dislikes`建立出adjacency list，之後判斷此graph是否能夠two-coloring即可(一種顏色相當於一個partition，所以要判斷所有節點可否被區分為兩個partition)。

在程式中我們利用DFS的策略來進行two-coloring的判斷，並用`vector<int> color(n+1, -1)`來記錄每個節點當前的顏色，其中。

- -1: 未被著色
- 0: 紅色
- 1: 黑色

當我們遇到尚未著色的節點就繼續進行DFS，否則判斷當前節點的顏色是否與應該被著的顏色相同。