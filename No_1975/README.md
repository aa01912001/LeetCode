題號: 1975. Maximum Matrix Sum
難度: Medium

## 問題描述

You are given an `n x n` integer `matrix`. You can do the following operation **any** number of times:

- Choose any two **adjacent** elements of `matrix` and **multiply** each of them by `-1`.

Two elements are considered **adjacent** if and only if they share a **border**.

Your goal is to **maximize** the summation of the matrix's elements. Return the **maximum** sum of the matrix's elements using the operation mentioned above.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/07/16/pc79-q2ex2.png)
```
Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
```
**Constraints:**

- `n == matrix.length == matrix[i].length`
- `2 <= n <= 250`
- `-10^5 <= matrix[i][j] <= 10^5`

---
## 解決思路

此題中，可以發現我們能夠透過將負數與任意相鄰正數進行運算以移動負號的位置，我們會盡量讓兩個負號相鄰以消去負號，因此我們只需要計算matrix中所有負數的個數，只要為偶數，我們最終就能夠消去所有的負數，反之，所有數中取絕對值最小的那個數最終就會成為負數而留下來，使得matrix sum最大。

值得注意的是，只要matrix中出現一個0，那麼所有的數最終就會成為正數，因為0乘上-1不會改變其值，因此我們可以讓所有負數與0相鄰以消去負號。