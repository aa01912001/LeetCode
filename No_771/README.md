題號: 771. Jewels and Stones

難度: Easy

## 問題描述
You're given strings `jewels` representing the types of stones that are jewels, and `stones` representing the stones you have. Each character in `stones` is a type of stone you have. You want to know how many of the stones you have are also jewels.

Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.

Example 1:
```
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3
```
---
## 解決思路
我們利用unordered_map先將stones中每個字元的數量儲存起來後，再將jewels中每個字元所對應的總數相加後即為答案。

