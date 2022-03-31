題號: 2169. Count Operations to Obtain Zero
難度: Easy

## 問題描述

You are given **two non-negative** integers `num1` and `num2`.

In one **operation**, if `num1 >= num2`, you must subtract `num2` from `num1`, otherwise subtract `num1` from `num2`.

- For example, if `num1 = 5` and `num2 = 4`, subtract `num2` from `num1`, thus obtaining `num1 = 1` and `num2 = 4`. However, if `num1 = 4` and `num2 = 5`, after one operation, `num1 = 4` and `num2 = 1`.

Return the **number of operations** required to make either `num1 = 0` or `num2 = 0`.

**Example 1:**
```
Input: num1 = 2, num2 = 3
Output: 3
Explanation: 
- Operation 1: num1 = 2, num2 = 3. Since num1 < num2, we subtract num1 from num2 and get num1 = 2, num2 = 3 - 2 = 1.
- Operation 2: num1 = 2, num2 = 1. Since num1 > num2, we subtract num2 from num1.
- Operation 3: num1 = 1, num2 = 1. Since num1 == num2, we subtract num2 from num1.
Now num1 = 0 and num2 = 1. Since num1 == 0, we do not need to perform any further operations.
So the total number of operations required is 3.
```

**Constraints:**

- `0 <= num1, num2 <= 10^5`

---
## 解決思路

若`num1 > num2`，我們應該將解答加上`num1 / num2`之商數後(代表`num1`連續減掉若干次後才會小於`num2`)，再將`num1`更新為`num1 / num2`之餘數，反之亦同。

如此最後必有一數先變為0，我們同時也取得正確的運算次數。