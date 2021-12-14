題號: 1031. Maximum Sum of Two Non-Overlapping Subarrays

難度: Medium

## 問題描述

Given an integer array `nums` and two integers `firstLen` and `secondLen`, return the maximum sum of elements in two non-overlapping **subarrays** with lengths `firstLen` and `secondLen`.

The array with length `firstLen` could occur before or after the array with length `secondLen`, but they have to be non-overlapping.

A **subarray** is a **contiguous** part of an array.

**Example 1:**
```
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.
```

**Constraints:**

- `1 <= firstLen, secondLen <= 1000`
- `2 <= firstLen + secondLen <= 1000`
- `firstLen + secondLen <= nums.length <= 1000`
- `0 <= nums[i] <= 1000`

---
## 解決思路

此題可利用DP的策略來考慮每一個`nums[i]`可能屬於長度為`firstLen`或`secondLen`的子陣列中最後一個元素的情況。

程式中，我們維護了兩個DP陣列：
1. `dpFirst[i]`－用來儲存從`nums[0]~nums[i-1]`中最大的長度為`firstLen`之子陣列之和
2. `dpSecond[i]`－用來儲存從`nums[0]~nums[i-1]`中最大的長度為`secondLen`之子陣列之和

之後針對`nums`從頭遍歷到尾，對於每一個`nums[i]`我們都去考慮其屬於兩子陣列最尾端的元素之情況，並和暫存的最佳解去比大小即可，此部分於程式中如下所示，其中`sum`為`nums[0]`到`nums[i]`之和：

```cpp=
ret = max(ret, sum-preSum[i-firstLen]+dpSecond[i-firstLen+1]);
ret = max(ret, sum-preSum[i-secondLen]+dpFirst[i-secondLen+1]);
```

只要遍歷到最後即可找出最佳解。