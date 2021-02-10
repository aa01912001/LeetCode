題號: 1457. Pseudo-Palindromic Paths in a Binary Tree

難度: Medium

## 問題描述
Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be **pseudo-palindromic** if at least one permutation of the node values in the path is a palindrome.

Return the number of **pseudo-palindromic** paths going from the root node to leaf nodes.


Example 1:
![](https://assets.leetcode.com/uploads/2020/05/06/palindromic_paths_1.png)
```
Input: root = [2,3,1,3,1,null,1]
Output: 2 
Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
```
Constraints:

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 9`


---
## 解決思路
此題我們可利用DFS來檢查每一條路徑，其中經過每一個節點時，我們利用`tmp_xor`變數來儲存每一個節點值由上到下做xor的結果，我們在做xor時並不是單純的用`root->val`來做xor，而是使用`xorTable[root->val]`;其中`xorTable = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256}`用來代表節點值1到9分別代表的bit，如此我們就可以計算每個節點值的parity。最後若抵達樹葉節點，則判斷tmp_xor是否等於0或是否只有一個1~9中的值出現為奇數次，若是的話則代表此路徑為**pseudo-palindromic path**。