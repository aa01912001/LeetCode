題號: 687. Longest Univalue Path
難度: Medium

## 問題描述

Given the `root` of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

**The length of the path** between two nodes is represented by the number of edges between them.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/10/13/ex1.jpg)
```
Input: root = [5,4,5,1,1,5]
Output: 2
```
**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`
- The depth of the tree will not exceed `1000`.

---
## 解決思路

此題我們可以透過DFS的方式，每次找到當前`root`之左右節點向下延伸之**longest univalue path**(程式中存於`leftPath`與`rightPath`)；之後判斷當前`root`之值是否與左節點相同，若相同，代表`leftPath`可與當前`root`結合做延伸，因此我們將`leftPath+1`，否則令`leftPath = 0`，而右節點也進行相同判斷。

當我們計算出新的`leftPath`與`rigthPath`後，就需要去判斷結合左右節點與當前`root`所建構出的橫向**univalue path**是否長於先前找到之**longest univalue path**，若是的話則將解答進行更新。

最後應該要返回`max(leftPath, rigthPath)`給上層節點，以便將較長的**univalue path**可能性透過遞迴傳回判斷，如此，最終就能從tree中找出一條最長的**longest univalue path**。

