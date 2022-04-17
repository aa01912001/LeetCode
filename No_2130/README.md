題號: 2130. Maximum Twin Sum of a Linked List
難度: Medium

## 問題描述

In a linked list of size `n`, where `n` is **even**, the `ith` node (**0-indexed**) of the linked list is known as the **twin** of the `(n-1-i)th` node, if `0 <= i <= (n / 2) - 1`.

- For example, if `n = 4`, then node `0` is the twin of node `3`, and node `1` is the twin of node `2`. These are the only nodes with twins for `n = 4`.

The **twin sum** is defined as the sum of a node and its twin.

Given the `head` of a linked list with even length, return the **maximum twin sum** of the linked list.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/12/03/eg1drawio.png)
```
Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 
```

**Constraints:**

- The number of nodes in the list is an **even** integer in the range `[2, 10^5]`.
- `1 <= Node.val <= 10^5`


---
## 解決思路

此題我們可透過`slower`與`faster`指標找出此list後半段的開頭，之後我們將後半段的list做reverse後，再將兩指標依次前進相加並同時比較最大值即可。

