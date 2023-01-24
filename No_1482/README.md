題號: 1482. Minimum Number of Days to Make m Bouquets
難度: Medium

## 問題描述
You are given an integer array `bloomDay`, an integer `m` and an integer `k`.

You want to make `m` bouquets. To make a bouquet, you need to use `k` **adjacent flowers** from the garden.

The garden consists of `n` flowers, the `ith` flower will bloom in the `bloomDay[i]` and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make `m` bouquets from the garden. If it is impossible to make m bouquets return `-1`.

**Example 1:**
```
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
```

**Constraints:**

- `bloomDay.length == n`
- `1 <= n <= 10^5`
- `1 <= bloomDay[i] <= 10^9`
- `1 <= m <= 10^6`
- `1 <= k <= n`

---
## 解決思路
我們可以以binary search的方式來找出解答值，對於每次猜測的`mid`值，我們必須要去判斷是否可以在`mid`天內完成`m`組花束。

而判斷的方法為，從頭開始遍歷`bloomDay`，每次發現當前天數小於`mid`，則將`flowerCount`加一，否則代表無法包含當前的花，因此將`flowerCount`歸零，而一旦發現`flowerCount`的值等於`m`則代表找到一組連續的花可以在`mid`天內開花，因此我們將`totalBouquets`加一後，再把`flowerCount`歸零往下尋找其他可能的連續花組;最後，遍歷完`bloomDay`後，我們只需要返`totalBouquets`使否大於等於`m`即可。