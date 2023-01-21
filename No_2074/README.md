題號: 2074. Reverse Nodes in Even Length Groups
難度: Medium

## 問題描述
You are given the `head` of a linked list.

The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (`1, 2, 3, 4, ...`). The length of a group is the number of nodes assigned to it. In other words,

- The `1st` node is assigned to the first group.

- The `2nd` and the `3rd` nodes are assigned to the second group.

The `4th`, `5th`, and `6th` nodes are assigned to the third group, and so on.

Note that the length of the last group may be less than or equal to `1 + the length of the second to last group`.

Reverse the nodes in each group with an even length, and return the `head` of the modified linked list.

**Example 1:**
![](https://i.imgur.com/y9kYdBo.png)
```
Input: head = [5,2,6,3,9,1,7,3,8,4]
Output: [5,6,2,3,9,1,4,8,3,7]
Explanation:
- The length of the first group is 1, which is odd, hence no reversal occurs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurs.
- The length of the last group is 4, which is even, hence the nodes are reversed.
```

**Constraints:**

- The number of nodes in the list is in the range `[1, 10^5]`.
- `0 <= Node.val <= 10^5`

---
## 解決思路

此題我們只需要一邊計算每個group的長度，並且將長度為偶數的group進行reverse即可，此題考察點僅在於是否熟悉sublist的reverse操作。