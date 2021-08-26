題號: 1493. Longest Subarray of 1's After Deleting One Element

難度: Medium

## 問題描述

Given a binary array `nums`, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array.

Return 0 if there is no such subarray.

**Example 1:**

```
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.

---
## 解決思路

此題我們需要兩個DP陣列`leftOnes`和`rightOnes`，其中:

`leftOnes[i]`用來儲存`nums[i]`左邊連續的1個數(包含`nums[i]`本身)，但若`nums[i]`為0則`leftOnes[i]`等於0。

`rightOnes[i]`用來儲存`nums[i]`右邊連續的1個數(包含`nums[i]`本身)，但若`nums[i]`為0則`rightOnes[i]`等於0。

最後遍歷`nums`找出所有0的位置(假設位置為`i`)去分別計算出最大的`leftOnes[i-1]`與`rightOnes[i+1]`的和(這樣子相當於將`nums[i]`的0刪掉後可得到的最大左右連續1長度)即可。

