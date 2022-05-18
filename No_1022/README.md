題號: 1022. Sum of Root To Leaf Binary Numbers
難度: Easy

## 問題描述

You are given the `root` of a binary tree where each node has a value `0` or `1`. Each root-to-leaf path represents a binary number starting with the most significant bit.

- For example, if the path is `0 -> 1 -> 1 -> 0 -> 1`, then this could represent `01101` in binary, which is `13`.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a **32-bits** integer.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png)
```
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 1000]`.
- `Node.val` is `0` or `1`.

---
## 解決思路

此題我們只需要透過DFS策略來記錄每個當前的path sum，直到遇見leaf後再將此path sum加至解答中。