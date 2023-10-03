題號: 1657. Determine if Two Strings Are Close
難度: Medium

## 問題描述
Two strings are considered **close** if you can attain one from the other using the following operations:

- Operation 1: Swap any two **existing** characters.
    - For example, `abcde -> aecdb`

- Operation 2: Transform **every** occurrence of one **existing** character into another **existing** character, and do the same with the other character.
    - For example, `aacabb -> bbcbaa` (all `a`'s turn into `b`'s, and all `b`'s turn into `a`'s)

You can use the operations on either string as many times as necessary.

Given two strings, `word1` and `word2`, return `true` if `word1` and `word2` are **close**, and `false` otherwise.

**Example 1:**
```
Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
```

**Constraints:**

- `1 <= word1.length, word2.length <= 10^5`
- `word1` and `word2` contain only lowercase English letters.

## 解決思路
透過Operation 1，我們可以知道我們不需要在意字符的排序，只需要知道每個不同字符的頻率是否一致即可，並且也需要確定`word1`、`word2`中所出現的不同字元需為一致。

因此我們可以透過
`vector<int> countForWord1(26), countForWord2(26)`來記錄`word1`、`word2`中各字元所出現的頻率。

之後我們確認`countForWord1`、`countForWord2`是否包含一樣的字元，若是，我們分別對此兩個vector進行遞增排序，以比較`word1`與`word2`字元出現頻率是否為相同的pattern。