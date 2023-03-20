題號: 1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
難度: Medium

## 問題描述
Given an array of integers `arr` and two integers `k` and `threshold`, return the number of sub-arrays of size `k` and average greater than or equal to `threshold`.

**Example 1:**
```
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 10^4`
- `1 <= k <= arr.length`
- `0 <= threshold <= 10^4`

---
## 解決思路
此題只需利用sliding window的方式對每個長度為`k`的子陣列計算平均即可。