題號: 187. Repeated DNA Sequences

難度: Medium

## 問題描述

The **DNA sequence** is composed of a series of nucleotides abbreviated as `'A'`, `'C'`, `'G'`, and `'T'`.

For example, `"ACGAATTCCG"` is a **DNA sequence**.
When studying **DNA**, it is useful to identify repeated sequences within the DNA.

Given a string `s` that represents a **DNA sequence**, return all the `10`**-letter-long** sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in **any order**.


Example 1:

```
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
```

Constraints:

- `1 <= s.length <= 10^5`
- `s[i] is either 'A', 'C', 'G', or 'T'.`



---
## 解決思路

此題只需要利用`unordered_map<string, int>`來儲存DNA中每個長度為10的子序列之出現次數後，最後再找出次數為2次以上的子序列即可。

