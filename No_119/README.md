題號: 119. Pascal's Triangle II

難度: Easy

## 問題描述

Given an integer `rowIndex`, return the `rowIndexth` (**0-indexed**) row of the **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

![image alt](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

**Example 1:**

```
Input: rowIndex = 3
Output: [1,3,3,1]
```

**Constraints:**

- `0 <= rowIndex <= 33`



---
## 解決思路

此題只要以DP的方式利用已知的上一列來去計算下一列即可。