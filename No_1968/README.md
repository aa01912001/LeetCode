題號: 1968. Array With Elements Not Equal to Average of Neighbors
難度: Medium

## 問題描述
You are given a **0-indexed** array `nums` of **distinct** integers. You want to rearrange the elements in the array such that every element in the rearranged array is not equal to the **average** of its neighbors.

More formally, the rearranged array should have the property such that for every `i` in the range `1 <= i < nums.length - 1`, `(nums[i-1] + nums[i+1]) / 2` is **not** equal to `nums[i]`.

Return any rearrangement of `nums` that meets the requirements.

**Example 1:**
```
Input: nums = [1,2,3,4,5]
Output: [1,2,4,5,3]
Explanation:
When i=1, nums[i] = 2, and the average of its neighbors is (1+4) / 2 = 2.5.
When i=2, nums[i] = 4, and the average of its neighbors is (2+5) / 2 = 3.5.
When i=3, nums[i] = 5, and the average of its neighbors is (4+3) / 2 = 3.5. 
```

**Constraints:**

- `3 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`

---
## 解決思路
我們可以知道三數中最小的數一定必定不等於其他兩數之和平均，同理三數中最大的數也一定不等於其他兩數之和平均。

因此，此題我們只需對`nums`做遞增排序後，再將此陣列從中間切成兩半並依序從頭取出交錯排列即可。