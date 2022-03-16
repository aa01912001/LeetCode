題號: 1171. Remove Zero Sum Consecutive Nodes from Linked List
難度: Medium

## 問題描述

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

**Example 1:**
```
Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
```

**Constraints:**

- The given linked list will contain between `1` and `1000` nodes.
- Each node in the linked list has `-1000 <= node.val <= 1000`.

---
## 解決思路

此題我們可以藉由`unordered_map<int, ListNode*>`將list中的prefix sum與其相對應節點記錄起來，只要在後續中能夠找到同樣的prefix sum，代表兩相同prefix sum間有著一段總和為0之連續節點，因此我們就能透過map取出具有該prefix sum之節點並進行串接。

Note: 我們在排除Zero Sum Consecutive Nodes時，也必須將由這些節點所構成之prefix sum從map中刪除，以避免重覆考慮造成錯誤。