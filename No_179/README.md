題號: 179. Largest Number

難度: Medium

## 問題描述

Given a list of non-negative integers `nums`, arrange them such that they form the largest number.

**Note:** The result may be very large, so you need to return a string instead of an integer.

**Example 1:**


```
Input: nums = [3,30,34,5,9]
Output: "9534330"
```


**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 10^9`


---
## 解決思路

此題我們可將`nums`中的數都轉換成字串後，在自訂義一個comparator去做sort。在comparator中我們輸入的是兩個字串`a`、`b`，我們只需要判斷串聯後字串`a+b`與`b+a`的大小即可。若`a+b > b+a`則代表字串`a`應該被放在字串`b`前面，反之亦然。最後將排序完的vector中的字串依序串聯起來並返回即可。



