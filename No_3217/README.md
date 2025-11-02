題號: 3217. Delete Nodes From Linked List Present in Array

難度: Medium

## 問題描述
## Problem Description

You are given an array of integers `nums` and the `head` of a linked list. Return the `head` of the modified linked list after **removing** all nodes from the linked list that have a value that exists in `nums`.

**Example 1:**
![linkedlistexample0](https://hackmd.io/_uploads/HyMnMSEkZe.png)
```
Input: nums = [1,2,3], head = [1,2,3,4,5]
Output: [4,5]
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- All elements in `nums` are unique.
- The number of nodes in the given list is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^5`
- The input is generated such that there is at least one node in the linked list that has a value not present in `nums`.

**解決思路:**

我們首先將`nums`轉換成hash set以利後續加速檢查，之後開始從頭遍歷並依序刪除存在於set的節點即可。