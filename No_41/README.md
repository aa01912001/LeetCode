題號: 41. First Missing Positive
難度: Hard

## 問題描述
Given an unsorted integer array `nums`, return the smallest missing positive integer.

You must implement an algorithm that runs in `O(n)` time and uses `O(1)` auxiliary space.

**Example 1:**
```
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

## 解決思路
此題我們可以很明顯地看出，最終解答一定是在`[1,n+1]`的範圍內，其中`n`為`nums`長度，因此我們可以讓`nums`中所有落在該範圍內的數都置換到對應的index上，最後我們判斷`nums[i]`不等於`i+1`的話，那麼就是缺失了`i+1`的正整數。

程式中若`nums[i]`不為正整數，或是在`nums[i]`的對應index上已經有了該數，我們就將`i`遞進1，繼續進行下一個數的判斷。
