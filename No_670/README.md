題號: 670. Maximum Swap

難度: Medium

## 問題描述

You are given an integer `num`. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

**Example 1:**


```
Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
```

**Constraints:**

- `0 <= num <= 10^8`

---
## 解決思路

此題我們可以從最小的位數開始尋找當前最大的數字並存入`maxVal`變數中，一旦發現某個位數的數字小於`maxVal`，我們就將當前位置與`maxVal`的位置交換，並將解答暫時設為當前的數字。之後再交換一次復原數字並繼續尋找是否有更大的數字可做交換。如此搜尋到最後即可得到最佳解。







