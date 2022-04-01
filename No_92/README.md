題號: 92. Reverse Linked List II
難度: Medium

## 問題描述

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return the reversed list.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/02/19/rev2ex2.jpg)
```
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
```

**Constraints:**

- The number of nodes in the list is `n`.
- `1 <= n <= 500`
- `-500 <= Node.val <= 500`
- `1 <= left <= right <= n`

---
## 解決思路

此題我們可以利用遞迴的方式將`left`與`right`間的節點進行reverse。

在reverse的遞迴當中，我們使用`tmp`變數將當前節點原本之下一個節點記錄起來，並在遞迴返回後將`tmp->next`改為當前節點，以完成reverse操作，另外，我們遍歷到最後一個節點時，就將其下一個節點向前傳遞，使`left`節點能夠與其串接，並且我們將最後一個節點另外記錄下來(程式中儲存在`last`變數)，以便讓`left`的前一個節點進行串接。