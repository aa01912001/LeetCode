題號: 1346. Check If N and Its Double Exist
難度: Easy

## 問題描述

Given an array `arr` of integers, check if there exists two integers `N` and `M` such that `N` is the double of `M` ( i.e. `N = 2 * M`).

More formally check if there exists two indices `i` and `j` such that :

- `i != j`
- `0 <= i, j < arr.length`
- `arr[i] == 2 * arr[j]`

**Example 1:**
```
Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
```


**Constraints:**

- `2 <= arr.length <= 500`
- `-10^3 <= arr[i] <= 10^3`

---
## 解決思路

此題我們只要利用`unordered_set<int>`將每個`arr[i]`記錄起來後，並逐一判斷`arr[i]*2`與`arr[i]/2`是否有在其中即可。

