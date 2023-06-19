題號: 239. Sliding Window Maximum
難度: Hard

## 問題描述
You are given an array of integers `nums`, there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

**Example 1:**
```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

## 解決思路
此題我們可以利用`deque<int> dq`來進行monotonic數值的儲存，其中queue的前端保存了當前最大數的index。

當我們發現`dq.front() == i-k`，代表window已經向右移了一位，因此前方元素已經過期，我們將之取出。

隨後我們不斷判斷當前元素`nums[i]`若大於`nums[dq.back()]`的話，就將queue最後的元素取出，以保證queue中只存放有用的元素。