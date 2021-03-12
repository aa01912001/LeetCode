題號: 1721. Swapping Nodes in a Linked List

難度: Medium

## 問題描述
You are given the `head` of a linked list, and an integer `k`.

Return the head of the linked list after **swapping** the values of the `kth` node from the beginning and the `kth` node from the end (the list is **1-indexed**).

Example 1:
![](https://assets.leetcode.com/uploads/2020/09/21/linked1.jpg)
```
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
```

Constraints:

- The number of nodes in the list is `n`.
- `1 <= k <= n <= 105`
- `0 <= Node.val <= 100`


---
## 解決思路
此題可用一個`vector<ListNode*>`的結構來儲存每個節點的位址，因為將linked list轉變成vector的原因，我們能夠迅速地找到目標節點，並交換其值。