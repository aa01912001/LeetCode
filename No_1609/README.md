題號: 1609. Even Odd Tree
難度: Medium

## 問題描述

A binary tree is named **Even-Odd** if it meets the following conditions:

- The root of the binary tree is at level index `0`, its children are at level index `1`, their children are at level index `2`, etc.
- For every **even-indexed** level, all nodes at the level have **odd** integer values in **strictly increasing** order (from left to right).
- For every odd-indexed level, all nodes at the level have **even** integer values in **strictly decreasing** order (from left to right).

Given the `root` of a binary tree, return `true` if the binary tree is **Even-Odd**, otherwise return `false`.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/09/15/sample_1_1966.png)
```
Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
Output: true
Explanation: The node values on each level are:
Level 0: [1]
Level 1: [10,4]
Level 2: [3,7,9]
Level 3: [12,8,6,2]
Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.
```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^6`

---
## 解決思路

此題我們只需要透過BFS策略來遍歷每一level，並在每一層根據題目相應規則進行判斷即可。
