Problem Number: 2089. Find Target Indices After Sorting Array

Difficulty: `Easy`

## Problem Description

You are given a **0-indexed** integer array `nums` and a target element `target`[cite: 2].

A **target index** is an index `i` such that `nums[i] == target`[cite: 2].

Return *a list of the target indices of* `nums` *after sorting* `nums` *in non-decreasing order*[cite: 2]. *If there are no target indices, return an empty list*[cite: 2]. *The returned list must be sorted in* **increasing** *order*[cite: 2].


**Example 1:**
```
Input: nums = [1,2,5,2,3], target = 2
Output: [1,2]
Explanation: After sorting, nums is [1,2,2,3,5].
The indices where nums[i] == 2 are 1 and 2.
```
**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i], target <= 100`

**Intuition:**

For this problem, we don't need to sort the given array. We can simply iterate through the array to count how many items are less than `target` and how many items are equal to `target`. 

Therefore, the target indices after sorting will range from `less_count` to `less_count + target_count` (exclusive).