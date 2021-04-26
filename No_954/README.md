題號: 954. Array of Doubled Pairs

難度: Medium

## 問題描述
Given an array of integers `arr` of even length, return `true` if and only if it is possible to reorder it such that `arr[2 * i + 1] = 2 * arr[2 * i]` for every `0 <= i < len(arr) / 2`.

Example 1:

```
Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
```

Constraints:

- `0 <= arr.length <= 3 * 10^4`
- `arr.length is even.`
- `-10^5 <= arr[i] <= 10^5`



---
## 解決思路

此題我們先利用`unordered_mpa<int, int>`來記錄`arr`中每個數字出現過的次數，之後將`arr`做遞增排序(若未做排序可能會導致錯誤的順序挑選而使得return false)，之後將每個`arr[i]`與`2*arr[i]`從unordered_map中取出配對。最後只要判斷是否有配對到`arr.size()/2`次即可。
