題號: 162. Find Peak Element

難度: Medium

## 問題描述

A peak element is an element that is strictly greater than its neighbors.

Given an integer array `nums`, find a peak element, and return its index. If the array contains multiple peaks, return the index to **any of the peaks**.

You may imagine that `nums[-1] = nums[n] = -∞`.

You must write an algorithm that runs in `O(log n)` time.

**Example 1:**

```
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `nums[i] != nums[i + 1]` for all valid `i`.

---
## 解決思路

此題題目因為假設`nums[-1] = nums[n] = -∞`與`nums[i] != nums[i + 1] for all valid i`因此保證有解，我們可以利用`binary search`的方式每次搜尋中間索引值(`mid`)的數並判斷是否為peak，若不是則將`i`或`j`更新為`nums[mid-1]`與`nums[mid+1]`較大者的索引值(因為最左與最右分別是-∞，因此可保證區段間一定有peak存在)，如此搜尋下去必定可以找到peak。







