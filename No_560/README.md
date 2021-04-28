題號: 560. Subarray Sum Equals K

難度: Medium

## 問題描述
Given an array of integers `nums` and an integer `k`, return the total number of continuous subarrays whose sum equals to `k`.

Example 1:

```
Input: nums = [1,1,1], k = 2
Output: 2
```

Constraints:

- `1 <= nums.length <= 2 * 10^4`
-  `-1000 <= nums[i] <= 1000`
- `-10^7 <= k <= 10^7`

---
## 解決思路

此題可利用`unordered_map<int, int>`紀錄曾經出現過的sum值(sum of nums[0] ~ nums[x])，之後用累加的方式計算nums[0] ~ nums[i]的sum值後再判斷是否有sum-k的值曾經出現過。