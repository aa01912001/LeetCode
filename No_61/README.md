題號: 61. Rotate List

難度: Medium

## 問題描述

Given the `head` of a linked list, rotate the list to the right by `k` places.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)

```
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 500]`.
- `-100 <= Node.val <= 100`
- `0 <= k <= 2 * 10^9`


---
## 解決思路

此題我們需要先將list的長度計算出來(假設為`len`)後再找出`len-(k%len)`的位置(假設為`h1`)，代表執行rotate之後的新head。之後將list最後的節點接到`head`，`h1`的前一個節點接到nullptr並返回`h1`即可。


