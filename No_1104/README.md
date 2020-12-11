題號: 1104. Path In Zigzag Labelled Binary Tree

難度: Medium

## 問題描述
In an infinite binary tree where every node has two children, the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

![Example](https://assets.leetcode.com/uploads/2019/06/24/tree.png)


Given the `label` of a node in this tree, return the labels in the path from the root of the tree to the node with that `label`.

---
## 解決思路
此題我們只需要想辦法找出節點parent的公式即可，透過觀察我們發現節點之parent可以透過下列公式算出:

**pow(2, h+1) - (label/2 - pow(2, h)) - 1**

其中h為parent那層的樹高，且root樹高為0。