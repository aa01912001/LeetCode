題號: 2645. Minimum Additions to Make Valid String
難度: Medium

## 問題描述
Given a string `word` to which you can insert letters "a", "b" or "c" anywhere and any number of times, return the minimum number of letters that must be inserted so that `word` becomes **valid**.

A string is called **valid** if it can be formed by concatenating the string "abc" several times.

**Example 1:**
```
Input: word = "aaa"
Output: 6
Explanation: Insert letters "b" and "c" next to each "a" to obtain the valid string "abcabcabc".
```

**Constraints:**

- `1 <= word.length <= 50`
- `word` consists of letters "a", "b" and "c" only. 

## 解決思路
首先我們可以假設對於word中的每個字元都需要插入另外兩個相應字元並回valid，因此一開始我們將解答值預設為`2*word.length()`。

之後我們逐一遍歷每一字元並分為三種情況:

1. word[i] == 'a':
    不做任何事，其一定需要有另外兩個字元配合。

2. word[i] == 'b':
    若前一個字元為'a'，代表結合前一字元只需要另外插入'c'即可，因此將解答值減3。
    
3. word[i] == 'c':
    若前一個字元為'a'或'b'，與case 2同理，皆只需要插入另一字元配合即可，故同樣將解答值減3。