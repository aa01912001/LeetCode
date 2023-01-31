題號: 918. Maximum Sum Circular Subarray
難度: Medium

## 問題描述
Given a **circular integer array** `nums` of length `n`, return the maximum possible sum of a non-empty **subarray** of `nums`.

A **circular array** means the end of the array connects to the beginning of the array. Formally, the next element of `nums[i]` is `nums[(i + 1) % n]` and the previous element of `nums[i]` is `nums[(i - 1 + n) % n]`.

A **subarray** may only include each element of the fixed buffer `nums` at most once. Formally, for a subarray `nums[i], nums[i + 1], ..., nums[j]`, there does not exist `i <= k1`, `k2 <= j` with `k1 % n == k2 % n`.

**Example 1:**
```
Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
```

**Constraints:**

- `n == nums.length`
- `1 <= n <= 3 * 10^4`
- `-3 * 10^4 <= nums[i] <= 3 * 10^4`

---
## 解決思路
我們我們可以分為兩個case:

1. 答案來自於一般的**maximum subarray sum**
2. 答案來自於**array sum** - **minimum subarray sum**

而我們必須注意一個corner case;當陣列元素全為負數時，我們不能不選任何的元素，因此應該返回我們找到的**maximum subarray sum**。