題號: 740. Delete and Earn

難度: Medium

## 問題描述

You are given an integer array `nums`. You want to maximize the number of points you get by performing the following operation any number of times:

- Pick any `nums[i]` and delete it to earn `nums[i]` points. Afterwards, you must delete **every** element equal to `nums[i] - 1` and **every** element equal to `nums[i] + 1`.

Return the **maximum number of points** you can earn by applying the above operation some number of times.

**Example 1:**

```
Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
```

**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `1 <= nums[i] <= 10^4`

---
## 解決思路

此題我們可以使用DP的策略，想法如下:

首先我們使用`map<int, int> bMap`的結構來儲存`nums`每個數的總points。之後依每個數由小到大挑選出來作判斷。

我們另外維護兩個變數:

`int maxWithoutCur`: 用來保存從最小的數到當前數(不包含挑選了當前數)的最大points。

`int maxWithCur`: 用來保存從最小的數到當前數(包含挑選了當前數)的最大points。

在每挑出一個數後，我們可以分為兩種情況:

- case1: 當前數不為前挑選數的下一個整數
    另`tmp`為`maxWithoutCur`
    更新`maxWithoutCur`為`max(maxWithoutCur, maxWithCur)`
    更新`maxWithCur`為`max(tmp, maxWithCur) + 當前數的總points`
    
- case2: 當前數為前挑選數的下一個整數
    另`tmp`為`maxWithoutCur`
    更新`maxWithoutCur`為`max(maxWithoutCur, maxWithCur)`
    更新`maxWithCur`為`tmp + 當前數的總points`
    
如此反覆到最後，我們即可得到包含最後數的總points的解與不包含的解，我們只需要返回兩者中最大的即可。










