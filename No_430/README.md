題號: 430. Flatten a Multilevel Doubly Linked List

難度: Medium

## 問題描述
You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.


Example 1:

```
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation:

The multilevel linked list in the input is as follows:

```
![](https://assets.leetcode.com/uploads/2018/10/12/multilevellinkedlist.png)

```
After flattening the multilevel linked list it becomes:
```
![](https://assets.leetcode.com/uploads/2018/10/12/multilevellinkedlistflattened.png)

Constraints:

- The number of Nodes will not exceed `1000`.
- `1 <= Node.val <= 10^5`
---
## 解決思路

此題可以透過遞迴的策略來遍歷每個節點，途中只要發現節點child不為nullptr，則優先遞迴搜尋child level。此外我們透過`Node* pre`參數來記錄原節點之下一節點(head->next)在遍歷完child level後要轉為連接的前一個節點(**也就是head->next->prev在遞迴遍歷完head->child後會有所變更**)。

**要注意遞迴完child level後要將原本head->child指向nullptr，否則會回報 invalid doubly linked list。**