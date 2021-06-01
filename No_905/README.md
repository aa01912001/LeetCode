題號: 905. Sort Array By Parity

難度: Easy

## 問題描述

Given an array `nums` of non-negative integers, return an array consisting of all the even elements of `nums`, followed by all the odd elements of `nums`.

You may return any answer array that satisfies this condition.

Example 1:

```
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

Constraints:

- `1 <= nums.length <= 5000`
- `0 <= nums[i] <= 5000`

---
## 解決思路

此題只要將`nums`中的數依照奇、偶分好類後，再合併即可。