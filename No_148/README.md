題號: 148. Sort List
難度: Medium

## 問題描述
Given the `head` of a linked list, return the list after sorting it in **ascending order**.

**Example 1:**
![](https://hackmd.io/_uploads/S1oJSg316.jpg)
```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

**Constraints:**

- The number of nodes in the list is in the range `[0, 5 * 10^4]`.
- `-10^5 <= Node.val <= 10^5`

**Follow up:** Can you sort the linked list in `O(n logn)` time and `O(1)` memory (i.e. constant space)?

## 解決思路
此題我們利用merge sort的方式，在每次遞迴中，將當前的list利用快慢指標的方式2分為兩條lists，之後對這兩條lists同樣繼續遞迴做sorting後，再將兩條排序好的lists進行merge即可。