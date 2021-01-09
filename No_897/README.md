題號: 897. Increasing Order Search Tree

難度: Easy

## 問題描述
Given the `root` of a binary search tree, rearrange the tree in **in-order** so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

Example 1:
![](https://assets.leetcode.com/uploads/2020/11/17/ex1.jpg)

```
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
```



Constraints:

- The number of nodes in the given tree will be in the range `[1, 100]`.
- `0 <= Node.val <= 1000`



---
## 解決思路
此題直接利用DFS做inorder搜尋，且一邊形成右頃樹即可。

注意: 程式中使用**雙重指標tmp**的原因在於，因為在C++指標本身也是**call by value**所以如果我們直接改變指標的值(例如tmp = root)，那麼返回上層遞迴後仍然也是原本的值，所以在此使用雙重指標來改變指標的儲存的位置。
