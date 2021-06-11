題號: 962. Maximum Width Ramp

難度: Medium

## 問題描述

Given an array `nums` of integers, a ramp is a tuple `(i, j)` for which `i < j` and `nums[i] <= nums[j]`.  The width of such a ramp is `j - i`.

Find the maximum width of a ramp in `nums`.  If one doesn't exist, return 0.


**Example 1:**

```
Input: nums = [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.
```

Constraints:

- `2 <= nums.length <= 50000`
- `2 <= nums.length <= 50000`

---
## 解決思路

此題我需要兩個額外的`vector<int>`:

- `leftMin` : 其中`leftMin[i]`代表，從`nums[0]~nums[i]`出現的最小值
- `rightMax` : 其中`rightMax[i]`代表，從`nums[n-1]~nums[i]`出現的最大值，其中n為`nums`之長度

之後我們從`leftMin[0]`與`rightMax[0]`來比較`leftMin[i]`與`rightMax[j]`。

若`leftMin[i] <= rightMax[j]`我們就將j加一，代表進一步找尋有更長的ramp，若`leftMin[i] > rightMax[j]`則將i加1，代表我們需要更小的值。而每次比較後我們就去執行`ret = max(ret, j-i-1)`將歷史最長ramp紀錄之。