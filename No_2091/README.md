題號: 2091. Removing Minimum and Maximum From Array
難度: Medium

## 問題描述

You are given a **0-indexed** array of **distinct** integers `nums`.

There is an element in `nums` that has the **lowest** value and an element that has the **highest** value. We call them the **minimum** and **maximum** respectively. Your goal is to remove **both** these elements from the array.

A **deletion** is defined as either removing an element from the **front** of the array or removing an element from the **back** of the array.

Return the **minimum** number of deletions it would take to remove **both** the minimum and maximum element from the array.

```
Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`
- The integers in `nums` are **distinct**.

---
## 解決思路

此題我們首先需要找出最大值與最小值的索引位置，假設其中較小的索引為`lo1`，較大的索引為`lo2`，我們透過觀察可以發現解答只會出現在下列三種情況之一：

1. 從front刪到`lo2`
2. 從back刪到`lo1`
3. 從front刪到`lo1`，且從back刪到`lo2`

以上三種情況皆能將`lo1`與`lo2`刪除，因此我們只需要找出以上三種刪除方式所需的步數，並返回最小的數即可。

