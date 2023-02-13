題號: 1736. Latest Time by Replacing Hidden Digits
難度: Easy

## 問題描述
You are given a string `time` in the form of `hh:mm`, where some of the digits in the string are hidden (represented by `?`).

The valid times are those inclusively between `00:00` and `23:59`.

Return the latest valid `time` you can get from time by replacing the hidden digits.

**Example 1:**
```
Input: time = "2?:?0"
Output: "23:50"
Explanation: The latest hour beginning with the digit '2' is 23 and the latest minute ending with the digit '0' is 50.
```

**Constraints:**

- `time` is in the format `hh:mm`.
- It is guaranteed that you can produce a valid time from the given string.

---
## 解決思路
此題只需對每一位填入最大數即可，但對於時來說，須注意前後限制。