題號: 2181. Merge Nodes in Between Zeros
難度: Medium

## 問題描述

You are given the `head` of a linked list, which contains a series of integers **separated** by `0`'s. The **beginning** and **end** of the linked list will have `Node.val == 0`.

For **every** two consecutive `0`'s, **merge** all the nodes lying in between them into a single node whose value is the **sum** of all the merged nodes. The modified list should not contain any `0`'s.

Return the head of the modified linked list.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2022/02/02/ex1-1.png)

```
Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
```


**Constraints:**

- The number of nodes in the list is in the range `[3, 2 * 10^5]`.
- `0 <= Node.val <= 1000`
- There are `no` two consecutive nodes with `Node.val == 0`.
- The **beginning** and **end** of the linked list have `Node.val == 0`.

---
## 解決思路

此題我們只需要在遍歷linked list的過程中將那些介於0節點間的節點之數做累加後，再進行串接即可，例如：

`rear(前一個0節點) -> 1 -> 2 -> 3 -> 0 -> ... -> 0`

累加1、2、3為6，並將此值替換後面的0節點，如下所示：

`rear(前一個0節點) -> 1 -> 2 -> 3 -> 6 -> ... -> 0`

之後將rear與後一個0節點串接即可，如下所示：

`rear(前一個0節點) -> 6 -> ... -> 0`

只要將每一段非零節點進行如上處理，即可得到最終所需的linked list。

