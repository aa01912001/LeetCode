題號: 2487. Remove Nodes From Linked List
難度: Medium

## 問題描述
You are given the `head` of a linked list.

Remove every node which has a node with a **strictly greater** value anywhere to the right side of it.

Return the `head` of the modified linked list.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2022/10/02/drawio.png)
```
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.
```

**Constraints:**

- The number of the nodes in the given list is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`

---
## 解決思路

此題我們可以使用monotonic stack的技巧，在stack中儲存遞減的節點，一旦當前節點大於stack top的話，就不斷pop節點，直到stack top的節點值大於等於當前節點，最後只需要將所有stack中所剩餘的遞減節點串聯起來並回傳即可。