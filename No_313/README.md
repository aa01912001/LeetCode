題號: 313. Super Ugly Number
難度: Medium

## 問題描述

A `super ugly number` is a positive integer whose prime factors are in the array `primes`.

Given an integer `n` and an array of integers `primes`, return the `nth` **super ugly number**.

The `nth` **super ugly number** is **guaranteed** to fit in a **32-bit** signed integer.

**Example 1:**
```
Input: n = 12, primes = [2,7,13,19]
Output: 32
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
```

**Constraints:**

- `1 <= n <= 10^6`
- `1 <= primes.length <= 100`
- `2 <= primes[i] <= 1000`
- `primes[i]` is **guaranteed** to be a prime number.
- All the values of `primes` are **unique** and sorted in **ascending order**.


---
## 解決思路

對於`primes`中的每一個質數來說，乘上先前某個ugly number皆有可能成為下一個ugly number，因此此題我們可以採用DP的方式準備一個陣列`uNumber`，過程中其將會紀錄1th~nth的ugly number，我們準備另一個陣列`primeIndex`，其中`primeIndex[i]`代表`primes[i]`所指向可相乘的最小ugly number於`uNumber`之索引值。

一但我們發現`uNumber[primeIndex[i]] * primes[i]`是當回合所有可能的ugly number中最小的，我們就將此值插入至`uNumber`中，並且將具有此值的`primeIndex[i]`加一(代表該質數指向之第x個ugly number已經與該質數相乘並成為最小的ugly number，因此後續該質數需要指向第x+1小的ugly number來與其他可能的候選ugly number做比較)。

最後只要執行`n-1`個回合(第一個ugly number必定為1)即可找出第nth的ugly number。