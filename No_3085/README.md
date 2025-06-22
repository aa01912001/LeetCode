題號: 3085. Minimum Deletions to Make String K-Special

難度: Medium

## 問題描述
You are given a string `word` and an integer `k`.

We consider `word` to be **k-special** if `|freq(word[i]) - freq(word[j])| <= k` for all indices `i` and `j` in the string.

Here, `freq(x)` denotes the **frequency** of the character `x` in `word`, and `|y| `denotes the absolute value of `y`.

Return the minimum number of characters you need to delete to make `word` **k-special**.

**Example 1:**
```
Input: word = "aabcaba", k = 0

Output: 3

Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.

```

**Constraints:**

- `1 <= word.length <= 10^5`
- `0 <= k <= 10^5`
- `word` consists only of lowercase English letters.

**解決思路:**

首先我們計算所有字元的頻率`freqs`，之後我們可以假設最終下界的可能值為`1~len(word)`，而對於每個可能值`target`，我們需要去計算所有字元的頻率需要滿足此`target`的運算總合次數為多少。

- 若當前頻率`f` < `target`，則需要將此字元全部刪除
- 若當前頻率`f` > `target + k`，則需要將此字元刪除`f - target - k`次，以滿足限制

我們對於每個可能的`target`計算出個別所需要的刪除次數後，返回最小的即可。