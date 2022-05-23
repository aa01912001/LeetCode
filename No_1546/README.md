題號: 1546. Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
難度: Medium

## 問題描述

Given an array `nums` and an integer `target`, return the maximum number of **non-empty non-overlapping** subarrays such that the sum of values in each subarray is equal to `target`.

**Example 1:**
```
Input: nums = [-1,3,5,1,4,2,-9], target = 6
Output: 2
Explanation: There are 3 subarrays with sum equal to 6.
([5,1], [4,2], [3,5,1,4,2,-9]) but only the first 2 are non-overlapping.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `0 <= target <= 10^6`

---
## 解決思路

此題可利用`unordered_map<int, int>`的結構來紀錄`nums`之prefix sum與其對應之index(假如有重複的prefix sum值，那麼應該紀錄index較大的那個，以盡量縮短涵蓋範圍)，之後當我們遍歷到`nums[i]`時，就去檢查`當前prefix sum - target`是否存在於map當中，若有的話(代表有個區間和為`target`)，則查看此區間是否與上個區間重疊(因此程式中要去紀錄前一個合法子陣列之最後位置)，若無，則將解答值加1。
