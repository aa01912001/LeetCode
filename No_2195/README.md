題號: 2195. Append K Integers With Minimal Sum
難度: Medium

## 問題描述
You are given an integer array `nums` and an integer `k`. Append `k` **unique positive** integers that do **not** appear in `nums` to `nums` such that the resulting total sum is **minimum**.

Return the sum of the `k` integers appended to `nums`.

**Example 1:**
```
Input: nums = [1,4,25,10,25], k = 2
Output: 5
Explanation: The two unique positive integers that do not appear in nums which we append are 2 and 3.
The resulting sum of nums is 1 + 4 + 25 + 10 + 25 + 2 + 3 = 70, which is the minimum.
The sum of the two integers appended is 2 + 3 = 5, so we return 5.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`
- `1 <= k <= 10^8`


## 解決思路
此題只需要對`nums`做遞增排序後，再從最前面的每個元素區段取出相應數量的數字進行加總即可。

例如: `nums = [1,4,25,10,25], k = 6`

`nums`做sorting後為: `[1,4,10,25,25]`

因此，1 ~ 4之間可以挑出2、3、4，同樣地4 ~ 10之間再依Greedy的方式挑出5、6、7。