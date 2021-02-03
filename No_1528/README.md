題號: 1528. Shuffle String

難度: Easy

## 問題描述
Given a string `s` and an integer array `indices` of the **same length**.

The string `s` will be shuffled such that the character at the `ith` position moves to `indices[i]` in the shuffled string.

Return the shuffled string.

Example 1:
![](https://assets.leetcode.com/uploads/2020/07/09/q1.jpg)

```
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
```

Constraints:


- `s.length == indices.length == n`
- `1 <= n <= 100`
- `s` contains only lower-case English letters.
- `0 <= indices[i] < n`
- All values of `indices` are unique (i.e. `indices` is a permutation of the integers from `0` to `n - 1`).


---
## 解決思路
此題直接利用一層for迴圈依序將s中的字元對應到`indices[i]`即可。