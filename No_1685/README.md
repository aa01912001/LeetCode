題號: 1685. Sum of Absolute Differences in a Sorted Array

難度: Medium

## 問題描述
You are given an integer array `nums` sorted in **non-decreasing** order.

Build and return an integer array `result` with the same length as nums such that `result[i]` is equal to the **summation of absolute differences** between `nums[i]` and all the other elements in the array.

In other words, `result[i]` is equal to `sum(|nums[i]-nums[j]|)` where `0 <= j < nums.length` and `j != i` (**0-indexed**).


Example 1:

```
Input: nums = [2,3,5]
Output: [4,3,5]
Explanation: Assuming the arrays are 0-indexed, then
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4,
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3,
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5.
```

Constraints:

- `2 <= nums.length <= 10^5`
- `1 <= nums[i] <= nums[i + 1] <= 10^4`

---
## 解決思路

此題因為給予的陣列已經是**non-decreasing**，所以我們能夠利用前一個計算出來的絕對差和來計算當前的解。

假設nums = {....,11,15,.....},其中11與15之index分別為j,i

那麼因為15與11的差為4，所以在計算15的解的時候相當於就是:
`result[j] + (nums[i]-nums[j])*i - (nums[i]-nums[j])*(nums.size()-i)`

其中加上`(nums[i]-nums[j])*i`**是因為15比11多4，所以前面i項所計算出來的絕對差值每項都會比11所計算出來的多4**。

而減去`(nums[i]-nums[j])*(nums.size()-i)`**是因為15比11多4，所以後面nums.size()-i項所計算出來的絕對差值每項都會比11所計算出來的少4**。
