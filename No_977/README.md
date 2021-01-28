題號: 977. Squares of a Sorted Array

難度: Easy

## 問題描述
Given an integer array `nums` sorted in **non-decreasing** order, return an array of **the squares of each number** sorted in non-decreasing order.

Example 1:
```
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

Constraints:


- `1 <= nums.length <= 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `nums` is sorted in **non-decreasing** order.


---
## 解決思路
因為`nums`原本就已經排序好了，所以我們只需要找到第一個大於等於0值的index(**有了此index後我們相當於有了兩個排序好的vector，其中一個值皆小於0，另一個反之**)，之後比較兩個vector的首項(對於每個值全為小於0的vector的首項要乘上-1轉正)，比較後我們就能得知哪一項在平方後會有較小的值，隨後將較小的那項放入解答vector後繼續迭代即可。