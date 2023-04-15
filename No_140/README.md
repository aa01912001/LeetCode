題號: 140. Word Break II
難度: Hard

## 問題描述
Given a string `s` and a dictionary of strings `wordDict`, add spaces in `s` to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in **any order**.

**Note** that the same word in the dictionary may be reused multiple times in the segmentation.

**Example 1:**
```
Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
```

**Constraints:**

- `1 <= s.length <= 20`
- `1 <= wordDict.length <= 1000`
- `1 <= wordDict[i].length <= 10`
- `s` and `wordDict[i]` consist of only lowercase English letters.
- All the strings of `wordDict` are **unique**.
- Input is generated in a way that the length of the answer doesn't exceed 10^5.

## 解決思路
此題我們可以利用遞迴的方式來建構所有可能的sentence，並且過程中我們透過hmap來進行memoization的優化。

我們可以發現假設我們首先挑中cat，則sanddog會再進行與`wordDict`的下一輪比對，而每次的比對方式都是拿取每個`wordDict`中的word與`s`進行比對，因此適合使用遞迴來解決。

假設我們已經建構完以cat為開頭的所有sentence，接著cats又會比對中，因此會以同樣的方式再建構一次以cats開頭的所有sentence。