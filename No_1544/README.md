題號: 1544. Make The String Great

難度: Easy

## 問題描述

Given a string `s` of lower and upper case English letters.

A good string is a string which doesn't have **two adjacent characters** `s[i]` and `s[i + 1]` where:

- `0 <= i <= s.length - 2`
- `s[i]` is a lower-case letter and `s[i + 1]` is the same letter but in upper-case or **vice-versa**.
- 
To make the string good, you can choose **two adjacent** characters that make the string bad and remove them. You can keep doing this until the string becomes good.

Return the string after making it good. The answer is guaranteed to be unique under the given constraints.

**Notice** that an empty string is also good.


**Example 1:**

```
Input: s = "leEeetcode"
Output: "leetcode"
Explanation: In the first step, either you choose i = 1 or i = 2, both will result "leEeetcode" to be reduced to "leetcode".
```

Constraints:

- `1 <= s.length <= 100`
- `s` contains only lower and upper case English letters.

---
## 解決思路

此題我們由string `s`後面開始遍歷所有字元，並用`stack<int>`暫存合法字元。每次遍歷到一個`s`中的字元，我們就去比對它跟stack top是否互為大小寫關係，是的話就將stack的top取出，否則將該次字元放入stack中。

在遍歷完所有`s`中的字元後將stack中剩餘的字元取出組成合法字串即可。