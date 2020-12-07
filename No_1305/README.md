題號: 1305. All Elements in Two Binary Search Trees
難度: Medium

## 問題描述
Given two binary search trees `root1` and `root2`.

Return a list containing all the integers from both trees sorted in **ascending** order.

---
## 解決思路
因為binary search tree之左子樹節點必小於root、右子樹節點必大於root，所以我們可以利用inorder traverse來得到binary search tree的節點排序。程式中我利用multiset來插入遍歷的節點來維護節點的順序，最後再利用vector的constructor來將multiset中的資料存進vector中。

**Note:**
1. multiset和set的底層皆為紅黑樹，又紅黑樹本質上是一棵高度平衡的binary search tree，所以我們可以使用multiset來插入遍歷的數組以此維持數組的順序。

2. multiset與set的差別在於multiset可以儲存重複的資料。


