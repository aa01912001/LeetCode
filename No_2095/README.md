題號: 2095. Delete the Middle Node of a Linked List
難度: Medium

## 問題描述

You are given the `head` of a linked list. **Delete** the **middle node**, and return the `head` of the modified linked list.
 
The **middle node** of a linked list of size `n` is the` ⌊n / 2⌋th` node from the **start** using **0-based indexing**, where `⌊x⌋` denotes the largest integer less than or equal to `x`.

- For `n` = `1`, `2`, `3`, `4`, and `5`, the middle nodes are `0`, `1`, `1`, `2`, and `2`, respectively.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/11/16/eg1drawio.png)
```
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
```


**Constraints:**

- The number of nodes in the list is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`

---
## 解決思路

此題我們可以藉由two pointers的方式值準備兩個初始指標，分別為：

1. `ListNode* slower = head`
2. `ListNode* faster = head->next`

在`faster->next`與`faster->next->next`不等於nullptr的情況下，每次都讓faster比slower多前進一格，如此，最終`slower->next`就會是**middle node**。