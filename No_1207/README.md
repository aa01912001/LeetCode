題號: 1207. Unique Number of Occurrences

難度: Easy

## 問題描述

Given an array of integers `arr`, write a function that returns `true` if and only if the number of occurrences of each value in the array is unique.

Example 1:

```
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
```

Constraints:

- `1 <= arr.length <= 1000`
- `-1000 <= arr[i] <= 1000`


---
## 解決思路

此題先用`unordered_map<int, int>`將`arr`每個數字出現的次數記錄下來後，再用`unordered_set<int>`來記錄`unordered_map<int, int>`所有出現的不同次數，最後只要比對`unordered_map<int, int>`與`unordered_set<int>`的size是否一致即可(一致則代表`arr`中不同的數字皆有著不同的出現次數)。