題號: 15. 3Sum
難度: Medium

## 問題描述

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

**Example 1:**
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```
**Constraints:**

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

---
## 解決思路

此題我們可以先對`nums`進行遞增sorting，之後每次循序固定一數(`nums[i]`)，再接著利用two pointers的方式尋找後續數組中和為`-1*nums[i]`的pair即可。

過程中，若我們發現`nums[i]`已經為正數，代表後續的數皆為正數，因此不可能找出總和為0的triplet，因此直接返回解答即可。