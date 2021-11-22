題號: 1014. Best Sightseeing Pair

難度: Medium

## 問題描述

You are given an integer array `values` where values[i] represents the value of the `ith` sightseeing spot. Two sightseeing spots `i` and `j` have a **distance** `j - i` between them.

The score of a pair (`i < j`) of sightseeing spots is `values[i] + values[j] + i - j`: the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

**Example 1:**

```
Input: values = [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
```

**Constraints:**

- `2 <= values.length <= 5 * 10^4`
- `1 <= values[i] <= 1000`

---
## 解決思路

此題我們可以使用DP的策略，想法如下:

考慮某個數`values[j]`，我們需要為其找出一個`values[i]`其向後走到index j仍然保持最大值，也就是:

對於`values[i+1]`來說，`values[i+1] + values[i] + (i-(i+1))`相當於考慮`values[i] - 1`，也就是`values[i]`退化了1。

對於`values[i+2]`來說，`values[i+2] + values[i] + (i-(i+2))`相當於考慮`values[i] - 2`，也就是`values[i]`退化了2。
.
.
.
對於`values[i+n]`來說，`values[i+n] + values[i] + (i-(i+n))`相當於考慮`values[i] - n`，也就是`values[i]`退化了n。

所以我們在程式中維護了一個變數`preMax`用來保存所遍歷到的最大值，並且每往後走一個索引就將其值減一，並且與當前索引的value去取最大值。

另外我們也用`ret`變數儲存當前最大的**Sightseeing Pair**值。











