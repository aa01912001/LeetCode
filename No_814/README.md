題號: 814. Binary Tree Pruning

難度: Medium

## 問題描述
We are given the head node `root` of a binary tree, where additionally every node's value is either a 0 or a 1.

Return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

(Recall that the subtree of a node X is X, plus every node that is a descendant of X.)

Example 1:
![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)
```
Input: [1,null,0,0,1]
Output: [1,null,0,null,1]
 
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

```

Note: 


- The binary tree will have at most `200 nodes`.
- The value of each node will only be `0` or `1`.



---
## 解決思路
此題可以利用遞迴的方式來遍歷每棵子樹，若某棵子樹之右子樹或左子樹不包含1，則將root之左節點或右節點指向`nullptr`，之後若左子樹和右子樹和自身節點值皆不包含1則返回`true`通知上層。而整個遞迴的終止條件為當前節點為`nullptr`則返回true。