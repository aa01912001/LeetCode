題號: 1558. Minimum Numbers of Function Calls to Make Target Array

難度: Medium

## 問題描述

![image alt](https://assets.leetcode.com/uploads/2020/07/10/sample_2_1887.png)

Your task is to form an integer array `nums` from an initial array of zeros `arr` that is the same size as `nums`.

Return the minimum number of function calls to make `nums` from `arr`.

The answer is guaranteed to fit in a 32-bit signed integer.

**Example 1:**

```
Input: nums = [1,5]
Output: 5
Explanation: Increment by 1 (second element): [0, 0] to get [0, 1] (1 operation).
Double all the elements: [0, 1] -> [0, 2] -> [0, 4] (2 operations).
Increment by 1 (both elements)  [0, 4] -> [1, 4] -> [1, 5] (2 operations).
Total of operations: 1 + 2 + 2 = 5.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`

---
## 解決思路

此題我們需要針對每個`nums[i]`逆轉回0。對於每個`nums[i]`我們需要將他一直除以2，作為`op == 2`的發生，而途中若發現`nums[i]`為奇數，就將解答值加1(因為代表此數需要單獨執行`op == 1`)。我們需要紀錄每個`nums`中的數所需要的`op == 2`次數，最後將最大的發生次數加入解答(因為op == 2的運算是共享的，所以只需要加入發生最多的那個次數即可)。


