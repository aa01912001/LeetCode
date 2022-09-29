題號: 1760. Minimum Limit of Balls in a Bag
難度: Medium

## 問題描述

You are given an integer array `nums` where the `ith` bag contains `nums[i]` balls. You are also given an integer `maxOperations`.

You can perform the following operation at most `maxOperations` times:


- Take any bag of balls and divide it into two new bags with a **positive** number of balls.
    - For example, a bag of `5` balls can become two new bags of `1` and `4` balls, or two new bags of `2` and `3` balls.

Your penalty is the **maximum** number of balls in a bag. You want to **minimize** your penalty after the operations.

Return the minimum possible penalty after performing the operations.

**Example 1:**
```
Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= maxOperations, nums[i] <= 10^9`

---
## 解決思路

此題我們可以透過**binary search**來對**minimum penalty**進行猜測，假設我們的當前猜測minimum penalty為`mid`，對於每個大於`mid`的`nums[i]`來說(小於的不需進行分割)，其利用最少operation的分割次數為`ceil(nums[i]/mid)-1`，因此我們需要將所有`nums[i]`的最少分割次數加總起來(為`count`)，並判斷`count`是否大於`maxOperation`，若大於，則代表當前所猜測的數字太小，因此我們將`left = mid + 1`，否則我們將繼續尋找更小的可能性，即，`right = mid`。最終返回`right`為最終答案。