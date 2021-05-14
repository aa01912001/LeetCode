題號: 1578. Minimum Deletion Cost to Avoid Repeating Letters

難度: Medium

## 問題描述

Given a string `s` and an array of integers `cost` where `cost[i]` is the cost of deleting the `ith` character in `s`.

Return the minimum cost of deletions such that there are no two identical letters next to each other.

Notice that you will delete the chosen characters at the same time, in other words, after deleting a character, the costs of deleting other characters will not change.

Example 1:

```
Input: s = "abaac", cost = [1,2,3,4,5]
Output: 3
Explanation: Delete the letter "a" with cost 3 to get "abac" (String without two identical letters next to each other).
```

Constraints:

- `s.length == cost.length`
- `1 <= s.length, cost.length <= 10^5`
- `1 <= cost[i] <= 10^4`
- `s` contains only lowercase English letters.



---
## 解決思路

此題我們必須尋找每一段擁有連續相同字元的子字串後，再找出其中最大的字元cost，之後將該子字串所有cost總合起來減掉最大的cost後即可得到該子字串的解。只要將所有連續相同字元子字串都按此方式執行，並將所有子字串之解相加，即可得到解答。

