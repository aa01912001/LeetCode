題號: 993. Cousins in Binary Tree

難度: Easy

## 問題描述
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth `k+1`.

Two nodes of a binary tree are cousins if they have the same depth, but have **different parents**.

We are given the `root` of a binary tree with unique values, and the values `x` and `y` of two different nodes in the tree.

Return `true` if and only if the nodes corresponding to the values `x` and `y` are cousins.

Example 1:

![](https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png)

```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

```


Constraints:

- The number of nodes in the tree will be between `2` and `100`.
- Each node has a unique integer value from `1` to `100`.
---
## 解決思路

此題可以利用BFS的策略對於x、y來判斷是否出現在同一level，並且判斷是否具相同的parent即可。