題號: 1458. Max Dot Product of Two Subsequences

難度: `Hard`

## 問題描述

Given two arrays `nums1` and `nums2`.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, `[2,3,5]` is a subsequence of `[1,2,3,4,5]` while `[1,5,3]` is not).


**Example 1:**
```
Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
```
**Constraints:**

- `1 <= nums1.length, nums2.length <= 500`
- `-1000 <= nums1[i], nums2[i] <= 1000`

**解決思路:**

此題為單純的DP題，我們令`dp[i][j]`為使用`nums1[0..i]` 與`nums2[0..j]`，所能得到的「非空 subsequence」最大 dot product。

其轉移方程概念如下:

```
pair = `nums1[i] * nums2[j]`

dp[i][j] = max(
    pair,                       # 單獨從這一對開始
    pair + dp[i-1][j-1],        # 延續之前的 subsequence
    dp[i-1][j],                 # 不用 nums1[i]
    dp[i][j-1],                 # 不用 nums2[j]
)
```

最後`dp[-1][-1]`即為nums1與nums2所能形成的最大dot product。