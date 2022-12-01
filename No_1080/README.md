題號: 1080. Insufficient Nodes in Root to Leaf Paths
難度: Medium

## 問題描述
Given the `root` of a binary tree and an integer `limit`, delete all **insufficient nodes** in the tree simultaneously, and return the root of the resulting binary tree.

A node is **insufficient** if every root to **leaf** path intersecting this node has a sum strictly less than `limit`.

A **leaf** is a node with no children.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2019/06/05/insufficient-11.png)
```
Input: root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1
Output: [1,2,3,4,null,null,7,8,9,null,14]
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 5000]`.
- `-10^5 <= Node.val <= 10^5`
- `-10^9 <= limit <= 10^9`

---
## 解決思路

此題我們只需要透過DFS的方式來判斷每條經過當前節點的`root`至`leaf`路徑之和是否皆小於`limit`即可。在呼叫DFS遞迴的過程中，我們不斷累加當前節點值直到遍歷至`leaf`，若最後之`sum`值小於`limit`則返回true。而針對某個節點來說，若其左或右子節點返回true，則代表該子樹所有至`leaf`的路徑和皆會小於`limit`，因此我們將當前節點之左或右節點變為nullptr。最後若左與右子節點皆返回true，當前節點應該返回true給上層節點，以表示包含該當前節點為`root`的子樹之路徑和皆小於`limit`。