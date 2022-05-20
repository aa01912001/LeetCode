題號: 988. Smallest String Starting From Leaf
難度: Medium



## 問題描述

You are given the `root` of a binary tree where each node has a value in the range `[0, 25]` representing the letters `'a'` to `'z'`.

Return the **lexicographically smallest** string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is **lexicographically smaller**.

A leaf of a node is a node that has no children.

- For example, `"ab"` is lexicographically smaller than `"aba"`.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2019/01/30/tree1.png)
```
Input: root = [0,1,2,3,4,3,4]
Output: "dba"
```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 8500]`.
- `0 <= Node.val <= 25`

---
## 解決思路

此題只需要透過DFS策略來找出所有可能的path string後，再一一比較取出最小的 **lexicographically smallest string**即可。
