題號: 1019. Next Greater Node In Linked List

難度: Medium

## 問題描述
We are given a linked list with `head` as the first node.  Let's number the nodes in the list: `node_1, node_2, node_3, ...` etc.

Each node may have a next larger **value**: for `node_i`, `next_larger(node_i)` is the `node_j.val` such that `j > i`, `node_j.val > node_i.val`, and `j` is the smallest possible choice.  If such a `j` does not exist, the next larger value is `0`.

Return an array of integers `answer`, where `answer[i] = next_larger(node_{i+1})`.

Note that in the example **inputs** (not outputs) below, arrays such as `[2,1,5]` represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.

Example 1:
```
Input: [2,7,4,3,5]
Output: [7,0,5,5,0]
```

Note:

1. `1 <= node.val <= 10^9` for each node in the linked list.
2. The given list has length in the range `[0, 10000]`.



---
## 解決思路
此題我們利用一個`stack<pair<int, int>>`的結構來儲存尚未找到next greater node的節點與其索引值。我們再遍歷linked list的時候需要在欲返回的vector `ret`插入(push_back)`0`值，代表預設此節點找不到next greater node，之後比較stack的top來比較說此節點是不是之前節點的next greater node，若是則從stack中取出top並將其在返回vector中的對應index之值設為當前節點的值。