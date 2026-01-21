題號: 3315. Construct the Minimum Bitwise Array II

難度: `Medium`

## 問題描述


You are given an array `nums` consisting of `n` **prime** integers.

You need to construct an array `ans` of length `n`, such that, for each index `i`, the bitwise `OR` of `ans[i]` and `ans[i] + 1` is equal to `nums[i]`, i.e. `ans[i] OR (ans[i] + 1) == nums[i]`.

Additionally, you must **minimize** each value of `ans[i]` in the resulting array.

If it is not possible to find such a value for `ans[i]` that satisfies the **condition**, then set `ans[i] = -1`.


**Example 1:**
```
Input: nums = [2,3,5,7]

Output: [-1,1,4,3]

Explanation:

    For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
    For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
    For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
    For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.


```
**Constraints:**

- `1 <= nums.length <= 100`
- `2 <= nums[i] <= 10^9`
- `nums[i]` is a prime number.

**解決思路:**

對於每個`num`，我們要嘗試「把 num 的某一個 1 bit 關掉」，得到一個候選值 `candidate`，
檢查它是否滿足 `candidate | (candidate + 1) == num`。 如果全部 bit 都試過仍不成立則解答為 -1。

為什麼「關掉一個 bit」就夠了？
因為我們需要找到的是`ans | (ans + 1) == num`，因此:
- ans 本身 不能有 num 沒有的 1
- 所以 ans 一定是 由 num 關掉某些 1 bit 得來
- 為了「最小」，我們優先從高位的1 bit來關閉嘗試