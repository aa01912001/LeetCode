題號: 1669. Merge In Between Linked Lists

難度: Medium

## 問題描述
YYou are given two linked lists: `list1` and `list2` of sizes `n` and `m` respectively.

Remove `list1`'s nodes from the `ath` node to the `bth` node, and put `list2` in their place.

The blue edges and nodes in the following figure indicate the result:

![Example](https://assets.leetcode.com/uploads/2020/11/05/fig1.png)
*Build the result list and return its head*.

---
## 解決思路
我們只需要找出list1中第`a-1`個node與第`b+1`個node後，再將list2連接上(**需找出list2的最後一個node**)即可。

具體怎麼做直接看程式碼就懂了!!

