題號: 907. Sum of Subarray Minimums

難度: Medium

## 問題描述

Given an array of integers arr, find the sum of `min(b)`, where `b` ranges over every (contiguous) subarray of `arr`. Since the answer may be large, return the answer **modulo** `10^9 + 7`.

**Example 1:**

```
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
```

**Constraints:**

- `1 <= arr.length <= 3 * 10^4`
- `1 <= arr[i] <= 3 * 10^4`

---
## 解決思路

此題我們可利用monotonic stack的策略來解。我們以`stack<pair<int, long>>`的結構來儲存`index i`與`從index i(一定有index i)到index 0間的所有子陣列之minimum之和`。

我們從index 0開始遍歷`arr`，假設當前遍歷index為`i`，我們必須將stack中比`arr[i]`還大的item取出(代表arr[i]為當前子陣列的最小值)，直到stack為空或者找到比他小的item後才停止。

之後將`{i, arr[i]*(i-s.top().first) + s.top().second}`的pair存入stack中，其中`i`為當前索引，`arr[i]*(i-s.top().first)`代表包含index i到之前所有的子陣列最小值為`arr[i]`之最小值總和，而`s.top().second`代表著上一次擁有著比`arr[i]`還要小的數值之**Sum of Subarray Minimums**(一定包含此數值之index為子陣列最後一項)。

最後將`s.top().second`加入解答中即可。

如此我們在每一次跌代就可以得到**每一個從index 0到當前index中所有包含當前index的子陣列之最小值之和**。