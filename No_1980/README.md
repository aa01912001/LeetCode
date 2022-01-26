題號: 1980. Find Unique Binary String
難度: Medium

## 問題描述

Given an array of strings `nums` containing `n` **unique** binary strings each of length `n`, return a binary string of length `n` that **does not appear** in `nums`. If there are multiple answers, you may return `any` of them.

**Example 1:**
```
Input: nums = ["01","10"]
Output: "11"
Explanation: "11" does not appear in nums. "00" would also be correct.
```


**Constraints:**

- `n == nums.length`
- `1 <= n <= 16`
- `nums[i].length == n`
- `nums[i]` is either `'0'` or `'1'`.
- All the strings of `nums` are **unique**.

---
## 解決思路

此題我們可以針對每個索引值`0~n-1`來對`nums[i][i]`做判斷，可分為兩種情況：

1. `nums[i][i] == '0'`：
    使答案字串中第`i`個位置等於`'1'`

2. `nums[i][i] == '1'`：
    使答案字串中第`i`個位置等於`'0'`
    
這種方式會使最終的字串與每個`nums[i]`都不一樣，且其長度仍為`n`