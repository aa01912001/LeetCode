題號: 1567. Maximum Length of Subarray With Positive Product
難度: Medium

## 問題描述
Given an array of integers `nums`, find the maximum length of a subarray where the product of all its elements is positive.

A subarray of an array is a consecutive sequence of zero or more values taken out of that array.

Return the maximum length of a subarray with positive product.

**Example 1:**
```
Input: nums = [1,-2,-3,4]
Output: 4
Explanation: The array nums already has a positive product of 24.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## 解決思路
此題我們只需要使用DP的方式來思考即可，我們準備兩個變數:

1. `dpPos`: 包含`nums[i-1]`之前的最大正整數乘積長度
2. `dpNeg`: 包含`nums[i-1]`之前的最大負整數乘積長度

而每回合對於`nums[i]`來說，可分為3個cases:

1. `nums[i] == 0`: 代表包含它之前的所有陣列元素都不可能包含在解答中了，否則乘積必為0，因此我們將`dpPos`與`dpNeg`更新為0
2. `nums[i] > 0`: 我們因此更新`dpPos`為`dpPos + 1`，`dpNeg`為`dpNeg + 1`(但若`dpNeg`之前為0的話則維持為0)
3. `nums[i] < 0`: 我們因此更新`dpPos`為`dpNeg + 1`(但若`dpNeg`之前為0的話則維持為0)，`dpNeg`為`dpPos + 1`

最後每回合我們將解答值與`dpPos`進行比較更新即可


