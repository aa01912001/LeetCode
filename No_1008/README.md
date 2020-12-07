題號: 1008. Construct Binary Search Tree from Preorder Traversal
難度: Medium

## 問題描述
Return the root node of a binary search tree that matches the given `preorder` traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of `node.left` has a value` < ` `node.val`, and any descendant of `node.right` has a value` >` `node.val`.  Also recall that a preorder traversal displays the value of the`node`first, then traverses `node.left`, then traverses `node.right`.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

---
## 解決思路
由於preorder是依照D(root)、L(left subtree)、R(right subtree)的順序遍歷，再加上binary search tree之左子樹節點必小於root、右子樹節點必大於root，所以我們可以從給定的preorder vector中取出第一個root後，再將之後的vector分為小於或大於節點的兩組，即為root在binary search tree中的左子樹和右子樹。而左子樹和右子樹再以遞迴的方式相同解之即可。


