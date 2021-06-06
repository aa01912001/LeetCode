題號: 1394. Find Lucky Integer in an Array

難度: Easy

## 問題描述

Given an array of integers `arr`, a lucky integer is an integer which has a frequency in the array equal to its value.

Return a lucky integer in the array. If there are multiple lucky integers return the **largest** of them. If there is no lucky integer return **-1**.

Example 1:


```
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
```

Constraints:

- `1 <= arr.length <= 500`
- `1 <= arr[i] <= 500`



---
## 解決思路

此題我們可用`unordered_map<int, int>`來記錄`arr`中每個數字出現的次數後，再找出最大的lucky integer即可。