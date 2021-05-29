題號: 1523. Count Odd Numbers in an Interval Range

難度: Easy

## 問題描述

Given two non-negative integers `low` and `high`. Return the count of odd numbers between `low` and `high` (inclusive).

Example 1:

```
Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
```

Constraints:

- `0 <= low <= high <= 10^9`



---
## 解決思路

此題先判斷`high-low`中的奇數個數後，再判斷`low`是否為奇數，之後加上去即可。