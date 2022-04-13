題號: 82. Remove Duplicates from Sorted List II
難度: Medium

## 問題描述

Given the `head` of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list **sorted** as well.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)
```
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 300]`.
- `-100 <= Node.val <= 100`
- The list is guaranteed to be **sorted** in ascending order.

---
## 解決思路

此題我們可利用two pointers的方式進行duplicates之排除，程式中我們利用`pre`指向前一個unique node，並且利用`tmp`查找`pre`之後的一段節點是否為duplicates，所是的話就將`pre->next`指向這段duplicates後的節點，反之，若`pre->next`為unique node，則`pre = pre->next`。

