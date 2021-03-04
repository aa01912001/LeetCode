題號: 1261. Find Elements in a Contaminated Binary Tree

難度: Medium

## 問題描述
Given a binary tree with the following rules:


1. `root.val == 0`
2. If `treeNode.val == x` and `treeNode.left != null`, then `treeNode.left.val == 2 * x + 1`
3. If `treeNode.val == x` and `treeNode.right != null`, then `treeNode.right.val == 2 * x + 2`

Now the binary tree is contaminated, which means all `treeNode.val` have been changed to `-1`.

You need to first recover the binary tree and then implement the `FindElements` class:

- `FindElements(TreeNode* root)` Initializes the object with a contamined binary tree, you need to recover it first.
- `bool find(int target)` Return if the `target` value exists in the recovered binary tree.

Example 1:
![](https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4.jpg)
```
Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

Constraints:


- `TreeNode.val == -1`
- The height of the binary tree is less than or equal to `20`
- The total number of nodes is between `[1, 10^4]`
- Total calls of `find()` is between `[1, 10^4]`
- `0 <= target <= 10^6`

---
## 解決思路

針對`FindElements(TreeNode* root)`我們可以使用DFS策略將tree還原，同時在遍歷的過程中，利用vector將每個節點還原後的值儲存起來。結束DFS後，我們將vector進行sort，以便在`bool find(int target)`中利用`binary search`進行查找。