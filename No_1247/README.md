題號: 1247. Minimum Swaps to Make Strings Equal
難度: Medium

## 問題描述

You are given two strings `s1` and `s2` of equal length consisting of letters `"x"` and `"y"` **only**. Your task is to make these two strings equal to each other. You can swap any two characters that belong to **different** strings, which means: swap `s1[i]` and `s2[j]`.

Return the minimum number of swaps required to make `s1` and `s2` equal, or return `-1` if it is impossible to do so.

**Example 1:**
```
Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
```

**Example 2:**
```
Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
```

**Constraints:**

- `1 <= s1.length, s2.length <= 1000`
- `s1, s2` only contain `'x'` or `'y'`.

---
## 解決思路

此題我們對於已經match的`s1[i]`、`s2[i]`可以忽略不計，只統計`xy`與`yx`的映射關係個數，其中`xy`代表在相應位置上s1為x，s2為y的個數，`yx`也為相同道理。之後我們透過example 1可以知道每兩個xy或yx映射可以利用1次的swap變為相同，而透過example 2得知xy與yx需要耗費兩次的swap，因此我們只須返回`xy/2 + yx/2 + xy%2*2`即為我們的答案值。

Note: 我們也需要另外判斷`xy%2 != yx%2`是否相同，若不同則代表最後會有單獨遺留的映射，因此應該返回-1。