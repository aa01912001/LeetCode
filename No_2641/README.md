題號: 2641. Cousins in Binary Tree II

難度: Medium

## 問題描述
Given the `root` of a binary tree, replace the value of each node in the tree with the **sum of all its cousins' values**.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the `root` of the modified tree.

**Note** that the depth of a node is the number of edges in the path from the root node to it.


**Example 1:**
![example11](https://hackmd.io/_uploads/BkNoU_73xx.png)
```
Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^4`

**解決思路:**

我們使用BFS來解決此問題，並分為以下步驟:

對於每一層，我們分兩輪處理：
- 第一輪：計算孩子的總和
    - 每個 parent 節點的孩子和（`child_sum[parent]`）。
    - 這一層所有孩子的總和（`level_sum`）。


- 第二輪：更新孩子的值
    - 孩子的新值 = `level_sum - sibling_sum`
    - 其中 sibling_sum = 該孩子和它的兄弟的值和（由 parent 計算出來）。
    - 把更新後的孩子的孩子加進 queue，等待下一層處理。