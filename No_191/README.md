題號: 191. Number of 1 Bits
難度: Easy

## 問題描述

Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

**Note:**

- Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
- In Java, the compiler represents the signed integers using `2's complement notation`. Therefore, in **Example 1**, the input represents the signed integer. `-3`.

**Example 1:**
```
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
```
**Constraints:**

- The input must be a **binary string** of length `32`.

---
## 解決思路

此題我們只需要每次執行`n &= n - 1`即可消除一個最後面的1，因此我們重複執行此運算直到`n`變為0即可。而我們最後只需要返回執行此運算的次數。