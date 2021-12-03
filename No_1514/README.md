題號: 1514. Path with Maximum Probability

難度: Medium

## 問題描述

You are given an undirected weighted graph of `n` nodes (0-indexed), represented by an edge list where `edges[i] = [a, b]` is an undirected edge connecting the nodes `a` and `b` with a probability of success of traversing that edge `succProb[i]`.

Given two nodes `start` and `end`, find the path with the maximum probability of success to go from `start` to `end` and return its success probability.

If there is no path from `start` to `end`, **return 0**. Your answer will be accepted if it differs from the correct answer by at most **1e-5**.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2019/09/20/1558_ex1.png)
```
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
```

**Constraints:**

- `2 <= n <= 10^4`
- `0 <= start, end < n`
- `start != end`
- `0 <= a, b < n`
- `a != b`
- `0 <= succProb.length == edges.length <= 2*10^4`
- `0 <= succProb[i] <= 1`
- There is at most one edge between every two nodes.

---
## 解決思路

此題我們可以對**dijkstra**演算法進行修改來找出`start`與`end`間的**Maximum Probability**。

程式中，我們使用**max heap**來維護當前每個節點的**Maximum Probability**，而因為C++中的priority_queue並沒有支援decresse key的操作，所以我們採用**lazy deletion**的方式來修改queue中每個節點的**Maximum Probability**值，想法如下:

即使同樣的節點被放入**max heap**多次，因為永遠會先取出最大的**Maximum Probability**，所以我們只要記錄該節點是否曾經從**max heap**被取出(代表該節點已經被確認它的**Maximum Probability**)即可。

而對於每個邊的relaxation操作，我們變為更新成較大的**Maximum Probability**值，並放入**max heap**中。

最後只要當**max heap**為空，代表已無節點未被確認，只要返回`end`的**Maximum Probability**值即可。