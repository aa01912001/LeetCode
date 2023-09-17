題號: 19. Remove Nth Node From End of List
難度: Medium

## 問題描述
Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Example 1:**
![](https://hackmd.io/_uploads/SkupXb4kT.jpg)
```
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Constraints:**

- The number of nodes in the list is `sz`.
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

**Follow up:** Could you do this in one pass?

## 解決思路
此題我們採用快慢指標的方式。一開始讓`fast`與`slow`相差`n`個節點，之後兩個指標一次都向前一步，直到`fast->next == nullptr`，此時我們就可以透過`slow`找到目標節點的位置。