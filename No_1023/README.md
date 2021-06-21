題號: 1023. Camelcase Matching

難度: Medium

## 問題描述

A query word matches a given `pattern` if we can insert **lowercase** letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of `queries`, and a `pattern`, return an `answer` list of booleans, where `answer[i]` is true if and only if `queries[i]` matches the `pattern`.

**Example 1:**

```
Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
```

Note:

1. `1 <= queries.length <= 100`
2. `1 <= queries[i].length <= 100`
3. `1 <= pattern.length <= 100`
All strings consists only of lower and upper case English letters.

---
## 解決思路

此題我們只要去分別判斷`queries`中的每個string是否可以match pattern即可。判斷的過程中用兩個index變數`i`、`j`來分別指向比較的string與pattern的字元，並且比較是否相等即可，若不相等就判斷string是否為大寫，是的話即返回`false`。
