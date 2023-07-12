題號: 1224. Maximum Equal Frequency
難度: Hard

## 問題描述
Given an array `nums` of positive integers, return the longest possible length of an array prefix of `nums`, such that it is possible to remove **exactly one** element from this prefix so that every number that has appeared in it will have the same number of occurrences.

If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).

**Example 1:**
```
Input: nums = [2,2,1,1,5,3,3,5]
Output: 7
Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4] = 5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
```
**Constraints:**

- `2 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

## 解決思路
此題我們可以準備兩個hash map:

1. `numCount`: 紀錄當前每個數字對應的個數
2. `freqCount`: 紀錄當前每個頻率對應的總元素個數

在迭代`nums`的過程中，我們可以使用`numCount`來輕易地更新`freqCount`，並且每回合更新完`freqCount`後，再考慮兩個cases:

1. `freqCount`之key size為1:
    我們只需要判斷當前pattern是否為`1 1 1 1 1`或`1 2 3 4 5`的形式即可。
    
2. `freqCount`之key size為2:
    我們只需要判斷當前pattern是否為`1 1 1 2`或`1 1 1 3 3 4 4`的形式即可。


