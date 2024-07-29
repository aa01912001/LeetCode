題號: 1395. Count Number of Teams
難度: Medium

## 問題描述
There are `n` soldiers standing in a line. Each soldier is assigned a **unique** `rating` value.

You have to form a team of 3 soldiers amongst them under the following rules:

- Choose 3 soldiers with index (`i`, `j`, `k`) with rating (`rating[i]`, `rating[j]`, `rating[k]`).

- A team is valid if: (`rating[i] < rating[j] < rating[k]`) or (`rating[i] > rating[j] > rating[k]`) where (`0 <= i < j < k < n`).

Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).

**Example 1:**
```
Input: rating = [2,5,3,4,1]
Output: 3
Explanation: We can form three teams given the conditions. (2,3,4), (5,4,1), (5,3,1). 
```

**Constraints:**

- `n == rating.length`
- `3 <= n <= 1000`
- `1 <= rating[i] <= 10^5`
- All the integers in `rating` are **unique**.

## 解決思路
此題對於每個`rating[i]`來說我們只需要找到其左邊小於它的數之個數(`l`)，以及其右邊大於它的數之個數(`r`)，我們就能計算出以`rating[i]`做為中間士兵的組合個數為`l * r + (i - l) * (n - i - 1 - r)`，其中`n`為`rating`長度，`l * r`為遞增之組合數，`(i - l) * (n - i - 1 - r)`為遞減之組合數。

