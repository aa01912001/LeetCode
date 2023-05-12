題號: 1124. Longest Well-Performing Interval
難度: Medium

## 問題描述
We are given `hours`, a list of the number of hours worked per day for a given employee.

A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than `8`.

A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

Return the length of the longest well-performing interval.

**Example 1:**
```
Input: hours = [9,9,6,0,6,6,9]
Output: 3
Explanation: The longest well-performing interval is [9,9,6].
```

**Constraints:**

- `1 <= hours.length <= 10^4`
- `0 <= hours[i] <= 16`

## 解決思路
此題我們首先將大於8的數轉換為1，小於8的數轉換為-1後，就可以將問題簡化為找出和大於0的子陣列長度。

為了解決簡化後的問題，我們可以計算prefix sum，若當前的數列和大於0，則我們直接將解答更新為當前index+1;若小於0，則我們應該去找出第一次出現prefix sum為當前`prefix sum - 1`的索引位置，則此中間區段必為合法區間，我們就拿此區間長度去跟當前解答比較。

程式中我們則利用hash map紀錄了每個不同的prefux sum第一次出現的索引位置。