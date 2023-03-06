題號: 373. Find K Pairs with Smallest Sums
難度: Medium

## 問題描述
You are given two integer arrays `nums1` and `nums2` sorted in **ascending order** and an integer `k`.

Define a pair `(u, v)` which consists of one element from the first array and one element from the second array.

Return the `k` pairs `(u1, v1), (u2, v2), ..., (uk, vk)` with the smallest sums.

**Example 1:**
```
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 10^5`
- `-10^9 <= nums1[i], nums2[i] <= 10^9`
- `nums1` and `nums2` both are sorted in **ascending order**.
- `1 <= k <= 10^4`

---
## 解決思路
此題可以利用max heap來記錄前k小的pair，而我們只需要遍歷`min(n1, k)*min(n2, k)`個pair即可。

Note: 當發現當前pair已經大於heap top時，需要用break跳出內層迴圈以減少時間(因為給定的數組為已經排序過的，因此繼續迭代內層迴圈必定找不到小於heap top的pair)。