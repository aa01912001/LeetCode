題號: 3186. Maximum Total Damage With Spell Casting

難度: Medium

## 問題描述
A magician has various spells.

You are given an array `power`, where each element represents the damage of a spell. Multiple spells can have the same damage value.

It is a known fact that if a magician decides to cast a spell with a damage of `power[i]`, they **cannot** cast any spell with a damage of `power[i] - 2`, `power[i] - 1`, `power[i] + 1`, or `power[i] + 2`.

Each spell can be cast **only once**.

Return the **maximum** possible total damage that a magician can cast.

**Example 1:**
```
Input: power = [1,1,3,4]
Output: 6
Explanation:

The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.

```

**Constraints:**

- `1 <= power.length <= 10^5`
- `1 <= power[i] <= 10^9`

**解決思路:**

因為相同傷害的法術可以一起施放、彼此不衝突，
我們可以先把所有相同數字的法術加總起來之後依照damage排序為`spells`。

之後我們訂一DP狀態如下:

`dp[i]` = 考慮到第`i`個spell為止，能造成的最大總傷害

對每一個`dp[i]`，我們有兩種選擇：

1. 不選當前 spell，那就繼承上一個結果：
    - `dp[i] = dp[i-1]`

2. 選當前spell但這樣會衝突到傷害值在 `[damage-2, damage+2]`之間的spell，
所以要往前找最近一個不衝突的spell（即差距 > 2）。找到那個索引 j 後：
    - `dp[i] = dp[j] + spells[i][1]`
    
3. 比較1, 2哪個較大則更新為`dp[i]`