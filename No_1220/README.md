題號: 1220. Count Vowels Permutation
難度: Hard

## 問題描述
Given an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:

- Each character is a lower case vowel (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`)
- Each vowel `'a'` may only be followed by an `'e'`.
- Each vowel `'e'` may only be followed by an 'a' or an `'i'`.
- Each vowel `'i'` **may not** be followed by another `'i'`.
- Each vowel `'o'` may only be followed by an 'i' or a `'u'`.
- Each vowel `'u'` may only be followed by an `'a'`.

Since the answer may be too large, return it modulo `10^9 + 7`.

**Example 1:**
```
Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
```
**Constraints:**

- `1 <= n <= 2 * 10^4`

## 解決思路
此題很明顯只需利用DP的方式來計算出當各個字母為最後一個字元時，其可能數為多少。

程式中，我們利用長度為5的`vector<long long> dp`來分別對應`'a'`, `'e'`, `'i'`, `'o'`, `'u'`為最後一個字元的解答數，因此我們只需要根據規則不斷更新不同長度的dp即可。

(此題難度應該只有easy~medium而已，不懂怎麼會被分類成hard)

