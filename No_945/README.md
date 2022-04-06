題號: 945. Minimum Increment to Make Array Unique
難度: Medium

## 問題描述

You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and increment `nums[i]` by `1`.

Return the minimum number of moves to make every value in `nums` **unique**.

**Example 1:**
```
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

---
## 解決思路

此題我們首先對`nums`做遞增排序，之後遍歷時只要發現`nums[i] <= nums[i-1]`，我們就將解答加上`nums[i-1]+nums[i]+1`(表示`nums[i]`應該移動之最小步數)且將`nums[i]`更新為`nums[i-1]+1`，如此最終即可使`nums`成為一個unique array。