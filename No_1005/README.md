題號: 1005. Maximize Sum Of Array After K Negations

難度: Easy

## 問題描述

Given an integer array `nums` and an integer `k`, modify the array in the following way:

- choose an index `i` and replace `nums[i]` with `-nums[i]`.

You should apply this process exactly `k` times. You may choose the same index `i `multiple times.

Return the largest possible sum of the array after modifying it in this way.

**Example 1:**

```
Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-100 <= nums[i] <= 100`
- `1 <= k <= 10^4`

---
## 解決思路

此題我們只需要將`nums`做sort之後，將`k`分配給所有的負數即可。若發現每個數被轉換為正數後，`k`值仍有剩，那就把剩下的`k`值分配給絕對值對最低的那個數即可。
