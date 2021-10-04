題號: 143. Reorder List

難度: Medium

## 問題描述

You are given the head of a singly linked-list. The list can be represented as:

```
L0 → L1 → … → L(n - 1) → Ln
```

Reorder the list to be on the following form:

```
L0 → Ln → L1 → L(n - 1) → L2 → L(n - 2) → …
```

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg)

```
Input: head = [1,2,3,4]
Output: [1,4,2,3]
```

**Constraints:**

- The number of nodes in the list is in the range `[1, 5 * 10^4]`.
- `1 <= Node.val <= 1000`



---
## 解決思路

此題我們先利用two pointer策略找出此list的中點後，再利用遞迴將中間節點到最後節點的list做reverse。最後再將兩條list合併即可。


