題號: 1630. Arithmetic Subarrays
難度: Medium

## 問題描述

A sequence of numbers is called `arithmetic` if it consists of at least two elements, and the difference between every two consecutive elements is the same. More formally, a sequence `s` is arithmetic if and only if `s[i+1] - s[i] == s[1] - s[0]` for all valid `i`.

For example, these are **arithmetic** sequences:
```
1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
```
The following sequence is not **arithmetic**:
```
1, 1, 2, 5, 7
```
You are given an array of `n` integers, `nums`, and two arrays of `m` integers each, `l` and `r`, representing the `m` range queries, where the `ith` query is the range `[l[i], r[i]]`. All the arrays are **0-indexed**.

Return a list of `boolean` elements `answer`, where `answer[i]` is `true` if the subarray `nums[l[i]], nums[l[i]+1], ... , nums[r[i]]` can be **rearranged** to form an **arithmetic** sequence, and `false` otherwise.


**Example 1:**
```
Input: nums = [4,6,5,9,3,7], l = [0,0,2], r = [2,3,5]
Output: [true,false,true]
Explanation:
In the 0th query, the subarray is [4,6,5]. This can be rearranged as [6,5,4], which is an arithmetic sequence.
In the 1st query, the subarray is [4,6,5,9]. This cannot be rearranged as an arithmetic sequence.
In the 2nd query, the subarray is [5,9,3,7]. This can be rearranged as [3,5,7,9], which is an arithmetic sequence.he next pointers, with '#' signifying the end of each level.
```
**Constraints:**

- `n == nums.length`
- `m == l.length`
- `m == r.length`
- `2 <= n <= 500`
- `1 <= m <= 500`
- `0 <= l[i] < r[i] < n`
- `-10^5 <= nums[i] <= 10^5`

---
## 解決思路

此題由於對時間複雜度的限制不高，因此每次我們只需要取出`l[i]~r[i]`的那段子陣列並且作排序後，判斷那段子陣列是否呈顯等差遞增即可。