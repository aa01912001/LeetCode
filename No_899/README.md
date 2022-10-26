題號: 899. Orderly Queue
難度: Hard

## 問題描述

You are given a string `s` and an integer `k`. You can choose one of the first `k` letters of `s` and append it at the end of the string..

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

**Example 1:**

```
Input: s = "baaca", k = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
```

**Constraints:**

- `1 <= k <= s.length <= 1000`
- `s` consist of lowercase English letters.

---
## 解決思路

此題我們可以分為兩種情況:

1. `k == 1`: 
    在這種情況下我們只需在`s.length()`個可能字串中找出最小的即可(前`i`個字元放在後`n-i`個字元後面的`n`個可能字串，其中`n`為`s`長度)。
    
2. `k > 1`:
    直接返回`s`做sorting後的字串即可。
    
- 證明當`k >= 2`時，`s`必定可變為sorting後的字串:
    每次在前`k`個字元中一直保留最小的字元，直到我們找到最小字元後再將該最小字元放至字串最後面，之後從前`n-1`個字元中尋找第二小的字元，並將其放至在最小字元後即可，如此進行反覆操作尋找次小字元即可得到最小字串。
    
Note: 該證明類似於bubble sort