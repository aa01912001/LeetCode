題號: 2096. Step-By-Step Directions From a Binary Tree Node to Another
難度: Medium

## 問題描述
You are given the `root` of a **binary tree** with `n` nodes. Each node is uniquely assigned a value from `1` to `n`. You are also given an integer `startValue` representing the value of the start node `s`, and a different integer `destValue` representing the value of the destination node `t`.

Find the **shortest path** starting from node `s` and ending at node `t`. Generate step-by-step directions of such path as a string consisting of only the **uppercase** letters `'L'`, `'R'`, and `'U'`. Each letter indicates a specific direction:

- `'L'` means to go from a node to its **left child** node.
- `'R'` means to go from a node to its **right child** node.
- `'U'` means to go from a node to its **parent** node.

Return the step-by-step directions of the **shortest path** from node `s` to node `t`.

**Example 1:**
![](https://hackmd.io/_uploads/S1vafN7Cn.png)
```
Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
```
**Constraints:**

- The number of nodes in the tree is `n`.
- `2 <= n <= 10^5`
- `1 <= Node.val <= n`
- All the values in the tree are **unique**.
- `1 <= startValue, destValue <= n`
- `startValue != destValue`

## 解決思路
此題我們一開始分別針對`startValue`與`destValue`求得路徑`sPath`與`dPath`。我們假設路徑如下:

sPath = "LLLRRLR"
dPath = "LLLLRRL"

第一步我們忽略共同前綴"LLL"，其代表兩節點之最小共同祖先到樹根之路徑，因此無需考慮。

之後針對sPath的剩餘字串("RRLR")長度，建構相同長度的'U'路徑，放入解答中得到"UUUU"，其代表從start節點爬到最小共同祖先所需之路徑。

最後只需要將dPath剩餘字串(最小共同祖先到dest節點之路徑)append到當前解答之後即可得到"UUUULRRL"之最終解。

程式中我們為了避免memory limit exceeded，採用buttom-up的路徑建構方式以節省記憶體開銷。
