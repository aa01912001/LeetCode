題號: 23. Merge k Sorted Lists
難度: Hard

## 問題描述

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

**Example 1:**
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```
**Constraints:**

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in **ascending order**.
- The sum of `lists[i].length` will not exceed `10^4`.

---
## 解決思路

此題我們透過**divide and conquer**策略將k個list以**merge sort**的方式進行遞迴處理；在`divide`中，我們將`lists[start]`到`lists[end]`分為兩半繼續進行遞迴，而左、右兩半會分別傳回已排序好的list，我們則將此兩個list傳入到`merge`中進行合併，並傳回最終排序好的一條list。