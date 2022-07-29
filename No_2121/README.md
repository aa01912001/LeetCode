題號: 2121. Intervals Between Identical Elements
難度: Medium

## 問題描述

You are given a **0-indexed** array of `n` integers `arr`.

The **interval** between two elements in `arr` is defined as the **absolute difference** between their indices. More formally, the **interval** between `arr[i]` and `arr[j]` is `|i - j|`.

Return an array `intervals` of length `n` where `intervals[i]` is **the sum of intervals** between `arr[i]` and each element in `arr` with the same value as `arr[i]`.

Note: `|x|` is the absolute value of `x`.

**Example 1:**
```
Input: arr = [2,1,3,1,2,3,3]
Output: [4,2,7,2,4,4,5]
Explanation:
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
```
**Constraints:**

- `n == arr.length`
- `1 <= n <= 10^5`
- `1 <= arr[i] <= 10^5`

---
## 解決思路

此題我們針對每個不同數字的距離差之previous sum來計算某個數字對於其他相同數字的距離差絕對值之和，想法如下：

3 x x 3 x x x 3

對於第三個3(index 7)來說，其前面兩個3的距離差之previous sum為7(index 3-0 = 3)，因此對於index 10的3來說，其與其他相同數字的距離差絕對值之和為3 + 4\*2 = 11。

因此，程式中我們使用`unordered_map<int, vector<long>> hmap;`的結構來儲存不同數字的資訊，其中：

`hmap[num][0]`為`num`對於前面相同數字的距離差之previous sum。
`hmap[num][1]`為前一個`num`之index。
`hmap[num][2]`為先前所遇到的`num`個數。

另外，我們需要從左至右與從右至左的解答相加後才為正確解答。
