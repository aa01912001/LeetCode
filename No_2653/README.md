題號: 2653. Sliding Subarray Beauty
難度: Medium

## 問題描述
Given an integer array `nums` containing `n` integers, find the **beauty** of each subarray of size `k`.

The **beauty** of a subarray is the `xth` **smallest integer** in the subarray if it is **negative**, or `0` if there are fewer than `x` negative integers.

Return an integer array containing `n - k + 1` integers, which denote the **beauty** of the subarrays **in order** from the first index in the array.

- A subarray is a contiguous **non-empty** sequence of elements within an array.

**Example 1:**
```
Input: nums = [1,-1,-3,-2,3], k = 3, x = 2
Output: [-1,-2,-2]
Explanation: There are 3 subarrays with size k = 3. 
The first subarray is [1, -1, -3] and the 2nd smallest negative integer is -1. 
The second subarray is [-1, -3, -2] and the 2nd smallest negative integer is -2. 
The third subarray is [-3, -2, 3] and the 2nd smallest negative integer is -2.
```
**Constraints:**

- `n == nums.length `
- `1 <= n <= 10^5`
- `1 <= k <= n`
- `1 <= x <= k `
- `-50 <= nums[i] <= 50 `

## 解決思路
此題我們只需要準備一個陣列紀錄每個小於0的數字出現的頻率，再配合sliding window的方式進行頻率的增減後，我們就可以對於每個長度為`k`的子陣列找出其第`x`小的數字。

程式中我們對於`nums`進行跌代，每回合我們對於最前方的元素進行頻率的新增(若其為小於0的數字才需要)，對先前子陣列的起始位置之元素進行頻率的減少(若其為小於0的數字才需要)。

之後對於當前子陣列我們需要去尋找其第`x`小的數字，因此我們同樣跌代紀錄頻率的陣列(從數字小到大)來統計頻率數，一旦累加的數字大於等於`x`，則當前子陣列解答則為當前索引數;若跌代完該陣列後，發現累加的數字小於`x`，代表當前子陣列中的負數小於`x`個，因此其解為0。

