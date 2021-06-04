題號: 1209. Remove All Adjacent Duplicates in String II

難度: Medium

## 問題描述

You are given a string `s` and an integer `k`, a `k` **duplicate removal** consists of choosing `k` adjacent and equal letters from `s` and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make `k` **duplicate removals** on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

Example 1:


```
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
```

Constraints:

- `1 <= s.length <= 10^5`
- `2 <= k <= 10^4`
- `s` only contains lower case English letters.

---
## 解決思路

此題我們可以用`stack`來儲存`pair<char, int>`，代表**目前字元是第幾個連續的相同字元**，一旦發現有k個連續字元，就將他從`stack`中pop出，在遍歷全部`s`中的字元後，只要將`stack`中剩下的字元取出組成字串返回即可。