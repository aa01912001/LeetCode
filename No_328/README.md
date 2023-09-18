題號: 328. Odd Even Linked List
難度: Medium

## 問題描述
Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in `O(1)` extra space complexity and `O(n)` time complexity.

**Example 1:**
![](https://hackmd.io/_uploads/rkHQJSBJ6.jpg)
```
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

**Constraints:**

- The number of nodes in the linked list is in the range `[0, 10^4]`.
- `-10^6 <= Node.val <= 10^6`

## 解決思路
此題我們只需要準備兩個指標，分別指向odd list與even list的尾端，並不斷的對原list進行串接後，最終再將even list接在odd list後即可。