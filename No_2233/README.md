題號: 2233. Maximum Product After K Increments
難度: Medium

## 問題描述
You are given an array of non-negative integers `nums` and an integer `k`. In one operation, you may choose **any** element from `nums` and **increment** it by `1`.

Return the **maximum product** of `nums` after **at most** `k` operations. Since the answer may be very large, return it **modulo** `10^9 + 7`. Note that you should maximize the product before taking the modulo. 

**Example 1:**
```
Input: nums = [0,4], k = 5
Output: 20
Explanation: Increment the first number 5 times.
Now nums = [5, 4], with a product of 5 * 4 = 20.
It can be shown that 20 is maximum product possible, so we return 20.
Note that there may be other ways to increment nums to have the maximum product.
```

**Constraints:**

- `1 <= nums.length, k <= 10^5`
- `0 <= nums[i] <= 10^6`

## 解決思路
此題我們每次只要挑選最小的數進行加1即可，因此只需要用min heap來維護數組即可，最後再將heap中的所有數相乘即為答案。