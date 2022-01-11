題號: 692. Top K Frequent Words
難度: Medium

## 問題描述

Given an array of strings `words` and an integer `k`, return the `k` most frequent strings.

Return the answer **sorted** by **the frequency** from highest to lowest. Sort the words with the same frequency by their **lexicographical order**.
 

**Example 1:**
```
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
```


**Constraints:**

- `1 <= words.length <= 500`
- `1 <= words[i] <= 10`
- `words[i]` consists of lowercase English letters.
- `k` is in the range `[1, The number of unique words[i]]`

---
## 解決思路

此題我們首先利用`unordered_map<string, int>`來記錄每個單詞的頻率，之後再將每個單詞與其出現次數放進**max heap**後，再取出`k`個即可。

過程中我們需要自定義`priority_queue`的comparator，因此我們需要先比較兩單詞的頻率再去比較兩者之字典順序。