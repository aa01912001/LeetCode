題號: 2311. Longest Binary Subsequence Less Than or Equal to K

難度: Medium

## 問題描述
You are given a binary string `s` and a positive integer `k`.

Return the length of the **longest** subsequence of `s` that makes up a **binary** number less than or equal to `k`.

Note:

- The subsequence can contain **leading zeroes**.
- The empty string is considered to be equal to `0`.
- A **subsequence** is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.



**Example 1:**
```
Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] < nums.length`


**解決思路:**

我們知道越高位（左邊）貢獻越大，一不小心就超過 k，所以優先保留低位的 1。

透過greedy的方式從右往左貪心加值，只要加了不會超過 k，就納入解答子序列中。

假設 s = "1001010", k = 5

- 從右往左掃：
	- '0' → 加入沒問題（值仍是 0），ans=1
	- '1' → 加入值是 2^1=2，總值=2，ans=2
	- '0' → 加入值=0，總值=2，ans=3
	- '1' → 加入值=2^3=8，總值=10，超過 k → 不加
	- '0' → 加入值=0，總值=2，ans=4
	- '0' → 加入值=0，總值=2，ans=5
	- '1' → 加入值=2^5=32，總值=34，超過 → 不加