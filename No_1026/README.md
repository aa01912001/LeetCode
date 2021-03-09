題號: 1026. Maximum Difference Between Node and Ancestor

難度: Medium

## 問題描述
Given the `root` of a binary tree, find the maximum value V for which there exist **different** nodes `A` and `B` where `V = |A.val - B.val|` and `A` is an ancestor of `B`.

A node `A` is an ancestor of `B` if either: any child of `A` is equal to `B`, or any child of `A` is an ancestor of `B`.

Example 1:

![](https://assets.leetcode.com/uploads/2020/11/09/tmp-tree.jpg)

```
Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
```


Constraints:

- The number of nodes in the tree is in the range `[2, 5000]`.
- `0 <= Node.val <= 10^5`

---
## 解決思路

此題可以利用DFS的策略遍歷每個節點，其中利用變數`minValue`、`maxValue`來記錄遍歷過程中所遇到的最小值與最大值，如此就可以計算每一次遍歷到新的節點後所更動的Maximum Difference。