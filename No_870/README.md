題號: 870. Advantage Shuffle

難度: Medium

## 問題描述

Given two arrays `nums1` and `nums2` of equal size, the advantage of `nums1` with respect to `nums2` is the number of indices `i` for which `nums1[i] > nums2[i]`.

Return **any** permutation of `nums1` that maximizes its advantage with respect to `nums2`.


**Example 1:**

```
Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
Output: [2,11,7,15]
```

**Note:**

1. `1 <= nums1.length = nums2.length <= 10000`
2. `0 <= nums1[i] <= 10^9`
3. `0 <= nums2[i] <= 10^9`




---
## 解決思路

此題需要先將`num1`由小至大做排序，之後針對每一個`num2`裡面的值我們要從num1中由最小的數開始找出一個大於num2當前索引值且差值最小的數當作對應解，之後將此被挑選的數從`num1`中刪除並加入返回陣列即可;若`num1`中的所有數皆無法大於，則犧牲最小的數作為對應解。