題號: 532. K-diff Pairs in an Array
難度: Medium

## 問題描述
Given an array of integers `nums` and an integer `k`, return the number of **unique** k-diff pairs in the array.

A **k-diff** pair is an integer pair `(nums[i], nums[j])`, where the following are true:

- `0 <= i, j < nums.length`
- `i != j`
- `nums[i] - nums[j] == k`

**Notice** that `|val|` denotes the absolute value of `val`.

**Example 1:**
```
Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^7 <= nums[i] <= 10^7`
- `0 <= k <= 10^7`

## 解決思路
此題我們只需要利用hash map紀錄每個數的個數後，再從map中分別取出元素做以下判斷:

1. 若`k == 0 && p.second > 1`，則解答值加1。
2. 若`k > 0 && hmap.count(p.first+k)`，則解答值加1。

1代表`k`為0的情況，我們只需要找出所有出現次數超過1的元素個數即可。
2代表`k`大於0的情況，我們要另外找出當前元素值加上`k`是否有存在於`nums`中。