題號: 1497. Check If Array Pairs Are Divisible by k

難度: Medium

## 問題描述
Given an array of integers `arr` of even length `n` and an integer `k`.

We want to divide the array into exactly `n / 2` pairs such that the sum of each pair is divisible by `k`.

Return `true` If you can find a way to do that or `false` otherwise.


**Example 1:**
```
Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
```

**Constraints:**

- `arr.length == n`
- `1 <= n <= 10^5`
- `n` is even.
- `-10^9 <= arr[i] <= 10^9`
- `1 <= k <= 10^5`

**解決思路:**

首先我們統計每個餘數的個數，並分別以下cases:

1. 如餘數為0的個數不為偶數，則無法成功分配
2. 若k為偶數，且餘數為k/2的個數部為偶數，則同樣無法分配成功
3. 剩餘的餘數`r`我們只需要檢查其數量是否與`k-r`的數量相等即可。