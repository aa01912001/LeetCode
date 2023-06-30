題號: 2385. Amount of Time for Binary Tree to Be Infected
難度: Medium

## 問題描述
You are given the `root` of a binary tree with **unique** values, and an integer `start`. At minute `0`, an **infection** starts from the node with value `start`.

Each minute, a node becomes infected if:

- The node is currently uninfected.
- The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.

**Example 1:**
![](https://hackmd.io/_uploads/rJJ-yasO2.png)
```
Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`
- Each node has a **unique** value.
- A node with a value of `start` exists in the tree.

## 解決思路
此題我們採用DFS的方式來求解，首先我們要考慮兩個情況:

1. 與`start`距離最遠的節點存在於以`start`為根的子樹之葉節點中。
2. 與`start`距離最遠的節點存在於與`start`某個共同祖先節點的另一側子樹之葉節點。

對於情況1來說，我們只需要將解答更新為以`start`為根的左右子樹最大深度值。而對於狀況2來說，我們必須要讓共同祖先節點知道其子樹是否含有`start`，因此程式中我們利用`hasStart`來通知上層節點，一但某個節點知道其某側子樹含有`start`就可以將解答進行更新為:

(假設`start`位於左子樹)
`ret = max(ret, startDepth-depth+maxDepthRight)`，其中`ret`為解答值、`startDepth`為`start`節點在整棵樹中的深度、`depth`為當前節點之深度，而`maxDepthRight`為右子樹之最大深度。

