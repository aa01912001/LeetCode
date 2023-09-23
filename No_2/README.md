題號: 2. Add Two Numbers
難度: Medium

## 問題描述
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**
![](https://hackmd.io/_uploads/Bk86dg21p.jpg)
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Constraints:**

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- It is guaranteed that the list represents a number that does not have leading zeros.

## 解決思路
此題我們透過遞迴的方式不斷將`l1`、`l2`的下一個節點以及carry(進位值)傳遞下去，並且在每個遞迴中，計算當前兩個節點以及carry的sum值後，再透過該sum值來建立一個新的節點進行串聯。