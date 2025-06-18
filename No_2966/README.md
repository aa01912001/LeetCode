題號: 2966. Divide Array Into Arrays With Max Difference

難度: Medium

## 問題描述
You are given an integer array `nums` of size `n` where `n` is a multiple of 3 and a positive integer `k`.

Divide the array `nums` into `n / 3` arrays of size **3** satisfying the following condition:

- The difference between any two elements in one array is **less than or equal** to `k`.

Return a **2D** array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return **any** of them.

**Example 1:**
```
Input: nums = [1,3,4,8,7,9,3,5,1], k = 2

Output: [[1,1,3],[3,4,5],[7,8,9]]

Explanation:

The difference between any two elements in each array is less than or equal to 2.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 10^5`
- `n` is a multiple of 3
- `1 <= nums[i] <= 10^5`
- `1 <= k <= 10^5`


**解決思路:**

對於每個分組來說，我們根本不需要理會中間的那個數，只需要在意最大值減去最小值是否滿足`k`即可，因此我們首先將`nums`進行排序，並依需三個元素為一組來檢查是否滿足`k`，若不合法則直接返回空陣列即可。