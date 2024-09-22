題號: 2763. Sum of Imbalance Numbers of All Subarrays
難度: Hard

## 問題描述
The **imbalance number** of a **0-indexed** integer array `arr` of length `n` is defined as the number of indices in `sarr = sorted(arr)` such that:

- `0 <= i < n - 1`, and
- `sarr[i+1] - sarr[i] > 1`

Here, `sorted(arr)` is the function that returns the sorted version of `arr`.

Given a `0-indexed` integer array `nums`, return the `sum of imbalance numbers` of all its `subarrays`.

A `subarray` is a contiguous `non-empty` sequence of elements within an array.

**Example 1:**
```
Input: nums = [2,3,1,4]
Output: 3
Explanation: There are 3 subarrays with non-zero imbalance numbers:
- Subarray [3, 1] with an imbalance number of 1.
- Subarray [3, 1, 4] with an imbalance number of 1.
- Subarray [1, 4] with an imbalance number of 1.
The imbalance number of all other subarrays is 0. Hence, the sum of imbalance numbers of all the subarrays of nums is 3. 
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= nums.length`

**解決思路:**
此題我們需要針對每個index i往後計算每個包含以`nums[i]`為開頭的子陣列`nums[i] ~ nums[j]`之**imbalance number**。

其中我們需要準備:

- `count = -1`，其代表當前子陣列中所有不連續的元素個數
- `hset`，用來儲存遍歷過的元素

當我們遍歷到`nums[j]`時，可分以下情況:

1. `nums[j]`已經存在於`hset`中，代表此數排序後不可能成**imbalance number**，因為排序完前面必定是自己。若`nums[j]`不存在，則我們可接著判斷2, 3。

2. `nums[i] - 1` 與 `nums[i] + 1`皆不存在於`hset`中，代表此數在`nums[i]~nums[j]`這個子陣列排序後必定是**imbalance number**，因此我們將`count += 1`

3. `nums[i] - 1` 與 `nums[i] + 1`皆存在於`hset`中，代表此數會使前面某個**imbalance number**失效，例如我們有一個子陣列`[1,3,2]`，在遍歷完1, 3後，我們會判斷3為**imbalance number**，但加入2之後則3就不會是**imbalance number**。因此針對這種情況我們需要將`count -= 1`。

最後當下的`count`數值即為子陣列`nums[i] ~ nums[j]`的**imbalance number**總數，因此我們需要將解答值加上`count`。
