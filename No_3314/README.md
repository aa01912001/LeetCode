題號: 3314. Construct the Minimum Bitwise Array I

難度: `Easy`

## 問題描述


You are given an array `nums` consisting of `n` **prime** integers.

You need to construct an array `ans` of length `n`, such that, for each index `i`, the bitwise `OR` of `ans[i]` and `ans[i] + 1` is equal to `nums[i]`, i.e. `ans[i] OR (ans[i] + 1) == nums[i]`.

Additionally, you must **minimize** each value of `ans[i]` in the resulting array.

If it is not possible to find such a value for `ans[i]` that satisfies the **condition**, then set `ans[i] = -1`.


**Example 1:**
```
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
```
**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 300`
- `0 <= mat[i][j] <= 10^4`
- `0 <= threshold <= 10^5`

**解決思路:**

對於每個`num`，我們要嘗試「把 num 的某一個 1 bit 關掉」，得到一個候選值 `candidate`，
檢查它是否滿足 `candidate | (candidate + 1) == num`。 如果全部 bit 都試過仍不成立則解答為 -1。

為什麼「關掉一個 bit」就夠了？
因為我們需要找到的是`ans | (ans + 1) == num`，因此:
- ans 本身 不能有 num 沒有的 1
- 所以 ans 一定是 由 num 關掉某些 1 bit 得來
- 為了「最小」，我們優先從高位的1 bit來關閉嘗試