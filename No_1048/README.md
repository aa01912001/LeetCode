題號: 1048. Longest String Chain
難度: Medium

## 問題描述

You are given an array of `words` where each word consists of lowercase English letters.

`wordA` is a **predecessor** of `wordB` if and only if we can insert **exactly one** letter anywhere in `wordA` **without changing the order of the other characters** to make it equal to `wordB`.

- For example, `"abc"` is a **predecessor** of `"abac"`, while `"cba"` is not a **predecessor** of `"bcad"`.

A **word chain** is a sequence of words `[word1, word2, ..., wordk]` with `k >= 1`, where `word1` is a **predecessor** of `word2`, `word2` is a **predecessor** of `word3`, and so on. A single word is trivially a **word chain** with `k == 1`.

Return the **length** of the **longest possible word chain** with words chosen from the given list of `words`.

**Example 1:**
```
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
```


**Constraints:**

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` only consists of lowercase English letters.

---
## 解決思路

此題我們可以採用DP的方法來解決，程式中我們維護一個結構如下：

`unordered_map<string, int> dp;`

用來儲存每個words中的字串為chain中的最後一個時，可能形成的**longest possible word chain**長度。

另外我們維護一個結構如下：

`unordered_map<int, vector<string>> allLenString;`：

用來記錄不同字串長度所擁有的所有words中的字串

對於長度為`len`的字串`str1`來說，我們要尋找其為chain中的最後一個字串之**longest possible word chain**，因此我們就必須針對長度為`len-1`的所有字串去逐一比對是否為其**predecessor**，若為**predecessor**(假設該字串為`str2`)，就去比較`dp[str2]+1`是否大於`dp[str1]`，並更新其值，因此我們從words中最小字串長度的字串開始反覆更新`dp`，就能取得最終的**longest possible word chain**。
