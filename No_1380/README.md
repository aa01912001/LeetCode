題號: 1380. Lucky Numbers in a Matrix

難度: Easy

## 問題描述

Given a `m * n` matrix of **distinct** numbers, return all lucky numbers in the matrix in **any** order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

**Example 1:**


```
Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
Output: [15]
Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column
```


**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= n, m <= 50`
- `1 <= matrix[i][j] <= 10^5.`
- All elements in the matrix are distinct.



---
## 解決思路

此題我們只需要去找出每一row最小的數與每一column最大的數，將這些數放入`unordered_map<int, int>`中，最後找出value值為2的那些數即可(value等於2代表著此數在某個row為最小，且同時在某個column為最大)。

Note: 因為題目有說矩陣中的每一個數都不一樣，所以此方法才適用。



