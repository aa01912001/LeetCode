題號: 783. Minimum Distance Between BST Nodes

難度: Easy

## 問題描述

Given the `root` of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

Example 1:

![image alt](https://assets.leetcode.com/uploads/2021/02/05/bst1.jpg)

```
Input: root = [4,2,6,1,3]
Output: 1
```

Constraints:

- `1 <= s.length <= 500`
- `k` is in the range `[1, the number of words in s]`.
- `s` consist of only lowercase and uppercase English letters and spaces.
- The words in `s` are separated by a single space.
- There are no leading or trailing spaces.


---
## 解決思路

此題只要使用DFS策略找出各個節點的**左子樹最大值**與**右子樹最小值**後，再分別與節點值做絕對差值後取最小與歷史最小差值比較即可。
