題號: 3834. Merge Adjacent Equal Elements

難度: `Medium`

## 問題描述


You are given an integer array `nums`.

You must **repeatedly** apply the following merge operation until no more changes can be made:

* If any **two adjacent elements are equal**, choose the **leftmost** such adjacent pair in the current array and replace them with a single element equal to their **sum**.

After each merge operation, the array size **decreases** by 1. Repeat the process on the updated array until no more changes can be made.

Return the final array after all possible merge operations.


**Example 1:**
```
Input: nums = [3,1,1,2]

Output: [3,4]

Explanation:

    The middle two elements are equal and merged into 1 + 1 = 2, resulting in [3, 2, 2].
    The last two elements are equal and merged into 2 + 2 = 4, resulting in [3, 4].
    No adjacent equal elements remain. Thus, the answer is [3, 4].
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

**解決思路:**

此題我們可透過stack的方式依序放入nums的數字，每次判斷是否當前num等於stack top的數字即可，若相同則不斷取出top元素合併。