題號: 1122. Relative Sort Array

難度: Easy

## 問題描述

Given two arrays `arr1` and `arr2`, the elements of `arr2` are distinct, and all elements in `arr2` are also in `arr1`.

Sort the elements of `arr1` such that the relative ordering of items in `arr1` are the same as in `arr2`.  Elements that don't appear in arr2 should be placed at the end of `arr1` in **ascending** order.

**Example 1:**

```
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
```

**Constraints:**

- `1 <= arr1.length, arr2.length <= 1000`
- `0 <= arr1[i], arr2[i] <= 1000`
- All the elements of `arr2` are **distinct**.
- Each `arr2[i]` is in `arr1`.


---
## 解決思路

此題我們可有用`map<int, int>`去儲存在`arr1`中的數字出現的頻率，之後再依據`arr2`中的順序將`map`中的數字做排序。而對於那些沒出現在`arr2`中的數字，因為`map`底層為紅黑數，所以在iterate時就會按照遞增取出，所以我們就可以將沒有出現在`arr2`中的數字取出做遞增排序並插入在最後。

