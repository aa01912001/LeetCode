題號: 817. Linked List Components
難度: Medium

## 問題描述

You are given the `head` of a linked list containing unique integer values and an integer array `nums` that is a subset of the linked list values.

Return the number of connected components in `nums` where two values are connected if they appear **consecutively** in the linked list.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/07/22/lc-linkedlistcom1.jpg)

```
Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
```


**Constraints:**

- The number of nodes in the linked list is `n`.
- `1 <= n <= 10^4`
- `0 <= Node.val < n`
- All the values `Node.val` are **unique**.
- `1 <= nums.length <= n`
- `0 <= nums[i] < n`
- All the values of `nums` are **unique**.

---
## 解決思路

此題我們只需要利用`unordered_map<int, bool> hmap;`的結構將`nums`中的所有數記錄起來，之後遍歷linked list時只要檢查當前節點是否存在於`hmap`中即可。另外程式中我們使用`bool inNums`來記錄前一個節點是否同樣屬於存在於`nums`中的節點，並根據相應情況將components的個數加1。


