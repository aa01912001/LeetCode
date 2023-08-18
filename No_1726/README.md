題號: 1726. Tuple with Same Product
難度: Medium

## 問題描述
Given an array `nums` of **distinct** positive integers, return the number of tuples `(a, b, c, d)` such that `a * b = c * d` where `a`, `b`, `c`, and `d` are elements of `nums`, and `a != b != c != d`.

**Example 1:**
```
Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
```
**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^4`
- All elements in `nums` are **distinct**.

## 解決思路
假設我們找到一組合法的tuple: `(a, b, c, d)`，那麼我們可以知道可以它可以有8種合法的排列方式:

a、b交換: 2種
c、d交換: 2種
(a, b)與(c, d)交換: 2種

總共有2x2x2 = 8種

因此我們可以用兩層for迴圈來計算所有`nums[i]`、`nums[j]` pair的乘積，並用hash map紀錄曾經算過的乘積數量。

假設當前`nums[i]`、`nums[j]`的乘積於map中的數量為`x`，代表當前pair可以跟前面`x`個不同的pair形成合法tuple，因此我們就可以將`x * 8`加至解答中，並更新map。

