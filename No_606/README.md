題號: 606. Construct String from Binary Tree

難度: Easy

## 問題描述

Given the `root` of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/05/03/cons1-tree.jpg)
```
Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-1000 <= Node.val <= 1000`


---
## 解決思路

此題只要利用DFS分別對左右子樹建構字串並回傳給原本的根節點即可。


