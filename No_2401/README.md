題號: 2401. Longest Nice Subarray
難度: Medium

## 問題描述
You are given an array `nums` consisting of **positive** integers.

We call a subarray of `nums` **nice** if the bitwise **AND** of every pair of elements that are in **different** positions in the subarray is equal to `0`.

Return the length of the **longest** nice subarray.

A **subarray** is a **contiguous** part of an array.

**Note** that subarrays of length `1` are always considered nice.

**Example 1:**
```
Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

## 解決思路
此題我們只需要利用sliding window的方式判斷每個子陣列的元素全部AND是否為0即可。

同時我們也需要一邊將目前AND為0的元素全部OR起來，以便判斷該值(假設為，`tmp`)是否可與下個元素做AND運算後仍為0。

若`tmp`與當前元素之AND運算不為0，我們需要將`tmp`更新為`tmp ^ nums[left]`使`left`向右進一位後，繼續進行判斷。