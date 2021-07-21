題號: 86. Partition List

難度: Medium

## 問題描述

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```


**Constraints:**

- The number of nodes in the list is in the range `[0, 200]`.
- `-100 <= Node.val <= 100`
- `-200 <= x <= 200`

---
## 解決思路

此題只需要將此linked list遍歷一次，同時形成一條節點值皆小於`x`的linked list和節點值皆大於等於`x`的linked list後，再把第二條接在第一條尾部即可。



