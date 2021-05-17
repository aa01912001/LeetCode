題號: 923. 3Sum With Multiplicity

難度: Medium

## 問題描述

Given an integer array `arr`, and an integer `target`, return the number of tuples `i, j, k` such that `i < j < k` and `arr[i] + arr[j] + arr[k] == target`.

As the answer can be very large, return it **modulo** `10^9 + 7`.

Example 1:

```
Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
```

Constraints:

- `3 <= arr.length <= 3000`
- `0 <= arr[i] <= 100`
- `0 <= target <= 300`

---
## 解決思路

此題首先統計`arr`中各個數字出現的次數。因為`arr[i]`只會出現0\~100的數字所以我們可以以O(101^3)的時間找出0~101中可能的組合，之後再利用剛剛統計的結果將每個組合在`arr`中可以取得的索引組合數計算出來即可。
