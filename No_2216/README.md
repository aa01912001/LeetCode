題號: 2216. Minimum Deletions to Make Array Beautiful
難度: Medium

## 問題描述
You are given a **0-indexed** integer array `nums`. The array `nums` is **beautiful** if:

- `nums.length` is even.
- `nums[i] != nums[i + 1]` for all `i % 2 == 0`.

Note that an empty array is considered beautiful.

You can delete any number of elements from `nums`. When you delete an element, all the elements to the right of the deleted element will be **shifted one unit to the left** to fill the gap created and all the elements to the left of the deleted element will remain **unchanged**.

Return the **minimum** number of elements to delete from `nums` to make it beautiful.

**Example 1:**
```
Input: nums = [1,1,2,3,5]
Output: 1
Explanation: You can delete either nums[0] or nums[1] to make nums = [1,2,3,5] which is beautiful. It can be proven you need at least 1 deletion to make nums beautiful.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^5`


---
## 解決思路
我們可以使用stack來儲存已經符合規則2的數組。首先我們必須從頭遍歷`nums`，對於`nums[i]`來說，我們要如何考慮是否需要刪除?若當前`stk.size()`為偶數時，代表目前的beautiful array的索引位置為奇數，因此可以無條件地將`nums[i]`加入beautiful array中;反之，我們就必須考量`nums[i]`是否等於`stk.top()`，若相等，則必須刪除`nums[i]`，否則違反規則2，因此我們將解答值加1，若不相等，則直接將`nums[i]`加入beautiful array中即可。

最後我們要記得判斷最後的`stk.size()`是否為偶數，若否，則應該刪除beautiful array最右邊的數(也就是`stk.top()`)。