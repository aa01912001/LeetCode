題號: 1903. Largest Odd Number in String

難度: Easy

## 問題描述

You are given a string `num`, representing a large integer. Return the **largest-valued odd** integer (as a string) that is a **non-empty substring** of `num`, or an empty string `""` if no odd integer exists.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**


```
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```

**Constraints:**

- `1 <= num.length <= 10^5`
- `num` only consists of digits and does not contain any leading zeros.



---
## 解決思路

此題只要利用**greedy**的策略從num後面遍歷digit到頭即可，途中只要發現digit為奇數就返回從index 0 到此digit的index的子字串即可。


