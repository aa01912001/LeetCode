題號: 1319. Number of Operations to Make Network Connected

難度: Medium

## 問題描述

There are `n` computers numbered from `0` to `n-1` connected by ethernet cables `connections` forming a network where `connections[i] = [a, b]` represents a connection between computers `a` and `b`. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/01/02/sample_1_1677.png)

```
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
```

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= connections.length <= min(n*(n-1)/2, 10^5)`
- `connections[i].length == 2`
- `0 <= connections[i][0], connections[i][1] < n`
- `connections[i][0] != connections[i][1]`
- There are no repeated connections.
- No two computers are connected by more than one cable.

---
## 解決思路

此題我們可用`union find`的方式將所有connected component找出來，之後因為題目限制了無loop edge、無重複邊與頂點至頂點最多一條邊，因此在邊數大於n-1的情況下必定有解。故我們只需要找出connected component的個數後，再將此數減一返回即可(因為讓m個獨立節點連通最少只需要加入m-1條邊)。







