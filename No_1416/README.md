題號: 1416. Restore The Array

難度: Hard

## 問題描述
A program was supposed to print an array of integers. The program forgot to print whitespaces and the array is printed as a string of digits `s` and all we know is that all integers in the array were in the range `[1, k]` and there are no leading zeros in the array.

Given the string `s` and the integer `k`, return the number of the possible arrays that can be printed as `s` using the mentioned program. Since the answer may be very large, return it modulo `10^9 + 7`.

**Example 1:**
```
Input: s = "1317", k = 2000
Output: 8
Explanation: Possible arrays are [1317],[131,7],[13,17],[1,317],[13,1,7],[1,31,7],[1,3,17],[1,3,1,7]
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only digits and does not contain leading zeros.
- `1 <= k <= 10^9`

**解決思路:**

此題我們可以用Recursion + Memorization（DP）處理。

- recursion(idx) 代表「從字串位置 idx 開始，到結尾有多少種合法切法」。
- 從 idx 開始，嘗試取長度 1~L（L = len(str(k))）的子字串作為下一個數字：
    - 不能有前導 0（如果 s[idx] == '0'，直接 return 0）。
    - 轉成數字後要 ≤ k。
    - 符合的話，就遞迴算「後面剩下的切法數量」，加總起來。
- Memorization（@cache）：
    - 每個 idx 的計算結果只算一次，避免重複遞迴。


複雜度如下:
- Time: O(n * L)，L = len(str(k))，因為每個位置最多嘗試 L 種切法。若 k ≤ 10^9，L ≤ 9，所以實際上接近 O(n)。
- Space: O(n)（遞迴深度 + Memorization）。