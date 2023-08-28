題號: 828. Count Unique Characters of All Substrings of a Given String
難度: Hard

## 問題描述
Let's define a function `countUniqueChars(s)` that returns the number of unique characters in `s`.

- For example, calling `countUniqueChars(s)` if `s = "LEETCODE"` then `"L"`, `"T"`, `"C"`, `"O"`, `"D"` are the unique characters since they appear only once in `s`, therefore `countUniqueChars(s) = 5`

Given a string `s`, return the sum of `countUniqueChars(t)` where `t` is a substring of `s`. The test cases are generated such that the answer fits in a 32-bit integer.

Notice that some substrings can be repeated so in this case you have to count the repeated ones too.

**Example 1:**
```
Input: s = "ABC"
Output: 10
Explanation: All possible substrings are: "A","B","C","AB","BC" and "ABC".
Every substring is composed with only unique letters.
Sum of lengths of all substring is 1 + 1 + 1 + 2 + 2 + 3 = 10
```
**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of uppercase English letters only.


## 解決思路
此題我們不需要真的去計算每一個子字串裡的unique char個數，而是應該換個思考方式，對於`s[i]`來說會在哪些子字串唯一?

我們假設一字串為`CBACDDC`，對於中間的index為3(假設為`i`)的C來說，我們只需要知道其前後的相同字元位置分別為0(假設為`pre`)、6(假設為`post`)即可

我們就知道其可能被算進解答的可能子字串有下列三種cases:

1. 位於子字串最後字元(這裡我們將單純只有一個字元也算進此case): 因此可能有BAC、AC、C三種(`i-pre`)

2. 位於子字串開頭字元: 因此可能有CD、CDD兩種(`post-i-1`)

3. 位於子字串中間字元: 因此可能有ACD、ACDD、BACD、BACDD四種(`(i-pre-1) * (post-i-1)`)

於是對於此C來說，再最終解答裡一共被算進9次。而我們只需要用同樣方式對每個`s[i]`進行此計算並加總即可。
