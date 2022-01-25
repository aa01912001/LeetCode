題號: 201. Bitwise AND of Numbers Range
難度: Medium

## 問題描述

Given two integers `left` and `right` that represent the range `[left, right]`, return the bitwise AND of all numbers in this range, inclusive.

**Example 1:**
```
Input: left = 5, right = 7
Output: 4
```


**Constraints:**

- `0 <= left <= right <= 2^31 - 1`

---
## 解決思路

此題我們可以針對`left`中的位元來判斷，針對第i個位元的位置可分為兩種情況：

1. 該位置為0：
    代表即使跟後續數值做AND運算，該位置也終究是0。
2. 該位置為1：
    我們需要判斷`left`與`right`間是否有該位置為0的數出現，假設`left`之二進位中某個位置為1，並表示為`xxx1xxx`，我們需要判斷`xx10000`是否介於`left`與`right`之間，若是的話代表必定會有至少1數，其第i個位置為0，所以解答中的此位置也會為0。
    
藉由檢視`left`中的每個bit，我們可以得知答案中每個bit是為0或1，