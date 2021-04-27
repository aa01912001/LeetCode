題號: 125. Valid Palindrome

難度: Easy

## 問題描述
Given a string `s`, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Example 1:

```
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

Constraints:

- `1 <= s.length <= 2 * 10^5`
- `s consists only of printable ASCII characters.`


---
## 解決思路

此題先把此字串轉換成只含小寫和數字的字串後再判斷是否為一個合法的Palindrome即可。
