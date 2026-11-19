Problem Number: 2567. Minimum Score by Changing Two Elements

Difficulty: `Medium`

## Problem Description

You are given an integer array `nums`.

* The **low** score of `nums` is the **minimum** absolute difference between any two integers.
* The **high** score of `nums` is the **maximum** absolute difference between any two integers.
* The **score** of `nums` is the sum of the **high** and **low** scores.

Return the **minimum score** after **changing two elements** of `nums`.

**Example 1:**
```
Input: nums = [1,4,7,8,5]

Output: 3

Explanation:

- Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
- The low score is the minimum absolute difference: |6 - 6| = 0.
- The high score is the maximum absolute difference: |8 - 5| = 3.
- The sum of high and low score is 3.
```
**Constraints:**

- `3 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`


## Solution Intuition

First, we sort `nums` in ascending order. Since we can change at most two elements, we can **observe** that the minimum possible **high** score must come from one of the following three cases:

1. **Change the two smallest elements** to match the third element (`nums[2]`). Thus, the high score will be `nums[-1] - nums[2]` (the largest element minus the third element).
2. **Change the two largest elements** to match the third-to-last element (`nums[-3]`). Thus, the high score will be `nums[-3] - nums[0]` (the third-to-last element minus the smallest element).
3. **Change both the smallest and largest elements** to match their adjacent elements (`nums[1]` and `nums[-2]`, respectively). Thus, the high score will be `nums[-2] - nums[1]` (the second-to-last element minus the second element).

Notice that in all three cases, there will always be at least one duplicate pair in `nums` after the modifications, which guarantees that the **low** score is `0`. 

Therefore, the minimum value among the three high scores above will be our final answer.