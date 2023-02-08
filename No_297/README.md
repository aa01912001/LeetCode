題號: 297. Serialize and Deserialize Binary Tree
難度: Hard

## 問題描述
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Example 1:**
![](https://i.imgur.com/kmOl2b0.png)
```
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

---
## 解決思路
對於`serialize`來說，我們可以利用BFS來遍歷每個節點，並且為其標記唯一label，這裡我們使用0/1 path的方式來為每個節點建立label，假設某個節點的label為`***`，那麼其左子節點的label為`***0`，右子節點為`***1`，因此對於每個節點的字串形式為`value|label`，而節點之間我們則用`!`符號分隔。

而對於`deserialize`來說，我們可以使用`unordered_map<string, TreeNode*>`的結構來儲存每個唯一label對應的節點，對於一個label為`***0`或`***1`的節點，我們可以很清楚其父節點的label為`***`，因此透過hash map我們可以輕易地找到父節點並與當前節點進行串接。