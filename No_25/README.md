題號: 25. Reverse Nodes in k-Group

難度: Hard

## 問題描述

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```

**Constraints:**

- The number of nodes in the list is in the range `sz`.
- `1 <= sz <= 5000`
- `0 <= Node.val <= 1000`
- `1 <= k <= sz`

---
## 解決思路

此題我們需要利用遞迴的策略將每遍歷到的k個節點做reverse。途中，我們利用`ListNode *preGroupTail`來記錄前一組的結尾節點，如此我們做完該組的reverse之後，就可以返回該組reverse之後的第一個節點，並嫁接到`preGroupTail`之後。

而我們也需要另外儲存第一組做reverse後的第一個節點，這樣結束之後才能返回整個list的開頭。



