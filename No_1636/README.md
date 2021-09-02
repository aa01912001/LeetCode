題號: 1636. Sort Array by Increasing Frequency

難度: Easy

## 問題描述

Given an array of integers `nums`, sort the array in **increasing** order based on the frequency of the values. If multiple values have the same frequency, sort them in **decreasing** order.

Return the sorted array.

**Example 1:**

```
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

---
## 解決思路

此題我們只需要利用`unordered_map<int, int>`去紀錄每個數的frequency之後，再自定義comparator去做sort即可。
