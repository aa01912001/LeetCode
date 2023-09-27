題號: 75. Sort Colors
難度: Medium

## 問題描述
Given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place** so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers `0`, `1`, and `2` to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

**Example 1:**
```
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 300`
- `nums[i]` is either `0`, `1`, or `2`.

**Follow up:** Could you come up with a one-pass algorithm using only constant extra space?

## 解決思路
此題我們透過two pointer的方式，令`indexZero`指向即將要擺放0的前一個位置，`indexTwo`指向即將要擺放2前一個位置，我們初始化`indexZero = -1`、`indexTwo = nums.size()`

之後我們遍歷`nums`，並分為兩個cases:

1. `nums[i] == 0`: `swap(nums[++indexZero], nums[i])`
2. `nums[i] == 2`: `swap(nums[--indexTwo], nums[i])`

之後若`i == indexZero || nums[i] == 1`代表我們可以往下一個元素去考進行交換，因此我們將`i`加1。