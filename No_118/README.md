題號: 118. Pascal's Triangle

難度: Easy

## 問題描述
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example 1:
```
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
```

---
## 解決思路
此題可以看出Pascal's Triangle為一正三角形，我們只需利用兩層for loop即可填入每一格的解。其中每一格ret[i][j]為前一row之ret[i-1][j-1] + ret[i-1][j]之值，但若j為邊界則此格設為1。