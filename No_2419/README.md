題號: 2419. Longest Subarray With Maximum Bitwise AND

難度: Medium

## 問題描述
You are given an integer array `nums` of size `n`.

Consider a **non-empty** subarray from `nums` that has the **maximum** possible **bitwise AND**.

- In other words, let `k` be the maximum value of the bitwise AND of **any** subarray of `nums`. Then, only subarrays with a bitwise AND equal to `k` should be considered.

Return the length of the **longest** such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A **subarray** is a contiguous sequence of elements within an array.

**Example 1:**
```
Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^6`

**解決思路:**

我們知道Bitwise AND 的性質如下:
- AND 的結果會隨著子陣列長度增加而變小或一樣，不會變大。
- 最大AND值通常出現在單個數字，或一段連續完全相同的高位數組成的子陣列中。

因此我只要知道陣列中的最大值`max_val`後，去尋找所有數皆等於`max_val`的最長子陣列即可。