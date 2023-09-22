題號: 24. Swap Nodes in Pairs
難度: Medium

## 問題描述
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example 1:**
![](https://hackmd.io/_uploads/SyhJQo91T.jpg)
```
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 100]`.
- `0 <= Node.val <= 100`

## 解決思路
此題我們利用遞迴策略，優先將後續的list做完swap後，再藉由返回的新head，將當前兩個nodes做交換即可。