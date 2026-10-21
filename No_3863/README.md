Problem Number: 3863. Minimum Operations to Sort a String

Difficulty: `Medium`

## Problem Description

You are given a string `s` consisting of lowercase English letters.

In one operation, you can select any **substring** of `s` that is **not** the entire string and **sort** it in **non-descending alphabetical** order.

Return the **minimum** number of operations required to make `s` sorted in **non-descending** order.
If it is not possible, return -1.


**Example 1:**
```
Input: s = "dog"

Output: 1

Explanation:

- Sort substring "og" to "go".
- Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.

```
**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only lowercase English letters.

**Intuition:**

By observation, we can know that the maximum number of operations for a given string `s` is at most 3, because we can always choose a substring of length $n - 1$ to perform the operation.

Therefore, we only need to consider which conditions will yield an answer of `-1`, `0`, `1`, `2`, or `3`:

- **0**: The string `s` is already sorted.
- **-1**: The length of the given string `s` is 2 and it is not sorted.
- **1**: None of the above conditions are met, and either `s[0] == min_val` or `s[-1] == max_val`. In this case, we only need to sort the remaining substring of length $n - 1$.
- **2**: None of the above conditions are met, and there exists a minimum character (`min_val`) or a maximum character (`max_val`) within the middle portion (`s[1]` to `s[n - 2]`).
  - **Why 2 operations?**
    1. **Operation 1 (Relocate Extreme Value)**: 
       - If `min_val` is in the middle, we can select a proper prefix `s[0 : i+1]` (which excludes `s[n-1]`) and sort it. Sorting this substring moves `min_val` directly to the very first position (`s[0]`).
       - If `max_val` is in the middle, we can select a proper suffix `s[i : n]` (which excludes `s[0]`) and sort it. Sorting this substring moves `max_val` directly to the very last position (`s[n-1]`).
    2. **Operation 2 (Sort Remaining Substring)**: 
       - Once `min_val` is anchored at `s[0]` (or `max_val` at `s[n-1]`), the string meets the condition for **Case 1**.
       - We can then perform 1 final operation on the remaining substring (`s[1 : n]` or `s[0 : n-1]`) to sort the entire string.
    - **Why MUST a minimum or maximum character exist in the middle for the answer to be 2?**
        - To sort the entire string in **2 operations**, the **1st operation MUST move at least one extreme value (`min_val` or `max_val`) to its correct final end** (`s[0]` or `s[n-1]`).
        - If `min_val` (or `max_val`) is in the middle, we can select a proper prefix (or suffix) containing it, so sorting that substring relocates `min_val` to `s[0]` (or `max_val` to `s[n-1]`).
        - **Conversely, if NO extreme value is in the middle**, then `s[0]` MUST be `max_val` and `s[n-1]` MUST be `min_val`. Because we cannot select the entire string, **no single operation can directly move `min_val` to `s[0]` or `max_val` to `s[n-1]`**. Thus, 2 operations are mathematically impossible, making 3 operations required.
- **3**: None of the above conditions are met.