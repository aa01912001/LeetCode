題號: 898. Bitwise ORs of Subarrays
難度: Medium

## 問題描述

We have an array `arr` of non-negative integers.

For every (contiguous) subarray `sub = [arr[i], arr[i + 1], ..., arr[j]]` (with `i <= j`), we take the bitwise OR of all the elements in `sub`, obtaining a result `arr[i] | arr[i + 1] | ... | arr[j]`.

Return the number of possible results. Results that occur more than once are only counted once in the final answer

**Example 1:**
```
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.
```


**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `0 <= nums[i] <= 10^9`

---
## 解決思路

此題可以利用DP策略去利用`unordered_set<int> pre`的結構去紀錄從`arr[0]~arr[i-1]`且包含`arr[i-1]`的**Bitwise ORs of Subarrays**可能結果。

程式中我們使用`unordered_set<int> ret`來記錄遍歷過程中的所有結果，而對於每一回合的`arr[i]`來說，我們需要去找出包含他的`pre`，所以我們必須將前回合`pre`中的所有數與`arr[i]`做OR運算後打造出一個新的`pre`(要另外包含`arr[i]`本身)，最後在將`pre`中的所有數放入`ret`即可。

`arr[i]`為最後且長度大於等於2的子陣列必包含`arr[i-1]`，因此利用`pre`我們就不必另外再計算一次`arr[i]`之前包含`arr[i-1]`的可能結果。

最後只要返回`ret`中的個數即為正確解答。