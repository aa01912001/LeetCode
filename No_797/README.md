題號: 797. All Paths From Source to Target

難度: Medium

## 問題描述
Given a directed acyclic graph (**DAG**) of `n` nodes labeled from 0 to n - 1, find all possible paths from node `0` to node `n - 1`, and return them in any order.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` (i.e., there is a directed edge from node `i` to node `graph[i][j]`).

Example 1:
![](https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg)
```
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```
---
## 解決思路
此題可利用DFS去遍歷可走的路徑，當我們走到一個節點後就會去搜尋它所有連到的節點並遞迴搜尋之。當走到目的節點(終止條件)後，就把此路徑(存放於sol變數)加進欲回傳的解答(存放於ret變數)中。