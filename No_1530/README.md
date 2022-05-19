題號: 1530. Number of Good Leaf Nodes Pairs
難度: Medium



## 問題描述

You are given the `root` of a binary tree and an integer `distance`. A pair of two different **leaf** nodes of a binary tree is said to be good if the length of **the shortest path** between them is less than or equal to `distance`.

Return the number of good leaf node pairs in the tree.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/07/09/e1.jpg)
```
Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
```
**Constraints:**

- The number of nodes in the `tree` is in the range `[1, 2^10]`.
- `1 <= Node.val <= 100`
- `1 <= distance <= 10`

---
## 解決思路

此題我們可透過DFS的策略來計算左右子樹其leaf node距離當前節點的距離，假設：

`target = 2`
左子樹有三個leaf node距離如下：
`[1, 2 , 2]`
右子樹有兩個leaf node距離如下：
`[1, 1]`

那麼只要從兩個vector中各挑一個節點且其距離加總小於等於`target`，那麼即為一個合法的pair，我們即將解答值加1。

最後我們需要將所有leaf node的距離加1後，作為當前子樹的leaf node距離返回給上層繼續判斷，返回vector如下所示：

`[2, 3, 3, 2, 2]`

如此，最終即可得到所有的合法pair之數量。