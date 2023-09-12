題號: 128. Longest Consecutive Sequence
難度: Medium

## 問題描述
Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in `O(n)` time.

**Example 1:**
```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Constraints:**

- `0 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## 解決思路
此題我們可以輕易地看出若在`nums`中連續的sequence，我們可以將之視為同一組。因此我們需要尋找最大的組別個數。

首先我們準備一個hash set將所有`nums`的元素存入，之後開始遍歷`nums`。

對於當前的每一個`nums[i]`若存在於set中，我們就開始不斷尋找其向下及向上的數是否也存在於set中，最後我們只需要將找到的範圍與解答進行更新即可。
