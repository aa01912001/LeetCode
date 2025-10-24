題號: 3346. Maximum Frequency of an Element After Performing Operations I

難度: Medium

## 問題描述
## Problem Description

You are given an integer array `nums` and two integers `k` and `numOperations`.

You must perform an **operation** `numOperations` times on `nums`, where in each operation you:

- Select an index `i` that was **not selected** in any previous operations.  
- Add an integer in the range `[-k, k]` to `nums[i]`.

Return the **maximum** possible **frequency** of any element in `nums` after performing the **operations**.


**Example 1:**
```
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". 
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`
- `0 <= k <= 10^5`
- `0 <= numOperations <= nums.length`

**解決思路:**

1. 用line sweep擬區間重疊次數，找出有多少個元素的「可變動範圍」重疊在同一個值附近。
每個數字 num 可以被調整成任意在 `[num - k, num + k]` 範圍內的值。

2. 建立events並排序:
- 區間 `[num−k,num−1]`：由 (num-k, 1) (開始) 和 (num-1, -1) (結束) 表示。
- 區間 `[num,num]` (單點)：由 (num, 1) (開始) 和 (num, -1) (結束) 表示。
- 區間 `[num+1,num+k]`：由 (num+1, 1) (開始) 和 (num+k, -1) (結束) 表示。

3. 排序`events`
- 事件按照 value (數值) 由小到大處理。
- 如果 value 相同，delta = 1 (開始事件) 會優先於 delta = -1 (結束事件) 被處理。

4. 掃描與計算
- `active_count += delta`: `active_count`表示總共有多少個原始 `num` 的可達區間 `[num−k,num+k]` 包含了 `value`。
- `base_count = freq.get(value, 0)`: `freq` 是 `Counter(nums)`，所以 `base_count` 得到的是原始 `nums` 陣列中 `value` 的數量。
- `possible_freq = base_count + min(active_count - base_count, num_operations`: 
    - `active_count - base_count`: 表示原本可變成`value`但不是`value`的元素數量
    - `min(...)`: 因為我們最多只能用`num_operations`次操作，也最多只能把`active_count - base_count`變為`value`，因此取最小值。

5. 更新解答值: `max_freq = max(max_freq, possible_freq)`

Note: `[num,num]`需要另外加進來的原因是為了確保我們在 `value=num` 這個點上，能用 `num` 自己 的 `base_count` (原始頻率) 來計算一次最大頻率。