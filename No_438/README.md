題號: 438. Find All Anagrams in a String
難度: Medium

## 問題描述
Given two strings `s` and `p`, return an array of all the start indices of `p`'s anagrams in `s`. You may return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
```
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
```

**Constraints:**

- `1 <= s.length, p.length <= 3 * 10^4`
- `s` and `p` consist of lowercase English letters.

## 解決思路
此題我們利用hash map統計`p`所有字元的個數後，再藉由sliding window的方式，對每個`s`中長度為`p.size()`的子字串進行統計判斷即可。

