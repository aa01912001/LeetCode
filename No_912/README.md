題號: 912. Sort an Array

難度: Medium

## 問題描述

Given an array of integers `nums`, sort the array in ascending order.


**Example 1:**

```
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
```

**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `-5 * 10^4 <= nums[i] <= 5 * 10^4`



---
## 解決思路

此題只需將`nums`中的所有數字放入`min heap`中後，再依序取出`min heap`中的元素形成遞增排序即可。