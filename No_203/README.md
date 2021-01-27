題號: 203. Remove Linked List Elements

難度: Easy

## 問題描述
Remove all elements from a linked list of integers that have value **val**.

Example 1:
```
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
```

---
## 解決思路
此題首先將head移動到具有非`val`值的節點後，再利用兩個`pre`與`next`指標將剩餘的linked link搜尋比較即可。