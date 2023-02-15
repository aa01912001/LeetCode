題號: 1300. Sum of Mutated Array Closest to Target
難度: Medium

## 問題描述
Given an integer array `arr` and a `target` value target, return the integer `value` such that when we change all the integers larger than `value` in the given array to be equal to `value`, the sum of the array gets as close as possible (in absolute difference) to `target`.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from `arr`.

**Example 1:**
```
Input: arr = [4,9,3], target = 10
Output: 3
Explanation: When using 3 arr converts to [3, 3, 3] which sums 9 and that's the optimal answer.
```

**Constraints:**

- `1 <= arr.length <= 10^4`
- `1 <= arr[i], target <= 10^5`

---
## 解決思路
此題我們需要利用binary search的方式來猜測最終的`value`值。

對於每一次的`mid`，我們首先計算整個`arr`轉換後的和(`sum`)，並有兩個cases:

1. `sum >= target`: 我們將`high = mid`，繼續尋找更小的可能值
2. `sum < target`: 表示當前`value`，我們將`low = mid + 1`往上尋找可以更逼近`target`的可能性。

最終當`low == high`時，我們比較`low`是否較更逼近`low-1`，以此判斷最終的回傳`value`。