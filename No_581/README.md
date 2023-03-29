題號: 581. Shortest Unsorted Continuous Subarray
難度: Medium

## 問題描述
Given an integer array `nums`, you need to find one **continuous subarray** that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

**Example 1:**
```
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `-10^5 <= nums[i] <= 10^5`

**Follow up**: Can you solve it in `O(n)` time complexity?

## 解決思路
此題我們只需要找出目標子陣列的頭尾index即可。
程式中:
`mx`用來記錄從`nums`前端開始遍歷的最大值。

若當前`nums[i]`小於`mx`代表此處必須要做交換，因此讓`rear = i`。
最終我們可得到目標子陣列的尾端，而透過相同方式紀錄最小值`mn`也可得到目標子陣列前端`front`。

因此最後我們只需要返回`rear - front + 1`即可。