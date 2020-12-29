題號: 784. Letter Case Permutation

難度: Medium

## 問題描述
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. You can return the output in **any order**.

Example 1:

```
Input: S = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
```

Constraints:

- `S` will be a string with length between `1` and `12`.
- `S` will consist only of letters or digits.


---
## 解決思路
此題直接利用backtracking的方式試著將每一個letter的做大小寫的轉換後再進入到下一位執行，直到index超出範圍後就將S放入解答即可。**同時我們也需要考慮每一個letter不做大小寫轉換的情況，所以必須另外將原本的字元作為一種情況下去遞迴**。另外若letter為數字形式，則不需做大小寫轉換。
