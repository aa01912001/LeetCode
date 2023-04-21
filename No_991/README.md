題號: 991. Broken Calculator
難度: Medium

## 問題描述
There is a broken calculator that has the integer `startValue` on its display initially. In one operation, you can:

- multiply the number on display by `2`, or
- subtract `1` from the number on display.

Given two integers `startValue` and `target`, return the minimum number of operations needed to display `target` on the calculator.

**Example 1:**
```
Input: startValue = 2, target = 3
Output: 2
Explanation: Use double operation and then decrement operation {2 -> 4 -> 3}.
```

**Constraints:**

- `1 <= startValue, target <= 10^9`

## 解決思路
此題我們可以知道，當`startValue > target`，我們需要進行`startValue - target`次的減法運算，反之`startValue < target`時，我們需要逆向模擬將`target`進行逆運算嘗試變回`startValue`或者最接近小於它的正整數。

當`target`為偶數時，我們將其除以2，反之將其加1。