題號: 1161. Maximum Level Sum of a Binary Tree

難度: Medium

## 問題描述
Given the `root` of a binary tree, the level of its root is `1`, the level of its children is `2`, and so on.

Return the **smallest** level `X` such that the sum of all the values of nodes at level `X` is **maximal**.

Example 1:
![](https://assets.leetcode.com/uploads/2019/05/03/capture.JPG)
```
Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.
```
---
## 解決思路
此題直接利用BFS將每一level遍歷搜尋後再計算sum比較可以。
