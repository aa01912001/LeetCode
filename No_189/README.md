題號: 189. Rotate Array
難度: Medium

## 問題描述
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

**Example 1:**
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`
- `0 <= k <= 10^5`

---
## 解決思路
假設`nums = [n1,n2,n3,n4,n5,n6,n7], k = 3`

其答案為: `[n5,n6,n7,n1,n2,n3,n4]`

我們可以發現就是將右`k`位移動至前`k`位;因此我們可以先對`nums`做reverse後得到:

`[n7,n6,n5,n4,n3,n2,n1]`

之後再對前`k`位及`n-k`位分別做reverse後即可得到解答。其中`n`為`nums`長度。