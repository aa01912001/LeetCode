題號: 1318. Minimum Flips to Make a OR b Equal to c

難度: Medium

## 問題描述

Given 3 positives numbers `a`, `b` and `c`. Return the minimum flips required in some bits of `a` and `b` to make ( `a` OR `b` == `c` ). (bitwise OR operation).
Flip operation consists of change **any** single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/01/06/sample_3_1676.png)

```
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
```


**Constraints:**

- `1 <= a <= 10^9`
- `1 <= b <= 10^9`
- `1 <= c <= 10^9`


---
## 解決思路

此題只要針對`a`、`b`、`c`中的各個bit去做判斷即可，過程中將`c`的最右bit分為0和1的cases去做處理。
