題號: 1684. Count the Number of Consistent Strings

難度: Easy

## 問題描述
You are given a string `allowed` consisting of `distinct` characters and an array of strings `words`. A string is **consistent** if all characters in the string appear in the string `allowed`.

Return the number of **consistent** strings in the array `words`.

Example 1:

```
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
```

Constraints:

- `1 <= words.length <= 10^4`
- `1 <= allowed.length <= 26`
- `1 <= words[i].length <= 10`
- The characters in `allowed` are **distinct**.
- `words[i]` and `allowed` contain only lowercase English letters.

---
## 解決思路

此題可以利用unordered_set的結構來儲存`allowed`中出現的字元，之後再一一判斷`words`中的每一個string是否合法即可。
