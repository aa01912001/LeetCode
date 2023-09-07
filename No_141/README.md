題號: 141. Linked List Cycle
難度: Easy

## 問題描述
Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. **Note that** `pos` **is not passed as a parameter**.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

**Example 1:**
![](https://hackmd.io/_uploads/Bk4HbCLRh.png)
```
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
```
**Constraints:**

- The number of the nodes in the list is in the range `[0, 10^4]`.
- `-10^5 <= Node.val <= 10^5`
- `pos` is `-1` or a **valid index** in the linked-list.

## 解決思路
此題我們利用準備兩個指標:

`slow = head`
`fast = head->next`

其中，`slow`一次只會向前走一步，而`fast`則是兩步，若list中含有cycle，那麼`fast`勢必會和`slow`重疊，否則`fast`將會先走到nullptr。
