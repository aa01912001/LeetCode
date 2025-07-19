題號: 3202. Find the Maximum Length of Valid Subsequence II

難度: Medium

## 問題描述
You are given an integer array `nums` and a **positive** integer `k`.

A **subsequence** `sub` of `nums` with length `x` is called **valid** if it satisfies:

- `(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.`

Return the length of the **longest valid** subsequence of `nums`. 

**Example 1:**
```
Input: nums = [1,2,3,4,5], k = 2

Output: 5

Explanation:

The longest valid subsequence is [1, 2, 3, 4, 5].

```

**Constraints:**

- `2 <= nums.length <= 10^3`
- `1 <= nums[i] <= 10^7`
- `1 <= k <= 10^3`


**解決思路:**

我們可以觀察給定的式子 `(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.`，不難看出對於三個連續的數子序列數`a, b, c`，如果 `(a + b) % k == (b + c) % k`，則代表`a % k == c % k`。

可以推導出：
- 若一個長度為 x 的 subsequence 滿足題目條件，那麼「間隔 2 的元素」的餘數（mod k）應該是一致的。

我們可以透過dp的方式來找出這種形式最長的子序列長度，方式如下:

```python=
for num in nums:
    remainder = num % k
    for i in range(k):
        dp[i][remainder] = dp[remainder][i] + 1
        ans = max(ans, dp[i][remainder])
```

解釋:
- 對每個`num`，計算它的餘數`remainder = num % k`
- 然後對所有可能的`i in range(k)`（也就是前一個數字的`mod k`值）：
    - 試圖透過`(前一個 mod 為 i, 當前為 remainder)`這種連接，去延長之前`(remainder, i)`的組合。
    - 所以可以想成「把`(remainder, i)`當成中間一段，現在再接一個`remainder`在後面」=> 所以`dp[i][remainder] = dp[remainder][i] + 1`