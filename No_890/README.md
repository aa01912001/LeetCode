題號: 890. Find and Replace Pattern

難度: Medium

## 問題描述
You have a list of `words` and a `pattern`, and you want to know which words in `words` matches the pattern.

A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.

(Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.)

Return a list of the words in `words` that match the given pattern. 

You may return the answer in any order.

Example 1:

```
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation,
since a and b map to the same letter.
```

Note:
- `1 <= words.length <= 50`
- `1 <= pattern.length = words[i].length <= 20`

---
## 解決思路
此題因為要確保word與pattern之間的映射為**1-1**，所以我們使用兩個char vector來記錄每個字元類之間的映射，**其中map紀錄了word中的字元類映射到哪個字元類，而imap紀錄了pattern中的字元類被哪個word中的字元類映射**。我們用map來確保在word中的字元類是否只會唯一對應到一個pattern中的字元類，而imap則是確保pattern中的字元類是否唯一被word中的某個字元類所對應。

如此遍歷所有word字元，即可知道是否該word可以成功映射到pattern。
