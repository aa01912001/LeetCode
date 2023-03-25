題號: 2563. Count the Number of Fair Pairs
難度: Medium

## 問題描述
Given a **0-indexed** integer array `nums` of size `n` and two integers `lower` and `upper`, return the number of fair pairs.

A pair `(i, j)` is **fair** if:

- `0 <= i < j < n`, and
- `lower <= nums[i] + nums[j] <= upper`

**Example 1:**
```
Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums.length == n`
- `-10^9 <= nums[i] <= 10^9`
- `-10^9 <= lower <= upper <= 10^9`


## 解決思路
此題我們可以先對`nums`做sort後，再利用two pointers的方式找出所有大於`upper`及小於`lower`的pair數量，最後再用所有的pair數量減去該數即可得到介於`lower`及`upper`的pair數量。

對於找出大於`upper`的pair數量，我們可以令`left = 0, right = n - 1` ，並有以下判斷:

若`nums[left] + nums[right] > upper`則我們可以知道共有`right-left`組pair可加入(因為`nums`已排序過，因此`(nums[left+1], nums[right])...(nums[right-1], nums[right])`)同樣會大於`upper`，隨後我們將`right`值減1。若`nums[left] + nums[right] <= upper`，則將`left`值加1。直到`left == right`則停止尋找。

對於找出小於`lower`的pair數量，道理與上述相同。