題號: 1671. Minimum Number of Removals to Make Mountain Array
難度: Hard

## 問題描述
You may recall that an array `arr` is a **mountain array** if and only if:

- `arr.length >= 3`
- There exists some index `i` (**0-indexed**) with `0 < i < arr.length - 1` such that:
	- `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
	- `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given an integer array `nums` , return the **minimum** number of elements to remove to make `nums` a **mountain array**.


**Example 1:**
```
Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
```
**Constraints:**

- `3 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^9`
- It is guaranteed that you can make a mountain array out of `nums`.

## 解決思路

此題我們採用DP的方式準備兩個陣列`vector<int> dpLeft(n, INT_MAX), dpRight(n, INT_MAX)`。其中`dpLeft[i]`表示由index 0 ~ i且包含`nums[i]`形成的strictly increasing sequence所需刪除的最少元素個數。

對於`dpLeft[i]`來說，我們必須將`nums[i]`與`nums[i-1]~nums[0]`進行比較，並分為兩個cases。

1. `nums[j] < nums[i]`: 則`dpLeft[i] = min(dpLeft[i], dpLeft[j]+i-j-1)`
2. `nums[j] >= nums[i]`: 代表無法包含`nums[j]`在內，必定得刪掉它

而`dpRight`為相反方向同理。

最後我們只需要找出擁有最小的`dpLeft[i]+dpRight[i]`即可，但`nums[i]`不可為sequence最左或最右之元素。