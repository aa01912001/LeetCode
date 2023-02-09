題號: 2458. Height of Binary Tree After Subtree Removal Queries
難度: Hard

## 問題描述
You are given the `root` of a **binary tree** with `n` nodes. Each node is assigned a unique value from `1` to `n`. You are also given an array `queries` of size `m`.

You have to perform m **independent** queries on the tree where in the ith query you do the following:

- **Remove** the subtree rooted at the node with the value `queries[i]` from the tree. It is **guaranteed** that `queries[i]` will not be equal to the value of the root.

Return an array `answer` of size `m` where `answer[i]` is the height of the tree after performing the `ith` query.

**Note**:
- The queries are independent, so the tree returns to its **initial** state after each query.
- The height of a tree is the **number of edges in the longest simple path** from the root to some node in the tree.


**Example 1:**
![](https://i.imgur.com/dT68Qi1.png)
```
Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `2 <= n <= 10^5`
- `1 <= Node.val <= n`
- All the values in the tree are **unique**.
- `m == queries.length`
- `1 <= m <= min(n, 10^4)`
- `1 <= queries[i] <= n`
- `queries[i] != root.val`

---
## 解決思路
此題我們首先利用DFS建立兩個結構，分別為:

1. `unordered_map<int, priority_queue<pair<int, int>>>`(存為**levelDownPath**): 用來為每一個tree level儲存一個max heap，而該max heap會記錄該level每個節點到其最深葉節點之路徑長`{path length, node value}`。

2. `unordered_map<int, int>`(存為**nodeLevel**): 紀錄每個節點對應的tree level。

對於`queries[i]`來說，我們只要找到相同level中**其他節點**最具有最長子路徑的路徑長度加上level值即可。

若該tree level中已經沒有其他節點，則直接返為level值。