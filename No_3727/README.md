題號: 3727. Maximum Alternating Sum of Squares

難度: `Medium`

## 問題描述


You are given an integer array `nums`. You may **rearrange the elements** in any order.

The **alternating score** of an array `arr` is defined as:

* `score = arr[0]^2 - arr[1]^2 + arr[2]^2 - arr[3]^2 + ...`

Return an integer denoting the **maximum possible alternating score** of `nums` after rearranging its elements.


**Example 1:**
```
Input: nums = [1,2,3]

Output: 12

Explanation:

A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.

The alternating score is calculated as:

score = 22 - 12 + 32 = 4 - 1 + 9 = 12
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `-4 * 104 <= nums[i] <= 4 * 10^4`

**解決思路:**

此題我們會希望平方後越大的數字被放在加總的項目，越小的則被放到減去的項目，因此我們只需要對`nums`的每個元素進行平方並排序後，取後半部分陣列的所有元素做加總，減去前半部分所有元素即為解答。