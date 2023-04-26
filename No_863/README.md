題號: 863. All Nodes Distance K in Binary Tree
難度: Medium

## 問題描述
Given the `root` of a binary tree, the value of a `target` node target, and an integer `k`, return an array of the values of all nodes that have a distance `k` from the target node.

You can return the answer in **any order**.

![](https://i.imgur.com/rkma1WM.png)

**Example 1:**
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 500]`.
- `0 <= Node.val <= 500`
- All the values `Node.val` are **unique**.
- `target` is the value of one of the nodes in the tree.
- `0 <= k <= 1000`

## 解決思路
此題我們先利用DFS來建立一個無向圖，以便讓任意節點可以拜訪到父節點。之後我們便可以輕易地使用BFS找到距離`target`節點距離第`k`層的所有節點了。