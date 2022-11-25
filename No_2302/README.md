題號: 2302. Count Subarrays With Score Less Than K
難度: Hard

## 問題描述

The **score** of an array is defined as the **product** of its sum and its length.

- For example, the score of `[1, 2, 3, 4, 5]` is `(1 + 2 + 3 + 4 + 5) * 5 = 75`.

Given a positive integer array `nums` and an integer `k`, return the **number of non-empty subarrays** of `nums` whose score is **strictly less** than `k`.

A **subarray** is a contiguous sequence of elements within an array.

**Example 1:**
```
Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `1 <= k <= 10^15`

---
## 解決思路

此題我們只需要針對nums先進行prefix sum後，再以sliding window的方式針對每個window計算其score，並判斷是否小於`k`即可。

- 若當前window score小於`k`，則應該將解答加上合法之子陣列個數(為當前window長度)，並向右擴展window右邊界。
- 若當前window score大於等於`k`，則應該向右縮減window左邊界，直到window之score小於`k`，或者左邊界等於右邊界。