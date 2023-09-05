題號: 21. Merge Two Sorted Lists
難度: Easy

## 問題描述
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

**Example 1:**
![](https://hackmd.io/_uploads/Bkp2NQNC2.jpg)
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```
**Constraints:**

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

## 解決思路
此題我們首先準備一個**dummy node**，同時讓`pre`指標一開始指向該node。

之後我們只需要不斷比較當前`list1`與`list2`之節點值即可。

若`list1->val <= list2->val`:
    我們讓`pre->next`指向`list1`，並同時讓`list1`、`pre`向前一位，繼續比較。
    
反之若`list1->val > list2->val`，同理對`list2`操作。

如此我們最後可形成一條排序好的list，我們只需要返回`dummy->next`(最終list的頭節點)即可。
