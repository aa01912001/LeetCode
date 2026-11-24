Problem Number: 3411. Maximum Subarray With Equal Products

Difficulty: `Easy`

## Problem Description

You are given an array of **positive** integers `nums`.

An array `arr` is called **product equivalent** if `prod(arr) == lcm(arr) * gcd(arr)`, where:

* `prod(arr)` is the product of all elements of `arr`.
* `gcd(arr)` is the GCD of all elements of `arr`.
* `lcm(arr)` is the LCM of all elements of `arr`.

Return the length of the **longest product equivalent** subarray of `nums`.

**Example 1:**
```
Input: nums = [1,2,1,2,1,1,1]

Output: 5

Explanation: 

The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
```
**Constraints:**

- `2 <= nums.length <= 100`
- `1 <= nums[i] <= 10`

## Solution Intuition

We can simply use nested for loops to calculate `prod`, `gcd`, and `lcm` for each subarray `arr`.