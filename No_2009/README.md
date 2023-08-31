題號: 2009. Minimum Number of Operations to Make Array Continuous
難度: Hard

## 問題描述
You are given an integer array `nums`. In one operation, you can replace **any** element in `nums` with **any** integer.

`nums` is considered continuous if both of the following conditions are fulfilled:

- All elements in `nums` are **unique**.
- The difference between the **maximum** element and the **minimum** element in `nums` equals `nums.length - 1`.

For example, `nums = [4, 2, 5, 3]` is **continuous**, but `nums = [1, 2, 3, 5, 6]` is **not continuous**.

Return the **minimum** number of operations to make `nums` **continuous**.

**Example 1:**
```
Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`



## 解決思路
此題我們假設`nums`長度為`n`。首先，我們先對`nums`做遞增排序，並且從頭開始遍歷並取出所有不同的數存於`dNums`中。之後我們可以使用sliding window的方式來找尋解答。

對於`dNums[left]`來說，代表著形成最終陣列的最小數字，而對於每個`dNums[right]`我們可以進行如下判斷:

`dNums[right]` 是否小於等於 `dNums[left] + n - 1`?

- 若是－代表我們可以使`right - left + 1`個元素不需變動，而對其他`n - (right - left + 1)`個元素進行變更，使陣列成為連續。因此若此情況成立，我們更新解答值，並右移右窗口尋求更少的運算數。

- 若否－代表`dNums[right]`與`dNums[left]`的距離已經超過`n`個元素的距離，因此這種情況下不可能同時保留`dNums[right]`與`dNums[left]`使陣列成為連續，因此我們應該右移左窗口，再次進行上述比較。


