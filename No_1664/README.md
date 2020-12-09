題號: 1664. Ways to Make a Fair Array

難度: Medium

## 問題描述
You are given an integer array `nums`. You can choose **exactly one** index (**0-indexed**) and remove the element. Notice that the index of the elements may change after the removal.

For example, if `nums = [6,1,7,4,1]`:

- Choosing to remove index `1` results in `nums = [6,7,4,1]`.
- Choosing to remove index `2 `results in `nums = [6,1,4,1]`.
- Choosing to remove index `4` results in `nums = [6,1,7,4]`.

An array is **fair** if the sum of the odd-indexed values equals the sum of the even-indexed values.

Return the **number** of indices that you could choose such that after the removal, `nums` is **fair**.

---
## 解決思路
首先我們先計算分別nums的奇數項總和、偶數項總和(**oddSum**、**evenSum**)。之後針對每個**index i**判斷是否移除後為**fair**。

我們使用兩個變數來儲存左子陣列的奇數項總和、偶數項總和(**tmpOddSum**、**tmpEvenSum**)。

我們可以觀察到**index i**為下列兩總cases:

1. **index i** 是奇數項:
    移除掉該項的奇數項總和為: **evenSum - tmpEvenSum + tmpOddSum**
    移除掉該項的偶數項總和為: **oddSum - tmpOddSum - nums[i] + tmpEvenSum**
    
2. **index i** 是偶數項:
    移除掉該項的奇數項總和為: **evenSum - tmpEvenSum - nums[i] + tmpOddSum**
    移除掉該項的偶數項總和為: **oddSum - tmpOddSum + tmpEvenSum**



