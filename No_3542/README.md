題號: 3542. Minimum Operations to Convert All Elements to Zero

難度: Medium

## 問題描述

You are given an array `nums` of size `n`, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become `0`.

In one operation, you can select a subarray `[i, j]` (where `0 <= i <= j < n`) and set all occurrences of the **minimum non-negative integer** in that subarray to `0`.

Return the **minimum** number of operations required to make all elements in the array `0`.


**Example 1:**
```
Input: nums = [0,2]
Output: 1
Explanation:

    Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
    Thus, the minimum number of operations required is 1.
```
**Constraints:**

- `1 <= n == nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`



**解決思路:**

此題可以使用monotinic stack的方式來解決。
我們使stack維持嚴格遞增:

- 如果當前數為0，代表我們不用再考量後面的數字是否能與前面的數字合併為一次運算了，直接將解答值加上當前stack元素個數並清空即可。

- 若top元素>=當前元素(`num`)，表示top一定無法跟後續的元素合併運算，我們需要不斷pop元素直到取出stack中最先出現的`num`的，過程中如果pop出的元素是>`num`的，則需要將解答值加上1。