題號: 147. Insertion Sort List
難度: Medium

## 問題描述

Given the `head` of a singly linked list, sort the list using **insertion sort**, and return the sorted list's head.

The steps of the **insertion sort** algorithm:

1. Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
3. It repeats until no input elements remain.

The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

![image alt](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/03/04/sort1linked-list.jpg)
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```


**Constraints:**

- The number of nodes in the list is in the range `[1, 5000]`.
- `-5000 <= Node.val <= 5000`

---
## 解決思路

此題我們可以利用兩個`ListNode *minNode, *tail`來執行in-place的排序，其中，minNode代表以排序好的linked list之最前端節點，而tail則為最後的節點，每次針對tail的後一個節點(`target`)我們可以分為三種情況：

1. `target`的值大於`tail`：
    我們只要移動`tail`指標至`target`即可
2. `target`的值小於`minNode`：
    將`target`移動至第一個並將`minNode`移至`target`，而`tail`無須移動
3. `target`的值介於`minNode`與`tail`：
    找出其適當位置後插入，`minNode`與`tail`無須移動
    
經由反覆做insertion，直到`tail->next == nullptr`後，即可得到排序好的linked list
